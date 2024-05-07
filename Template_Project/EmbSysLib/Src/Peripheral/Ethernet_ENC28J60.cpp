//#include <avr/io.h>
/*
#include "lib.h"

#include "net.h"
#include "enc28j60.h"
#include "lowlevel.h"
#include "NetARP.h"
#include "NetIP.h"
*/
#include "Com/Hardware/Ethernet.h"

//#include "ip_arp_udp_tcp.h"

   // ENC28J60 Control Registers
   // Control register definitions are a combination of address,
   // bank number, and Ethernet/MAC/PHY indicator bits.
   // - Register address        (bits 0-4)
   // - Bank number        (bits 5-6)
   // - MAC/PHY indicator        (bit 7)
   #define ADDR_MASK        0x1F
   #define BANK_MASK        0x60
   #define SPRD_MASK        0x80
   // All-bank registers
   #define EIE              0x1B
   #define EIR              0x1C
   #define ESTAT            0x1D
   #define ECON2            0x1E
   #define ECON1            0x1F
   // Bank 0 registers
   #define ERDPT           (0x00|0x00)
   #define ERDPTL           (0x00|0x00)
   #define ERDPTH           (0x01|0x00)
   #define EWRPT           (0x02|0x00)
   #define EWRPTL           (0x02|0x00)
   #define EWRPTH           (0x03|0x00)
   #define ETXST           (0x04|0x00)
   #define ETXSTL           (0x04|0x00)
   #define ETXSTH           (0x05|0x00)
   #define ETXND           (0x06|0x00)
   #define ETXNDL           (0x06|0x00)
   #define ETXNDH           (0x07|0x00)
   #define ERXST           (0x08|0x00)
   #define ERXSTL           (0x08|0x00)
   #define ERXSTH           (0x09|0x00)
   #define ERXND           (0x0A|0x00)
   #define ERXNDL           (0x0A|0x00)
   #define ERXNDH           (0x0B|0x00)
   #define ERXRDPT         (0x0C|0x00)
   #define ERXRDPTL         (0x0C|0x00)
   #define ERXRDPTH         (0x0D|0x00)
   #define ERXWRPTL         (0x0E|0x00)
   #define ERXWRPTH         (0x0F|0x00)
   #define EDMASTL          (0x10|0x00)
   #define EDMASTH          (0x11|0x00)
   #define EDMANDL          (0x12|0x00)
   #define EDMANDH          (0x13|0x00)
   #define EDMADSTL         (0x14|0x00)
   #define EDMADSTH         (0x15|0x00)
   #define EDMACSL          (0x16|0x00)
   #define EDMACSH          (0x17|0x00)
   // Bank 1 registers
   #define EHT0             (0x00|0x20)
   #define EHT1             (0x01|0x20)
   #define EHT2             (0x02|0x20)
   #define EHT3             (0x03|0x20)
   #define EHT4             (0x04|0x20)
   #define EHT5             (0x05|0x20)
   #define EHT6             (0x06|0x20)
   #define EHT7             (0x07|0x20)
   #define EPMM0            (0x08|0x20)
   #define EPMM1            (0x09|0x20)
   #define EPMM2            (0x0A|0x20)
   #define EPMM3            (0x0B|0x20)
   #define EPMM4            (0x0C|0x20)
   #define EPMM5            (0x0D|0x20)
   #define EPMM6            (0x0E|0x20)
   #define EPMM7            (0x0F|0x20)
   #define EPMCSL           (0x10|0x20)
   #define EPMCSH           (0x11|0x20)
   #define EPMOL            (0x14|0x20)
   #define EPMOH            (0x15|0x20)
   #define EWOLIE           (0x16|0x20)
   #define EWOLIR           (0x17|0x20)
   #define ERXFCON          (0x18|0x20)
   #define EPKTCNT          (0x19|0x20)
   // Bank 2 registers
   #define MACON1           (0x00|0x40|0x80)
   #define MACON2           (0x01|0x40|0x80)
   #define MACON3           (0x02|0x40|0x80)
   #define MACON4           (0x03|0x40|0x80)
   #define MABBIPG          (0x04|0x40|0x80)
   #define MAIPGL           (0x06|0x40|0x80)
   #define MAIPGH           (0x07|0x40|0x80)
   #define MACLCON1         (0x08|0x40|0x80)
   #define MACLCON2         (0x09|0x40|0x80)
   #define MAMXFL          (0x0A|0x40|0x80)
   #define MAMXFLL          (0x0A|0x40|0x80)
   #define MAMXFLH          (0x0B|0x40|0x80)
   #define MAPHSUP          (0x0D|0x40|0x80)
   #define MICON            (0x11|0x40|0x80)
   #define MICMD            (0x12|0x40|0x80)
   #define MIREGADR         (0x14|0x40|0x80)
