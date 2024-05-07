#include "Ethernet_MCU.h"
#include "Com/Hardware/Net/Net.h"

#define LAN8720_PHY_ADDRESS       0x01 /* Relative to STM324xG-EVAL Board */


#if defined   (__CC_ARM) /*!< ARM Compiler */
//////  __align(4)
////   ETH_DMADESCTypeDef  DMARxDscrTab[ETH_RXBUFNB];/* Ethernet Rx MA Descriptor */
//////  __align(4)
////   ETH_DMADESCTypeDef  DMATxDscrTab[ETH_TXBUFNB];/* Ethernet Tx DMA Descriptor */
//////  __align(4)
////   uint8_t Rx_Buff[ETH_RXBUFNB][ETH_RX_BUF_SIZE]; /* Ethernet Receive Buffer */
//////  __align(4)
////   uint8_t Tx_Buff[ETH_TXBUFNB][ETH_TX_BUF_SIZE]; /* Ethernet Transmit Buffer */

ETH_DMADESCTypeDef  DMARxDscrTab[ETH_RXBUFNB] __attribute__((at(0x20000000)));/* Ethernet Rx DMA Descriptors */

ETH_DMADESCTypeDef  DMATxDscrTab[ETH_TXBUFNB] __attribute__((at(0x20002000)));/* Ethernet Tx DMA Descriptors */

uint8_t Rx_Buff[ETH_RXBUFNB][ETH_RX_BUF_SIZE] __attribute__((at(0x20000100))); /* Ethernet Receive Buffers */

uint8_t Tx_Buff[ETH_TXBUFNB][ETH_TX_BUF_SIZE] __attribute__((at(0x20002100))); /* Ethernet Transmit Buffers */

#elif defined ( __ICCARM__ ) /*!< IAR Compiler */
  #pragma data_alignment=4
   ETH_DMADESCTypeDef  DMARxDscrTab[ETH_RXBUFNB];/* Ethernet Rx MA Descriptor */
  #pragma data_alignment=4
   ETH_DMADESCTypeDef  DMATxDscrTab[ETH_TXBUFNB];/* Ethernet Tx DMA Descriptor */
  #pragma data_alignment=4
   uint8_t Rx_Buff[ETH_RXBUFNB][ETH_RX_BUF_SIZE]; /* Ethernet Receive Buffer */
  #pragma data_alignment=4
   uint8_t Tx_Buff[ETH_TXBUFNB][ETH_TX_BUF_SIZE]; /* Ethernet Transmit Buffer */

#elif defined (__GNUC__) /*!< GNU Compiler */
  ETH_DMADESCTypeDef  DMARxDscrTab[ETH_RXBUFNB] __attribute__ ((aligned (4))); /* Ethernet Rx DMA Descriptor */
  ETH_DMADESCTypeDef  DMATxDscrTab[ETH_TXBUFNB] __attribute__ ((aligned (4))); /* Ethernet Tx DMA Descriptor */
  uint8_t Rx_Buff[ETH_RXBUFNB][ETH_RX_BUF_SIZE] __attribute__ ((aligned (4))); /* Ethernet Receive Buffer */
  uint8_t Tx_Buff[ETH_TXBUFNB][ETH_TX_BUF_SIZE] __attribute__ ((aligned (4))); /* Ethernet Transmit Buffer */

#elif defined  (__TASKING__) /*!< TASKING Compiler */
  __align(4)
   ETH_DMADESCTypeDef  DMARxDscrTab[ETH_RXBUFNB];/* Ethernet Rx MA Descriptor */
  __align(4)
   ETH_DMADESCTypeDef  DMATxDscrTab[ETH_TXBUFNB];/* Ethernet Tx DMA Descriptor */
  __align(4)
   uint8_t Rx_Buff[ETH_RXBUFNB][ETH_RX_BUF_SIZE]; /* Ethernet Receive Buffer */
  __align(4)
   uint8_t Tx_Buff[ETH_TXBUFNB][ETH_TX_BUF_SIZE]; /* Ethernet Transmit Buffer */

#endif /* __CC_ARM */