#define MIWR             (0x16|0x40|0x80)
   #define MIWRL            (0x16|0x40|0x80)
   #define MIWRH            (0x17|0x40|0x80)
   #define MIRDL            (0x18|0x40|0x80)
   #define MIRDH            (0x19|0x40|0x80)
   // Bank 3 registers
   #define MAADR1           (0x00|0x60|0x80)
   #define MAADR0           (0x01|0x60|0x80)
   #define MAADR3           (0x02|0x60|0x80)
   #define MAADR2           (0x03|0x60|0x80)
   #define MAADR5           (0x04|0x60|0x80)
   #define MAADR4           (0x05|0x60|0x80)
   #define EBSTSD           (0x06|0x60)
   #define EBSTCON          (0x07|0x60)
   #define EBSTCSL          (0x08|0x60)
   #define EBSTCSH          (0x09|0x60)
   #define MISTAT           (0x0A|0x60|0x80)
   #define EREVID           (0x12|0x60)
   #define ECOCON           (0x15|0x60)
   #define EFLOCON          (0x17|0x60)
   #define EPAUSL           (0x18|0x60)
   #define EPAUSH           (0x19|0x60)
   // PHY registers
   #define PHCON1           0x00
   #define PHSTAT1          0x01
   #define PHHID1           0x02
   #define PHHID2           0x03
   #define PHCON2           0x10
   #define PHSTAT2          0x11
   #define PHIE             0x12
   #define PHIR             0x13
   #define PHLCON           0x14

   // ENC28J60 ERXFCON Register Bit Definitions
   #define ERXFCON_UCEN     0x80
   #define ERXFCON_ANDOR    0x40
   #define ERXFCON_CRCEN    0x20
   #define ERXFCON_PMEN     0x10
   #define ERXFCON_MPEN     0x08
   #define ERXFCON_HTEN     0x04
   #define ERXFCON_MCEN     0x02
   #define ERXFCON_BCEN     0x01
   // ENC28J60 EIE Register Bit Definitions
   #define EIE_INTIE        0x80
   #define EIE_PKTIE        0x40
   #define EIE_DMAIE        0x20
   #define EIE_LINKIE       0x10
   #define EIE_TXIE         0x08
   #define EIE_WOLIE        0x04
   #define EIE_TXERIE       0x02
   #define EIE_RXERIE       0x01
   // ENC28J60 EIR Register Bit Definitions
   #define EIR_PKTIF        0x40
   #define EIR_DMAIF        0x20
   #define EIR_LINKIF       0x10
   #define EIR_TXIF         0x08
   #define EIR_WOLIF        0x04
   #define EIR_TXERIF       0x02
   #define EIR_RXERIF       0x01
   // ENC28J60 ESTAT Register Bit Definitions
   #define ESTAT_INT        0x80
   #define ESTAT_LATECOL    0x10
   #define ESTAT_RXBUSY     0x04
   #define ESTAT_TXABRT     0x02
   #define ESTAT_CLKRDY     0x01
   // ENC28J60 ECON2 Register Bit Definitions
   #define ECON2_AUTOINC    0x80
   #define ECON2_PKTDEC     0x40
   #define ECON2_PWRSV      0x20
   #define ECON2_VRPS       0x08
   // ENC28J60 ECON1 Register Bit Definitions
   #define ECON1_TXRST      0x80
   #define ECON1_RXRST      0x40
   #define ECON1_DMAST      0x20
   #define ECON1_CSUMEN     0x10
   #define ECON1_TXRTS      0x08
   #define ECON1_RXEN       0x04
   #define ECON1_BSEL1      0x02
   #define ECON1_BSEL0      0x01
   // ENC28J60 MACON1 Register Bit Definitions
   #define MACON1_LOOPBK    0x10
   #define MACON1_TXPAUS    0x08
   #define MACON1_RXPAUS    0x04
   #define MACON1_PASSALL   0x02
   #define MACON1_MARXEN    0x01
   // ENC28J60 MACON2 Register Bit Definitions
   #define MACON2_MARST     0x80
   #define MACON2_RNDRST    0x40
   #define MACON2_MARXRST   0x08
   #define MACON2_RFUNRST   0x04
   #define MACON2_MATXRST   0x02
   #define MACON2_TFUNRST   0x01
   // ENC28J60 MACON3 Register Bit Definitions
   #define MACON3_PADCFG2   0x80
   #define MACON3_PADCFG1   0x40
   #define MACON3_PADCFG0   0x20
   #define MACON3_TXCRCEN   0x10
   #define MACON3_PHDRLEN   0x08
   #define MACON3_HFRMLEN   0x04
   #define MACON3_FRMLNEN   0x02
   #define MACON3_FULDPX    0x01
   // ENC28J60 MICMD Register Bit Definitions
   #define MICMD_MIISCAN    0x02
   #define MICMD_MIIRD      0x01
   // ENC28J60 MISTAT Register Bit Definitions
   #define MISTAT_NVALID    0x04
   #define MISTAT_SCAN      0x02
   #define MISTAT_BUSY      0x01
   // ENC28J60 PHY PHCON1 Register Bit Definitions
   #define PHCON1_PRST      0x8000
   #define PHCON1_PLOOPBK   0x4000
   #define PHCON1_PPWRSV    0x0800
   #define PHCON1_PDPXMD    0x0100
   // ENC28J60 PHY PHSTAT1 Register Bit Definitions
   #define PHSTAT1_PFDPX    0x1000
   #define PHSTAT1_PHDPX    0x0800
   #define PHSTAT1_LLSTAT   0x0004
   #define PHSTAT1_JBSTAT   0x0002
   // ENC28J60 PHY PHCON2 Register Bit Definitions
   #define PHCON2_FRCLINK   0x4000
   #define PHCON2_TXDIS     0x2000
   #define PHCON2_JABBER    0x0400
   #define PHCON2_HDLDIS    0x0100

   // ENC28J60 Packet Control Byte Bit Definitions
   #define PKTCTRL_PHUGEEN  0x08
   #define PKTCTRL_PPADEN   0x04
   #define PKTCTRL_PCRCEN   0x02
   #define PKTCTRL_POVERRIDE 0x01

   // SPI operation codes
   #define ENC28J60_READ_CTRL_REG       0x00
   #define ENC28J60_READ_BUF_MEM        0x3A
   #define ENC28J60_WRITE_CTRL_REG      0x40
   #define ENC28J60_WRITE_BUF_MEM       0x7A
   #define ENC28J60_BIT_FIELD_SET       0x80
   #define ENC28J60_BIT_FIELD_CLR       0xA0
   #define ENC28J60_SOFT_RESET          0xFF


   // The RXSTART_INIT should be zero. See Rev. B4 Silicon Errata
   // buffer boundaries applied to internal 8K ram
   // the entire available packet buffer space is allocated
   //
   // start with recbuf at 0/
   #define RXSTART_INIT     (WORD)0x0000
   // receive buffer end
   #define RXSTOP_INIT      (WORD)(0x1FFF-0x0600-1)
   // start TX buffer at 0x1FFF-0x0600, pace for one full ethernet frame (~1500 bytes)
   #define TXSTART_INIT     (WORD)(0x1FFF-0x0600)
   // stp TX buffer at end of mem
   #define TXSTOP_INIT      (WORD)0x1FFF
   // max frame length which the conroller will accept:
   #define        MAX_FRAMELEN        1500        // (note: maximum ethernet frame length would be 1518)