/* Global pointers on Tx and Rx descriptor used to track transmit and receive descriptors */
__IO ETH_DMADESCTypeDef  *DMATxDescToSet;
__IO ETH_DMADESCTypeDef  *DMARxDescToGet;


/* Structure used to hold the last received packet descriptors info */
ETH_DMA_Rx_Frame_infos RX_Frame_Descriptor;
__IO ETH_DMA_Rx_Frame_infos *DMA_RX_FRAME_infos;
__IO uint32_t Frame_Rx_index;

//*****************************************************************************

//*****************************************************************************
cHwEthernet_MCU::cHwEthernet_MCU( cHwPort::Pin &resetPin, const cNetAddr<6> &addrPhyIn )

: cHwEthernet( addrPhyIn )

{
  EthInitStatus = 0;
  EthLinkStatus = 0;

  ETH_AutoNegotiation      =  true; // original: true

  //MAC Control Register
  ETH_Watchdog             = !ETH_MACCR_WD; // watchdog disable = false
  ETH_Jabber               = !ETH_MACCR_JD; // Jabber disable = false
  ETH_InterFrameGap        =  ETH_MACCR_IFG_96Bit;
  ETH_CarrierSense         = !ETH_MACCR_CSD; // carrier sense disable = false
  ETH_Speed                =  ETH_MACCR_FES; // fast speed (100M)
  ETH_ReceiveOwn           = !ETH_MACCR_ROD; // receive own disable = false
  ETH_LoopbackMode         = !ETH_MACCR_LM; // loop back mode = false
  ETH_Mode                 =  ETH_MACCR_DM; // full duplex mode = true
#ifdef CHECKSUM_BY_HARDWARE
  ETH_ChecksumOffload      =  ETH_MACCR_IPCO;
#else
  ETH_ChecksumOffload      = !ETH_MACCR_IPCO;
#endif
  ETH_RetryTransmission    =  ETH_MACCR_RD;  // retry transmission disable = true
  ETH_AutomaticPadCRCStrip = !ETH_MACCR_APCS;
  ETH_BackOffLimit         =  ETH_MACCR_BL_10;
  ETH_DeferralCheck        = !ETH_MACCR_DC;

  // MAC Frame Filter Register
  ETH_ReceiveAll               = !ETH_MACFFR_RA;
  ETH_SourceAddrFilter         =  !ETH_MACFFR_SAF   // source address filter = false
                                 |!ETH_MACFFR_SAIF; // SA inverse filtering = false
  ETH_PassControlFrames        =  ETH_MACFFR_PCF_BlockAll;
  ETH_BroadcastFramesReception = !ETH_MACFFR_BFD; // broadcast frame disable = false
  ETH_DestinationAddrFilter    = !ETH_MACFFR_DAIF;
  ETH_PromiscuousMode          = !ETH_MACFFR_PM;
  ETH_MulticastFramesFilter    =  !ETH_MACFFR_HPF
                                 |!ETH_MACFFR_PAM
                                 |!ETH_MACFFR_HM;  //perfect multicast filter
  ETH_UnicastFramesFilter      =  !ETH_MACFFR_HPF
                                 |!ETH_MACFFR_HU;   // perfect unicast filter

  // MAC Hash Table High Register
  ETH_HashTableHigh            = 0x0;

  //MAC Hash Table Low Register
  ETH_HashTableLow             = 0x0;

  //MAC Flow Control Register
  ETH_PauseTime                = 0x0;

  ETH_ZeroQuantaPause          =  ETH_MACFCR_ZQPD; // Zero quanta pause disable = true
  ETH_PauseLowThreshold        =  ETH_MACFCR_PLT_Minus4; //ETH_PauseLowThreshold_Minus4;
  ETH_UnicastPauseFrameDetect  = !ETH_MACFCR_UPFD;
  ETH_ReceiveFlowControl       = !ETH_MACFCR_RFCE;
  ETH_TransmitFlowControl      = !ETH_MACFCR_TFCE;

  // MAC VLAN Tag Register
  ETH_VLANTagComparison        = !ETH_MACVLANTR_VLANTC; // VLAN 12bit = false
  ETH_VLANTagIdentifier        = 0x0;

  // Ethernet DMA Operation Mode Register
  ETH_DropTCPIPChecksumErrorFrame = !ETH_DMAOMR_DTCEFD; // droping TCP/IP checksum error frames disable = false
  ETH_ReceiveStoreForward         =  ETH_DMAOMR_RSF;
  ETH_FlushReceivedFrame          = !ETH_DMAOMR_DFRF; // flushing of received frames disable = false
  ETH_TransmitStoreForward        =  ETH_DMAOMR_TSF;
  ETH_TransmitThresholdControl    =  ETH_DMAOMR_TTC_64Bytes;
  ETH_ForwardErrorFrames          = !ETH_DMAOMR_FEF;
  ETH_ForwardUndersizedGoodFrames = !ETH_DMAOMR_FUGF;
  ETH_ReceiveThresholdControl     =  ETH_DMAOMR_RTC_64Bytes;
  ETH_SecondFrameOperate          =  ETH_DMAOMR_OSF;

  // Ethernet DMA Bus Mode Register
  ETH_AddressAlignedBeats         =  ETH_DMABMR_AAB;
  ETH_FixedBurst                  =  ETH_DMABMR_FB;
  ETH_RxDMABurstLength            =  ETH_DMABMR_RDP_32Beat;
  ETH_TxDMABurstLength            =  ETH_DMABMR_PBL_32Beat;
  ETH_DescriptorSkipLength        =  0x0;

  ETH_DMAArbitration              =   ETH_DMABMR_RTPR_1_1 // Rx Tx priority ratio = 1:1
                                    |!ETH_DMABMR_DA;      // DMA arbitration scheme, RxPriorTx = false

  RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;  // Enable SYSCFG clock

  /* MII/RMII Media interface selection --------------------------------------*/
  SYSCFG->PMC |= SYSCFG_PMC_MII_RMII_SEL; // MediaInterface RMII = true;

  cHwPinConfig::set( cHwPinConfig::ETH_M,        cHwPinConfig::HIGH_SPEED
                                                |cHwPinConfig::PUSH_PULL
                                                |cHwPinConfig::NO_PUPD  );
																								
  cHwPinConfig::set( cHwPinConfig::ETH_MDIO,         cHwPinConfig::HIGH_SPEED
																								|cHwPinConfig::OPEN_DRAIN
                                                |cHwPinConfig::NO_PUPD  );
																								
  cHwPinConfig::set( cHwPinConfig::ETH_MII_RX_CLK,   cHwPinConfig::HIGH_SPEED
                                                |cHwPinConfig::OPEN_DRAIN
                                                |cHwPinConfig::NO_PUPD  );
																								
  cHwPinConfig::set( cHwPinConfig::ETH_MII_RX_DV,    cHwPinConfig::HIGH_SPEED
                                                |cHwPinConfig::OPEN_DRAIN
                                                |cHwPinConfig::NO_PUPD  );

 cHwPinConfig::set( cHwPinConfig::ETH_MII_TX_EN,    cHwPinConfig::HIGH_SPEED
                                                |cHwPinConfig::PUSH_PULL
                                                |cHwPinConfig::NO_PUPD  );

  cHwPinConfig::set( cHwPinConfig::ETH_MII_TXD0,    cHwPinConfig::HIGH_SPEED
                                                  |cHwPinConfig::PUSH_PULL
                                                  |cHwPinConfig::NO_PUPD  );
																									
  cHwPinConfig::set( cHwPinConfig::ETH_MII_TXD1,    cHwPinConfig::HIGH_SPEED
                                                  |cHwPinConfig::PUSH_PULL
                                                  |cHwPinConfig::NO_PUPD  );

 // cHwPinConfig::set( cHwPinConfig::ETH_MII_RX_ER );
 // cHwPinConfig::set( cHwPinConfig::ETH_MII_TX_EN );
//  cHwPinConfig::set( cHwPinConfig::ETH_MII_TXD0  );
//  cHwPinConfig::set( cHwPinConfig::ETH_MII_TXD1  );
//  cHwPinConfig::set( cHwPinConfig::ETH_MDC       );
  cHwPinConfig::set( cHwPinConfig::ETH_MII_RXD0,    cHwPinConfig::HIGH_SPEED
                                                |cHwPinConfig::INPUT
                                                |cHwPinConfig::NO_PUPD  );
  cHwPinConfig::set( cHwPinConfig::ETH_MII_RXD1,    cHwPinConfig::HIGH_SPEED
                                                |cHwPinConfig::INPUT
                                                |cHwPinConfig::NO_PUPD  );

  resetPin.setMode(cHwPort::OutOD);
  resetPin.clr();
  cSystem::delayMilliSec(1000);
  resetPin.set();

  RCC->AHB1ENR |= (  RCC_AHB1ENR_ETHMACEN
                   | RCC_AHB1ENR_ETHMACTXEN
                   | RCC_AHB1ENR_ETHMACRXEN
                   | RCC_AHB1ENR_ETHMACPTPEN ); // PTP dazu

  /* Reset ETHERNET on AHB Bus */
  RCC->AHB1RSTR |= RCC_AHB1RSTR_ETHMACRST;
  RCC->AHB1RSTR &= ~RCC_AHB1RSTR_ETHMACRST;

  /* Software reset */
  /* Set the SWR bit: resets all MAC subsystem internal registers and logic */
  /* After reset all the registers holds their respective reset values */
  ETH->DMABMR |= ETH_DMABMR_SR;

  /* Wait for software reset */
  while( ETH->DMABMR & ETH_DMABMR_SR );


  /*------------------------   DMA   -----------------------------------*/
  DWORD id;
  BYTE PhyAddr;
  for(PhyAddr = 0; 32 > PhyAddr; PhyAddr++)
  {
    id =   (DWORD)ETH_ReadPHYRegister(PhyAddr,2)<<16
         | (DWORD)ETH_ReadPHYRegister(PhyAddr,3);

    // datasheet for the ks8721bl ethernet controller (http://www.micrel.com/_PDF/Ethernet/datasheets/ks8721bl-sl.pdf)
    // page 20 --> PHY Identifier 1 and 2
    if ((0x00221619 == id) || (0x0007C0F1 == id))
      break;
  }

  if(32 < PhyAddr)
  {
    //printf("Ethernet Phy Not Found\n\r");
    while(1);
  }

  /* Configure Ethernet */
  EthInitStatus = ETH_Init( PhyAddr);

   if (EthInitStatus == 0) {
    while(1);
  }

  low_level_init();
}

//*****************************************************************************
WORD cHwEthernet_MCU::getType( )
{
  cHwEthernet_Header *eth =(cHwEthernet_Header *)buf;

  if     ( plen >= sizeof( cNetIP_Msg ) && eth->type == TYPE_IP )
  {
    return( TYPE_IP );
  }
  else if( plen >= sizeof( cNetARP_Msg ) && eth->type == TYPE_ARP )
  {
    return( TYPE_ARP );
  }
  else
  {
    return( TYPE_UNDEF );
  }
  //return( TYPE_UNDEF );
}

//*****************************************************************************
void cHwEthernet_MCU::PacketSend(  uint8_t* packet, uint16_t len)
{
  low_level_output(packet, len);


//  while( !Rdy4Tx() );

//  RequestSend( len );
//	CopyToFrame_EMAC(packet, len);

}

//*****************************************************************************
// Gets a packet from the network receive buffer, if one is available.
// The packet will be headed by an ethernet header.
//      maxlen  The maximum acceptable length of a retrieved packet.
//      packet  Pointer where packet data should be stored.
// Returns: Packet length in bytes if a packet was retrieved, zero otherwise.
bool cHwEthernet_MCU::PacketReceive()
{
  if( ETH_CheckFrameReceived() )
  {
//    WORD len = StartReadFrame();
//    if( len > BUFFER_SIZE)
//      len = BUFFER_SIZE;
//    CopyFromFrame_EMAC( buf, len);
//    EndReadFrame();
//    plen = len;
//    return( true );
		plen = low_level_input(buf,BUFFER_SIZE);

    return( true );
  }



//  if( CheckFrameReceived() )
//  {
//    WORD len = StartReadFrame();
//    if( len > BUFFER_SIZE)
//      len = BUFFER_SIZE;
//    CopyFromFrame_EMAC( buf, len);
//    EndReadFrame();
//    plen = len;
//    return( true );
//  }
//  else
//  {
//    return( false );
//  }
  return( false );
}