//*****************************************************************************
//*****************************************************************************
cHwEthernet_Enc28j60::cHwEthernet_Enc28j60( const cNetAddr<6>  &addrPhyIn, 
  cHwSPImaster::Device &spiIn )

: cHwEthernet( addrPhyIn ),
   spi( spiIn ) ,
   addrPhy( addrPhyIn )

{
  Init(addrPhyIn);
  cSystem::delayMilliSec(10);
  InitPhy();
}

//*****************************************************************************
WORD cHwEthernet_Enc28j60::getType( )
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
}


//*****************************************************************************
uint8_t cHwEthernet_Enc28j60::ReadOp(uint8_t op, uint8_t address)
{
  BYTE data[3] = { (BYTE)(op | (address & ADDR_MASK)),
                   0x00,
	                 0x00 };

  if( address & 0x80 ) // do dummy read if needed (for mac and mii, see datasheet page 29)

  {
    spi.transceive( data, 3 );
    return( data[2] );
  }
  else
  {
    spi.transceive( data, 2 );
    return( data[1] );
  }
}

//*****************************************************************************
void cHwEthernet_Enc28j60::WriteOp(uint8_t op, uint8_t address, uint8_t dataIn)
{
  BYTE data[2] = { (BYTE)( op | (address & ADDR_MASK) ),
                   dataIn };

  spi.write( data, 2 );
}