//*****************************************************************************
void cHwEthernet_MCU::create( const cNetAddr<6> destAddr,
                                   const WORD    type )
{
  cHwEthernet_Header *eth = (cHwEthernet_Header*)buf;

  eth->destinationAddr = destAddr;
  eth->sourceAddr      = addrPhy;
  eth->type            = type;
}


//*****************************************************************************
//
//
//
void cHwEthernet_MCU::low_level_init(/*struct netif *netif, cNetAddr<6> macAddr*/)
    {
    #ifdef CHECKSUM_BY_HARDWARE
      int i;
    #endif
      /* set MAC hardware address length */
      //netif->hwaddr_len = 6;
BYTE hwaddr[6];
      /* set MAC hardware address */
      hwaddr[0] =  addrPhy.addr[0]; //MAC_ADDR0;
      hwaddr[1] =  addrPhy.addr[1];
      hwaddr[2] =  addrPhy.addr[2];
      hwaddr[3] =  addrPhy.addr[3];
      hwaddr[4] =  addrPhy.addr[4];
      hwaddr[5] =  addrPhy.addr[5];

      /* initialize MAC address in ethernet MAC */
      ETH_MACAddressConfig(ETH_MAC_Address0, hwaddr);

      /* maximum transfer unit */
      //netif->mtu = 1500;

      /* device capabilities */
      /* don't set NETIF_FLAG_ETHARP if this device is not an ethernet one */
      //netif->flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_LINK_UP;

      /* Initialize Tx Descriptors list: Chain Mode */
      ETH_DMATxDescChainInit(DMATxDscrTab, &Tx_Buff[0][0], ETH_TXBUFNB);
      /* Initialize Rx Descriptors list: Chain Mode  */
      ETH_DMARxDescChainInit(DMARxDscrTab, &Rx_Buff[0][0], ETH_RXBUFNB);

    #ifdef CHECKSUM_BY_HARDWARE
      /* Enable the TCP, UDP and ICMP checksum insertion for the Tx frames */
      for(i=0; i<ETH_TXBUFNB; i++)
        {
          ETH_DMATxDescChecksumInsertionConfig(&DMATxDscrTab[i], ETH_DMATxDesc_ChecksumTCPUDPICMPFull);
        }
    #endif

       /* Note: TCP, UDP, ICMP checksum checking for received frame are enabled in DMA config */

      /* Enable MAC and DMA transmission and reception */
      ETH_Start();

    }