//*****************************************************************************
void cHwEthernet_Enc28j60::ReadBuffer(uint16_t len, uint8_t* data)
{
  spi.start();
  spi.spi.transceiveByte( (BYTE)ENC28J60_READ_BUF_MEM );
  // PROBLEM: CS wird hier angefasst, funktiuoniert es trotzdem???
  for(WORD i=0;i<len;i++)
    data[i] = spi.spi.transceiveByte( 0x00 );
  data[len] = '\0';
  spi.stop();
  
}

//*****************************************************************************
void cHwEthernet_Enc28j60::WriteBuffer(uint16_t len, uint8_t* data)
{
  spi.start();
  spi.spi.transceiveByte( (BYTE)ENC28J60_WRITE_BUF_MEM );
  // PROBLEM: CS wird hier angefasst, funktiuoniert es trotzdem???
  for(WORD i=0;i<len;i++)
    spi.spi.transceiveByte( data[i] );
  spi.stop();
}

//*****************************************************************************
void cHwEthernet_Enc28j60::SetBank(uint8_t address)
{
   // set the bank (if needed)
   if((address & BANK_MASK) != Bank)
   {
      // set the bank
      WriteOp(ENC28J60_BIT_FIELD_CLR, ECON1, (ECON1_BSEL1|ECON1_BSEL0));
      WriteOp(ENC28J60_BIT_FIELD_SET, ECON1, (address & BANK_MASK)>>5);
      Bank = (address & BANK_MASK);
   }
}

//*****************************************************************************
uint8_t cHwEthernet_Enc28j60::Read(uint8_t address)
{
   SetBank(address);
   return ReadOp(ENC28J60_READ_CTRL_REG, address);
}

//*****************************************************************************
void cHwEthernet_Enc28j60::WriteByte(uint8_t address, uint8_t data)
{
   SetBank(address);
   WriteOp(ENC28J60_WRITE_CTRL_REG, address, data);
}

//*****************************************************************************
void cHwEthernet_Enc28j60::WriteWord(uint8_t address, WORD data)
{
   SetBank(address);
   WriteOp(ENC28J60_WRITE_CTRL_REG, address, data&0xFF);
   SetBank(address+1);
   WriteOp(ENC28J60_WRITE_CTRL_REG, address+1, data>>8);
}


//*****************************************************************************
void cHwEthernet_Enc28j60::PhyWrite(uint8_t address, uint16_t data)
{
   WriteByte(MIREGADR, address);         // set the PHY register address
   WriteWord(MIWR, data);                // write the PHY data
   while(Read(MISTAT) & MISTAT_BUSY) // wait until the PHY write completes
   {
      cSystem::delayMicroSec(15);
   }
}


//**************************************************************************************
// Flash the 2 RJ45 LEDs twice to show that the interface works
void cHwEthernet_Enc28j60::InitPhy (void)
{
	/* Magjack leds configuration, see enc28j60 datasheet, page 11 */
	// LEDA=green LEDB=yellow
	//
	// 0x880 is PHLCON LEDB=on, LEDA=on
	// enc28j60PhyWrite(PHLCON,0b0000 1000 1000 00 00);
	PhyWrite(PHLCON,0x880);
	cSystem::delayMilliSec(500);
	//
	// 0x990 is PHLCON LEDB=off, LEDA=off
	// enc28j60PhyWrite(PHLCON,0b0000 1001 1001 00 00);
	PhyWrite(PHLCON,0x990);
	cSystem::delayMilliSec(500);
	//
	// 0x880 is PHLCON LEDB=on, LEDA=on
	// enc28j60PhyWrite(PHLCON,0b0000 1000 1000 00 00);
	PhyWrite(PHLCON,0x880);
	cSystem::delayMilliSec(500);
	//
	// 0x990 is PHLCON LEDB=off, LEDA=off
	// enc28j60PhyWrite(PHLCON,0b0000 1001 1001 00 00);
	PhyWrite(PHLCON,0x990);
	cSystem::delayMilliSec(500);
	//
   // 0x476 is PHLCON LEDA=links status, LEDB=receive/transmit
   // enc28j60PhyWrite(PHLCON,0b0000 0100 0111 01 10);
   PhyWrite(PHLCON,0x476);
	cSystem::delayMilliSec(100);
}


//*****************************************************************************
void cHwEthernet_Enc28j60::Init(const cNetAddr<6>  &addrPhyIn)
{
   // perform system reset
   WriteOp(ENC28J60_SOFT_RESET, 0, ENC28J60_SOFT_RESET);
   cSystem::delayMilliSec(50);
   // check CLKRDY bit to see if reset is complete
   // The CLKRDY does not work. See Rev. B4 Silicon Errata point. Just wait.
   //while(!(enc28j60Read(ESTAT) & ESTAT_CLKRDY));
   // do bank 0 stuff
   // initialize receive buffer
   // 16-bit transfers, must write low byte first
   // set receive buffer start address
   NextPacketPtr = RXSTART_INIT;
   // Rx start
   WriteWord(ERXST, RXSTART_INIT );
   // set receive pointer address
   WriteWord(ERXRDPT, RXSTART_INIT );
   // RX end
   WriteWord(ERXND, RXSTOP_INIT );
   // TX start
   WriteWord(ETXST, TXSTART_INIT );
   // TX end
   WriteWord(ETXND, TXSTOP_INIT );
   // do bank 1 stuff, packet filter:
   // For broadcast packets we allow only ARP packtets
   // All other packets should be unicast only for our mac (MAADR)
   //
   // The pattern to match on is therefore
   // Type     ETH.DST
   // ARP      BROADCAST
   // 06 08 -- ff ff ff ff ff ff -> ip checksum for theses bytes=f7f9
   // in binary these poitions are:11 0000 0011 1111
   // This is hex 303F->EPMM0=0x3f,EPMM1=0x30
   WriteByte(ERXFCON, 0 /*ERXFCON_UCEN*/  /*| ERXFCON_CRCEN */ /*| ERXFCON_PMEN*/ );
   WriteByte(EPMM0, 0x3f);
   WriteByte(EPMM1, 0x30);
   WriteByte(EPMCSL, 0xf9);
   WriteByte(EPMCSH, 0xf7);
   //
   //
   // do bank 2 stuff
   // enable MAC receive
   WriteByte(MACON1, MACON1_MARXEN | MACON1_TXPAUS | MACON1_RXPAUS);
   // bring MAC out of reset
   WriteByte(MACON2, 0x00);
   // enable automatic padding to 60bytes and CRC operations
   WriteOp(ENC28J60_BIT_FIELD_SET, MACON3, MACON3_PADCFG0 | MACON3_TXCRCEN | MACON3_FRMLNEN);
   // set inter-frame gap (non-back-to-back)
   WriteByte(MAIPGL, 0x12);
   WriteByte(MAIPGH, 0x0C);
   // set inter-frame gap (back-to-back)
   WriteByte(MABBIPG, 0x12);
   // Set the maximum packet size which the controller will accept
   // Do not send packets longer than MAX_FRAMELEN:
   WriteWord(MAMXFL, MAX_FRAMELEN );
   // do bank 3 stuff
   // write MAC address
   // NOTE: MAC address in ENC28J60 is byte-backward
   WriteByte(MAADR5, addrPhyIn.addr[0]);
   WriteByte(MAADR4, addrPhyIn.addr[1]);
   WriteByte(MAADR3, addrPhyIn.addr[2]);
   WriteByte(MAADR2, addrPhyIn.addr[3]);
   WriteByte(MAADR1, addrPhyIn.addr[4]);
   WriteByte(MAADR0, addrPhyIn.addr[5]);
   // no loopback of transmitted frames
   PhyWrite(PHCON2, PHCON2_HDLDIS);
   // switch to bank 0
   SetBank(ECON1);
   // enable interrutps
   WriteOp(ENC28J60_BIT_FIELD_SET, EIE, EIE_INTIE | EIE_PKTIE);
   // enable packet reception
   WriteOp(ENC28J60_BIT_FIELD_SET, ECON1, ECON1_RXEN);
}