//*****************************************************************************
//
//
//
    int cHwEthernet_MCU::low_level_output(/*struct netif *netif,*/ BYTE *buff, DWORD length ) //struct pbuf *p)
    {
			
//      struct pbuf *q;
      int framelength = 0;
      uint8_t *buffer =  (uint8_t *)(DMATxDescToSet->Buffer1Addr);

//      for(DWORD i=0;i<length;i++)
//      {
//        buffer[i] = buff[i];
//      }
      memcpy(buffer,buff,length);
      framelength = length;
 /*???????????????????
      // copy frame from pbufs to driver buffers
      for(q = p; q != NULL; q = q->next)
      {
        memcpy((uint8_t*)&buffer[framelength], q->payload, q->len);
      framelength = framelength + q->len;
      }
*/
      /* Note: padding and CRC for transmitted frame
         are automatically inserted by DMA */

      /* Prepare transmit descriptors to give to DMA*/
      ETH_Prepare_Transmit_Descriptors(framelength);

      return 0; //ERR_OK;
    }

//*****************************************************************************
//
//
//
    //?????????????????????
    //struct pbuf *

    DWORD cHwEthernet_MCU::low_level_input(BYTE *ibuffer, DWORD maxLen)/*struct netif *netif*/
    {
      //???struct pbuf *p, *q;
      uint16_t len;
//      int l =0;
      FrameTypeDef frame;
      uint8_t *buffer;
      uint32_t i=0;
      __IO ETH_DMADESCTypeDef *DMARxNextDesc;


     //???? p = NULL;

      /* get received frame */
      frame = ETH_Get_Received_Frame();

      /* Obtain the size of the packet and put it into the "len" variable. */
      len = frame.length;
      buffer = (uint8_t *)frame.buffer;

      /* We allocate a pbuf chain of pbufs from the Lwip buffer pool */
     //????? p = pbuf_alloc(PBUF_RAW, len, PBUF_POOL);

     // todo: pruefen auf maxLen

      memcpy( ibuffer, buffer,len);
/*      for( DWORD i=0;i<len;i++)
      {
        ibuffer[i] = buffer[i];
      }
      */
      /* copy received frame to pbuf chain */
////////////      if (p != NULL)
////////////      {
////////////        for (q = p; q != NULL; q = q->next)
////////////        {
////////////          memcpy((u8_t*)q->payload, (u8_t*)&buffer[l], q->len);
////////////          l = l + q->len;
////////////        }
////////////      }

      /* Release descriptors to DMA */
      /* Check if frame with multiple DMA buffer segments */
      if (DMA_RX_FRAME_infos->Seg_Count > 1)
      {
        DMARxNextDesc = DMA_RX_FRAME_infos->FS_Rx_Desc;
      }
      else
      {
        DMARxNextDesc = frame.descriptor;
      }

      /* Set Own bit in Rx descriptors: gives the buffers back to DMA */
      for (i=0; i<DMA_RX_FRAME_infos->Seg_Count; i++)
      {
        DMARxNextDesc->Status = ETH_DMARxDesc_OWN;
        DMARxNextDesc = (ETH_DMADESCTypeDef *)(DMARxNextDesc->Buffer2NextDescAddr);
      }

      /* Clear Segment_Count */
      DMA_RX_FRAME_infos->Seg_Count =0;

      /* When Rx Buffer unavailable flag is set: clear it and resume reception */
      if ((ETH->DMASR & ETH_DMASR_RBUS) != (uint32_t)RESET)
      {
        /* Clear RBUS ETHERNET DMA flag */
        ETH->DMASR = ETH_DMASR_RBUS;
        /* Resume DMA reception */
        ETH->DMARPDR = 0;
      }
     ////????? return p;
      return( len );
    }

/******************************************************************************/
/*                           DMA Descriptors functions                        */
/******************************************************************************/
//*****************************************************************************
FrameTypeDef cHwEthernet_MCU::ETH_Get_Received_Frame(void)
{
  uint32_t framelength = 0;
  FrameTypeDef frame = {0,0,0};

  /* Get the Frame Length of the received packet: substruct 4 bytes of the CRC */
  framelength = ((DMARxDescToGet->Status & ETH_DMARxDesc_FL) >> ETH_DMARxDesc_FrameLengthShift) - 4;
  frame.length = framelength;

  /* Get the address of the buffer start address */
  /* Check if more than one segment in the frame */
  if (DMA_RX_FRAME_infos->Seg_Count >1)
  {
    frame.buffer =(DMA_RX_FRAME_infos->FS_Rx_Desc)->Buffer1Addr;
  }
  else
  {
    frame.buffer = DMARxDescToGet->Buffer1Addr;
  }

  frame.descriptor = DMARxDescToGet;

  /* Update the ETHERNET DMA global Rx descriptor with next Rx descriptor */
  /* Chained Mode */
  /* Selects the next DMA Rx descriptor list for next buffer to read */
  DMARxDescToGet = (ETH_DMADESCTypeDef*) (DMARxDescToGet->Buffer2NextDescAddr);

  /* Return Frame */
  return (frame);
}