//*****************************************************************************
uint8_t cHwEthernet_Enc28j60::getrev(void)     // read the revision of the chip
{
	return(Read(EREVID));
}

//*****************************************************************************
void cHwEthernet_Enc28j60::PacketSend(uint8_t* packet, uint16_t len)
{
	// Set the write pointer to start of transmit buffer area
	WriteWord(EWRPT, TXSTART_INIT );
	// Set the TXND pointer to correspond to the packet size given
	WriteWord(ETXND, (TXSTART_INIT + len) );
	// write per-packet control byte (0x00 means use macon3 settings)
	WriteOp(ENC28J60_WRITE_BUF_MEM, 0, 0x00);
	// copy the packet into the transmit buffer
	WriteBuffer(len, packet);
	// send the contents of the transmit buffer onto the network
	WriteOp(ENC28J60_BIT_FIELD_SET, ECON1, ECON1_TXRTS);
   // Reset the transmit logic problem. See Rev. B4 Silicon Errata point 12.
	if((Read(EIR) & EIR_TXERIF))
   {
    //! /todo Workaround on transmit error
    Init(addrPhy);
    cSystem::delayMilliSec(10);
    InitPhy();
//    WriteOp(ENC28J60_BIT_FIELD_CLR, ECON1, ECON1_TXRTS);
   }
}

//*****************************************************************************
// Gets a packet from the network receive buffer, if one is available.
// The packet will be headed by an ethernet header.
//      maxlen  The maximum acceptable length of a retrieved packet.
//      packet  Pointer where packet data should be stored.
// Returns: Packet length in bytes if a packet was retrieved, zero otherwise.
bool cHwEthernet_Enc28j60::PacketReceive()
{
uint16_t maxlen = BUFFER_SIZE;
	uint16_t rxstat;
	uint16_t len;
	// check if a packet has been received and buffered
	//if( !(enc28j60Read(EIR) & EIR_PKTIF) ){
        // The above does not work. See Rev. B4 Silicon Errata point 6.
	if( Read(EPKTCNT) ==0 )
   {
		return(0);
   }

	// Set the read pointer to the start of the received packet
	WriteWord(ERDPT, NextPacketPtr);

   // read the next packet pointer
	NextPacketPtr  = ReadOp(ENC28J60_READ_BUF_MEM, 0);
	NextPacketPtr |= ReadOp(ENC28J60_READ_BUF_MEM, 0) << 8;

	// read the packet length (see datasheet page 43)
	len  = ReadOp(ENC28J60_READ_BUF_MEM, 0);
	len |= ReadOp(ENC28J60_READ_BUF_MEM, 0) << 8;
   len -= 4; //remove the CRC count

   // read the receive status (see datasheet page 43)
	rxstat  = ReadOp(ENC28J60_READ_BUF_MEM, 0);
	rxstat |= ReadOp(ENC28J60_READ_BUF_MEM, 0) << 8;

	// limit retrieve length
   if (len>maxlen-1)
   {
      len=maxlen-1;
   }
   // check CRC and symbol errors (see datasheet page 44, table 7-3):
   // The ERXFCON.CRCEN is set by default. Normally we should not
   // need to check this.
   if ((rxstat & 0x80)==0)
   {
      // invalid
      len=0;
   }
   else
   {
      // copy the packet from the receive buffer
      ReadBuffer(len, buf);
   }

   // Move the RX read pointer to the start of the next received packet
	// This frees the memory we just read out
	WriteWord(ERXRDPT, NextPacketPtr);

   // decrement the packet counter indicate we are done with this packet
	WriteOp(ENC28J60_BIT_FIELD_SET, ECON2, ECON2_PKTDEC);

  plen = len;
	return( (plen==0)?false:true );
}

//*****************************************************************************
void cHwEthernet_Enc28j60::create( const cNetAddr<6> destAddr,
                                   const WORD        type )
{
  cHwEthernet_Header *eth = (cHwEthernet_Header *)buf;

  eth->destinationAddr = destAddr;
  eth->sourceAddr      = addrPhy;
  eth->type            = type;
}