//*****************************************************************************
uint32_t cHwEthernet_MCU::ETH_Prepare_Transmit_Descriptors(uint16_t FrameLength)
{
  uint32_t buf_count =0, size=0,i=0;

  /* Check if the descriptor is owned by the ETHERNET DMA (when set) or CPU (when reset) */
  if((DMATxDescToSet->Status & ETH_DMATxDesc_OWN) != (uint32_t)RESET)
  {
    /* Return ERROR: OWN bit set */
    return ETH_ERROR;
  }

  if (FrameLength > ETH_TX_BUF_SIZE)
  {
    buf_count = FrameLength/ETH_TX_BUF_SIZE;
    if (FrameLength%ETH_TX_BUF_SIZE) buf_count++;
  }
  else buf_count =1;

  if (buf_count ==1)
  {
    /*set LAST and FIRST segment */
    DMATxDescToSet->Status |= (ETH_DMATxDesc_FS|ETH_DMATxDesc_LS);
    /* Set frame size */
    DMATxDescToSet->ControlBufferSize = (FrameLength& ETH_DMATxDesc_TBS1);
    /* Set Own bit of the Tx descriptor Status: gives the buffer back to ETHERNET DMA */
    DMATxDescToSet->Status |= ETH_DMATxDesc_OWN;
    DMATxDescToSet= (ETH_DMADESCTypeDef *)(DMATxDescToSet->Buffer2NextDescAddr);
  }
  else
  {
    for (i=0; i< buf_count; i++)
    {
			/* Clear FIRST and LAST segment bits */
      DMATxDescToSet->Status &= ~(ETH_DMATxDesc_FS | ETH_DMATxDesc_LS);
      if (i==0)
      {
        /* Setting the first segment bit */
        DMATxDescToSet->Status |= ETH_DMATxDesc_FS;
      }

      /* Program size */
      DMATxDescToSet->ControlBufferSize = (ETH_TX_BUF_SIZE & ETH_DMATxDesc_TBS1);

      if (i== (buf_count-1))
      {
        /* Setting the last segment bit */
        DMATxDescToSet->Status |= ETH_DMATxDesc_LS;
        size = FrameLength - (buf_count-1)*ETH_TX_BUF_SIZE;
        DMATxDescToSet->ControlBufferSize = (size & ETH_DMATxDesc_TBS1);
      }

      /*give back descriptor to DMA */
      DMATxDescToSet->Status |= ETH_DMATxDesc_OWN;

      DMATxDescToSet = (ETH_DMADESCTypeDef *)(DMATxDescToSet->Buffer2NextDescAddr);
      /* Set Own bit of the Tx descriptor Status: gives the buffer back to ETHERNET DMA */
     }
  }

  /* When Tx Buffer unavailable flag is set: clear it and resume transmission */
  if ((ETH->DMASR & ETH_DMASR_TBUS) != (uint32_t)RESET)
  {
    /* Clear TBUS ETHERNET DMA flag */
    ETH->DMASR = ETH_DMASR_TBUS;
    /* Resume DMA transmission*/
    ETH->DMATPDR = 0;
  }

  /* Return SUCCESS */
  return ETH_SUCCESS;
}

//*****************************************************************************
void cHwEthernet_MCU::ETH_DMARxDescChainInit(ETH_DMADESCTypeDef *DMARxDescTab, uint8_t *RxBuff, uint32_t RxBuffCount)
{
  uint32_t i = 0;
  ETH_DMADESCTypeDef *DMARxDesc;

  /* Set the DMARxDescToGet pointer with the first one of the DMARxDescTab list */
  DMARxDescToGet = DMARxDescTab;
  /* Fill each DMARxDesc descriptor with the right values */
  for(i=0; i < RxBuffCount; i++)
  {
    /* Get the pointer on the ith member of the Rx Desc list */
    DMARxDesc = DMARxDescTab+i;
    /* Set Own bit of the Rx descriptor Status */
    DMARxDesc->Status = ETH_DMARxDesc_OWN;

    /* Set Buffer1 size and Second Address Chained bit */
    DMARxDesc->ControlBufferSize = ETH_DMARxDesc_RCH | (uint32_t)ETH_RX_BUF_SIZE;
    /* Set Buffer1 address pointer */
    DMARxDesc->Buffer1Addr = (uint32_t)(&RxBuff[i*ETH_RX_BUF_SIZE]);

    /* Initialize the next descriptor with the Next Descriptor Polling Enable */
    if(i < (RxBuffCount-1))
    {
      /* Set next descriptor address register with next descriptor base address */
      DMARxDesc->Buffer2NextDescAddr = (uint32_t)(DMARxDescTab+i+1);
    }
    else
    {
      /* For last descriptor, set next descriptor address register equal to the first descriptor base address */
      DMARxDesc->Buffer2NextDescAddr = (uint32_t)(DMARxDescTab);
    }
  }

  /* Set Receive Descriptor List Address Register */
  ETH->DMARDLAR = (uint32_t) DMARxDescTab;


  DMA_RX_FRAME_infos = &RX_Frame_Descriptor;

}

//*****************************************************************************
uint32_t cHwEthernet_MCU::ETH_CheckFrameReceived(void)
{
  /* check if last segment */
  if(((DMARxDescToGet->Status & ETH_DMARxDesc_OWN) == (uint32_t)RESET) &&
     ((DMARxDescToGet->Status & ETH_DMARxDesc_LS) != (uint32_t)RESET))
    {
			
      DMA_RX_FRAME_infos->LS_Rx_Desc = DMARxDescToGet;
      DMA_RX_FRAME_infos->Seg_Count++;
      return 1;
    }

    /* check if first segment */
    else if(((DMARxDescToGet->Status & ETH_DMARxDesc_OWN) == (uint32_t)RESET) &&
     ((DMARxDescToGet->Status & ETH_DMARxDesc_FS) != (uint32_t)RESET)&&
     ((DMARxDescToGet->Status & ETH_DMARxDesc_LS) == (uint32_t)RESET))
    {
      DMA_RX_FRAME_infos->FS_Rx_Desc = DMARxDescToGet;
      DMA_RX_FRAME_infos->LS_Rx_Desc = NULL;
      DMA_RX_FRAME_infos->Seg_Count = 1;
      DMARxDescToGet = (ETH_DMADESCTypeDef*) (DMARxDescToGet->Buffer2NextDescAddr);
    }

    /* check if intermediate segment */
    else if(((DMARxDescToGet->Status & ETH_DMARxDesc_OWN) == (uint32_t)RESET) &&
     ((DMARxDescToGet->Status & ETH_DMARxDesc_FS) == (uint32_t)RESET)&&
     ((DMARxDescToGet->Status & ETH_DMARxDesc_LS) == (uint32_t)RESET))
    {
      (DMA_RX_FRAME_infos->Seg_Count) ++;
      DMARxDescToGet = (ETH_DMADESCTypeDef*) (DMARxDescToGet->Buffer2NextDescAddr);
    }
    return 0;
}



//*****************************************************************************
void cHwEthernet_MCU::ETH_DMATxDescChainInit(ETH_DMADESCTypeDef *DMATxDescTab, uint8_t* TxBuff, uint32_t TxBuffCount)
{
  uint32_t i = 0;
  ETH_DMADESCTypeDef *DMATxDesc;

  /* Set the DMATxDescToSet pointer with the first one of the DMATxDescTab list */
  DMATxDescToSet = DMATxDescTab;
  /* Fill each DMATxDesc descriptor with the right values */
  for(i=0; i < TxBuffCount; i++)
  {
    /* Get the pointer on the ith member of the Tx Desc list */
    DMATxDesc = DMATxDescTab + i;
    /* Set Second Address Chained bit */
    DMATxDesc->Status = ETH_DMATxDesc_TCH;

    /* Set Buffer1 address pointer */
    DMATxDesc->Buffer1Addr = (uint32_t)(&TxBuff[i*ETH_TX_BUF_SIZE]);

    /* Initialize the next descriptor with the Next Descriptor Polling Enable */
    if(i < (TxBuffCount-1))
    {
      /* Set next descriptor address register with next descriptor base address */
      DMATxDesc->Buffer2NextDescAddr = (uint32_t)(DMATxDescTab+i+1);
    }
    else
    {
      /* For last descriptor, set next descriptor address register equal to the first descriptor base address */
      DMATxDesc->Buffer2NextDescAddr = (uint32_t) DMATxDescTab;
    }
  }

  /* Set Transmit Desciptor List Address Register */
  ETH->DMATDLAR = (uint32_t) DMATxDescTab;
}

