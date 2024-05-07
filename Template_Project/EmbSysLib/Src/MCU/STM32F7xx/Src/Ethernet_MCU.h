/**
  ******************************************************************************
  * @file    stm32f4x7_eth.h
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    14-October-2011
  * @brief   This file contains all the functions prototypes for the Ethernet
  *          firmware driver.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; Portions COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */
/**
  ******************************************************************************
  * <h2><center>&copy; Portions COPYRIGHT 2012 Embest Tech. Co., Ltd.</center></h2>
  * @file    stm32f4x7_eth.h
  * @author  CMP Team
  * @version V1.0.0
  * @date    28-December-2012
  * @brief   This file contains all the functions prototypes for the Ethernet
  *          firmware driver.     
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, Embest SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT
  * OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT
  * OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION
  * CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  ******************************************************************************
  */
/**
  ******************************************************************************
  * @file    stm32f4x7_eth.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    14-October-2011
  * @brief   This file is the low level driver for STM32F407xx/417xx Ethernet Controller.
  *          This driver does not include low level functions for PTP time-stamp.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; Portions COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */
/**
  ******************************************************************************
  * <h2><center>&copy; Portions COPYRIGHT 2012 Embest Tech. Co., Ltd.</center></h2>
  * @file    stm32f4x7_eth.c
  * @author  CMP Team
  * @version V1.0.0
  * @date    28-December-2012
  * @brief   This file is the low level driver for STM32F407xx/417xx Ethernet Controller.
  *          This driver does not include low level functions for PTP time-stamp.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, Embest SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT
  * OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT
  * OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION
  * CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _ETHERNET_MCU_H
#define _ETHERNET_MCU_H

/* Includes ------------------------------------------------------------------*/
#include "Com/Hardware/Ethernet/Ethernet.h"
#include "Com/Hardware/Port/Port.h"

#include <string.h>

/* Exported constants --------------------------------------------------------*/

/* Uncomment the line below when using time stamping and/or IPv4 checksum offload */
#define USE_ENHANCED_DMA_DESCRIPTORS

/* Uncomment the line below if you want to use user defined Delay function
   (for precise timing), otherwise default _eth_delay_ function defined within
   the Ethernet driver is used (less precise timing) */
//#define USE_Delay



/* Uncomment the line below to allow custom configuration of the Ethernet driver buffers */    
//#define CUSTOM_DRIVER_BUFFERS_CONFIG   

#ifdef  CUSTOM_DRIVER_BUFFERS_CONFIG
/* Redefinition of the Ethernet driver buffers size and count */   
 #define ETH_RX_BUF_SIZE    ETH_MAX_PACKET_SIZE /* buffer size for receive */
 #define ETH_TX_BUF_SIZE    ETH_MAX_PACKET_SIZE /* buffer size for transmit */
 #define ETH_RXBUFNB        20                  /* 20 Rx buffers of size ETH_RX_BUF_SIZE */
xxx #define ETH_TXBUFNB        5                   /* 5  Tx buffers of size ETH_TX_BUF_SIZE */
#endif


/* PHY configuration section **************************************************/
/* The PHY status register value change from a PHY to another, so the user have 
   to update this value depending on the used external PHY */
#define PHY_SR    ((uint16_t)31) /* Value for DP83848 PHY */

/* The Speed and Duplex mask values change from a PHY to another, so the user
   have to update this value depending on the used external PHY */
#define PHY_DUPLEX_SPEED_STATUS_MASK  ((uint16_t)0x001C)
#define PHY_100BTX_FULL               (18)
#define PHY_100BTX_HALF								(8)
#define PHY_10M_FULL									(14)
#define PHY_10M_HALF									(4)
   


/**--------------------------------------------------------------------------**/
/** 
  * @brief                           DMA descriptors types
  */ 
/**--------------------------------------------------------------------------**/

/** 
  * @brief  ETH DMA Descriptors data structure definition
  */ 
typedef struct  {
  __IO uint32_t   Status;                /*!< Status */
  uint32_t   ControlBufferSize;     /*!< Control and Buffer1, Buffer2 lengths */
  uint32_t   Buffer1Addr;           /*!< Buffer1 address pointer */
  uint32_t   Buffer2NextDescAddr;   /*!< Buffer2 or next descriptor address pointer */
/* Enhanced ETHERNET DMA PTP Descriptors */
#ifdef USE_ENHANCED_DMA_DESCRIPTORS
  uint32_t   ExtendedStatus;        /* Extended status for PTP receive descriptor */
  uint32_t   Reserved1;             /* Reserved */
  uint32_t   TimeStampLow;          /* Time Stamp Low value for transmit and receive */
  uint32_t   TimeStampHigh;         /* Time Stamp High value for transmit and receive */
#endif /* USE_ENHANCED_DMA_DESCRIPTORS */
} ETH_DMADESCTypeDef;


typedef struct{
  uint32_t length;
  uint32_t buffer;
  __IO ETH_DMADESCTypeDef *descriptor;
}FrameTypeDef;


typedef struct  {
  __IO ETH_DMADESCTypeDef *FS_Rx_Desc;          /*!< First Segment Rx Desc */
  __IO ETH_DMADESCTypeDef *LS_Rx_Desc;          /*!< Last Segment Rx Desc */
  __IO uint32_t  Seg_Count;                     /*!< Segment count */
} ETH_DMA_Rx_Frame_infos;
  

/**--------------------------------------------------------------------------**/
/** 
  * @brief                          ETH Frames defines
  */ 
/**--------------------------------------------------------------------------**/
#define ETH_MAX_PACKET_SIZE    1524    /*!< ETH_HEADER + ETH_EXTRA + VLAN_TAG + MAX_ETH_PAYLOAD + ETH_CRC */
#define ETH_HEADER               14    /*!< 6 byte Dest addr, 6 byte Src addr, 2 byte length/type */
#define ETH_CRC                   4    /*!< Ethernet CRC */
#define ETH_EXTRA                 2    /*!< Extra bytes in some cases */   
#define VLAN_TAG                  4    /*!< optional 802.1q VLAN Tag */
#define MIN_ETH_PAYLOAD          46    /*!< Minimum Ethernet payload size */
#define MAX_ETH_PAYLOAD        1500    /*!< Maximum Ethernet payload size */
#define JUMBO_FRAME_PAYLOAD    9000    /*!< Jumbo frame payload size */      

 /* Ethernet driver receive buffers are organized in a chained linked-list, when
    an ethernet packet is received, the Rx-DMA will transfer the packet from RxFIFO
    to the driver receive buffers memory.
    
    Depending on the size of the received ethernet packet and the size of 
    each ethernet driver receive buffer, the received packet can take one or more
    ethernet driver receive buffer. 
    
    In below are defined the size of one ethernet driver receive buffer ETH_RX_BUF_SIZE 
    and the total count of the driver receive buffers ETH_RXBUFNB.
    
    The configured value for ETH_RX_BUF_SIZE and ETH_RXBUFNB are only provided as 
    example, they can be reconfigured in the application layer to fit the application 
    needs */ 
   
/* Here we configure each Ethernet driver receive buffer to fit the Max size Ethernet
   packet */    
#ifndef ETH_RX_BUF_SIZE
 #define ETH_RX_BUF_SIZE         ETH_MAX_PACKET_SIZE 
#endif

/* 5 Ethernet driver receive buffers are used (in a chained linked list)*/ 
#ifndef ETH_RXBUFNB
 #define ETH_RXBUFNB             5     /*  5 Rx buffers of size ETH_RX_BUF_SIZE */
#endif


 /* Ethernet driver transmit buffers are organized in a chained linked-list, when
    an ethernet packet is transmitted, Tx-DMA will transfer the packet from the 
    driver transmit buffers memory to the TxFIFO.
    
    Depending on the size of the Ethernet packet to be transmitted and the size of 
    each ethernet driver transmit buffer, the packet to be transmitted can take 
    one or more ethernet driver transmit buffer. 
    
    In below are defined the size of one ethernet driver transmit buffer ETH_TX_BUF_SIZE 
    and the total count of the driver transmit buffers ETH_TXBUFNB.
    
    The configured value for ETH_TX_BUF_SIZE and ETH_TXBUFNB are only provided as 
    example, they can be reconfigured in the application layer to fit the application 
    needs */ 
   
/* Here we configure each Ethernet driver transmit buffer to fit the Max size Ethernet
   packet */  
#ifndef ETH_TX_BUF_SIZE 
 #define ETH_TX_BUF_SIZE         ETH_MAX_PACKET_SIZE
#endif

/* 5 ethernet driver transmit buffers are used (in a chained linked list)*/ 
#ifndef ETH_TXBUFNB
 #define ETH_TXBUFNB             5      /* 5  Tx buffers of size ETH_TX_BUF_SIZE */
#endif

#define  ETH_DMARxDesc_FrameLengthShift           16

/**--------------------------------------------------------------------------**/
/** 
  * @brief                 Ethernet DMA descriptors registers bits definition
  */ 
/**--------------------------------------------------------------------------**/

/**
@code 
   DMA Tx Desciptor
  -----------------------------------------------------------------------------------------------
  TDES0 | OWN(31) | CTRL[30:26] | Reserved[25:24] | CTRL[23:20] | Reserved[19:17] | Status[16:0] |
  -----------------------------------------------------------------------------------------------
  TDES1 | Reserved[31:29] | Buffer2 ByteCount[28:16] | Reserved[15:13] | Buffer1 ByteCount[12:0] |
  -----------------------------------------------------------------------------------------------
  TDES2 |                         Buffer1 Address [31:0]                                         |
  -----------------------------------------------------------------------------------------------
  TDES3 |                   Buffer2 Address [31:0] / Next Descriptor Address [31:0]              |
  -----------------------------------------------------------------------------------------------
@endcode
*/

/** 
  * @brief  Bit definition of TDES0 register: DMA Tx descriptor status register
  */ 
#define ETH_DMATxDesc_OWN                     ((uint32_t)0x80000000)  /*!< OWN bit: descriptor is owned by DMA engine */
#define ETH_DMATxDesc_IC                      ((uint32_t)0x40000000)  /*!< Interrupt on Completion */
#define ETH_DMATxDesc_LS                      ((uint32_t)0x20000000)  /*!< Last Segment */
#define ETH_DMATxDesc_FS                      ((uint32_t)0x10000000)  /*!< First Segment */
#define ETH_DMATxDesc_DC                      ((uint32_t)0x08000000)  /*!< Disable CRC */
#define ETH_DMATxDesc_DP                      ((uint32_t)0x04000000)  /*!< Disable Padding */
#define ETH_DMATxDesc_TTSE                    ((uint32_t)0x02000000)  /*!< Transmit Time Stamp Enable */
#define ETH_DMATxDesc_CIC                     ((uint32_t)0x00C00000)  /*!< Checksum Insertion Control: 4 cases */
#define ETH_DMATxDesc_CIC_ByPass              ((uint32_t)0x00000000)  /*!< Do Nothing: Checksum Engine is bypassed */ 
#define ETH_DMATxDesc_CIC_IPV4Header          ((uint32_t)0x00400000)  /*!< IPV4 header Checksum Insertion */ 
#define ETH_DMATxDesc_CIC_TCPUDPICMP_Segment  ((uint32_t)0x00800000)  /*!< TCP/UDP/ICMP Checksum Insertion calculated over segment only */ 
#define ETH_DMATxDesc_CIC_TCPUDPICMP_Full     ((uint32_t)0x00C00000)  /*!< TCP/UDP/ICMP Checksum Insertion fully calculated */ 
#define ETH_DMATxDesc_TER                     ((uint32_t)0x00200000)  /*!< Transmit End of Ring */
#define ETH_DMATxDesc_TCH                     ((uint32_t)0x00100000)  /*!< Second Address Chained */
#define ETH_DMATxDesc_TTSS                    ((uint32_t)0x00020000)  /*!< Tx Time Stamp Status */
#define ETH_DMATxDesc_IHE                     ((uint32_t)0x00010000)  /*!< IP Header Error */
#define ETH_DMATxDesc_ES                      ((uint32_t)0x00008000)  /*!< Error summary: OR of the following bits: UE || ED || EC || LCO || NC || LCA || FF || JT */
#define ETH_DMATxDesc_JT                      ((uint32_t)0x00004000)  /*!< Jabber Timeout */
#define ETH_DMATxDesc_FF                      ((uint32_t)0x00002000)  /*!< Frame Flushed: DMA/MTL flushed the frame due to SW flush */
#define ETH_DMATxDesc_PCE                     ((uint32_t)0x00001000)  /*!< Payload Checksum Error */
#define ETH_DMATxDesc_LCA                     ((uint32_t)0x00000800)  /*!< Loss of Carrier: carrier lost during transmission */
#define ETH_DMATxDesc_NC                      ((uint32_t)0x00000400)  /*!< No Carrier: no carrier signal from the transceiver */
#define ETH_DMATxDesc_LCO                     ((uint32_t)0x00000200)  /*!< Late Collision: transmission aborted due to collision */
#define ETH_DMATxDesc_EC                      ((uint32_t)0x00000100)  /*!< Excessive Collision: transmission aborted after 16 collisions */
#define ETH_DMATxDesc_VF                      ((uint32_t)0x00000080)  /*!< VLAN Frame */
#define ETH_DMATxDesc_CC                      ((uint32_t)0x00000078)  /*!< Collision Count */
#define ETH_DMATxDesc_ED                      ((uint32_t)0x00000004)  /*!< Excessive Deferral */
#define ETH_DMATxDesc_UF                      ((uint32_t)0x00000002)  /*!< Underflow Error: late data arrival from the memory */
#define ETH_DMATxDesc_DB                      ((uint32_t)0x00000001)  /*!< Deferred Bit */

/** 
  * @brief  Bit definition of TDES1 register
  */ 
#define ETH_DMATxDesc_TBS2  ((uint32_t)0x1FFF0000)  /*!< Transmit Buffer2 Size */
#define ETH_DMATxDesc_TBS1  ((uint32_t)0x00001FFF)  /*!< Transmit Buffer1 Size */

/** 
  * @brief  Bit definition of TDES2 register
  */ 
#define ETH_DMATxDesc_B1AP  ((uint32_t)0xFFFFFFFF)  /*!< Buffer1 Address Pointer */

/** 
  * @brief  Bit definition of TDES3 register
  */ 
#define ETH_DMATxDesc_B2AP  ((uint32_t)0xFFFFFFFF)  /*!< Buffer2 Address Pointer */

  /*---------------------------------------------------------------------------------------------
  TDES6 |                         Transmit Time Stamp Low [31:0]                                 |
  -----------------------------------------------------------------------------------------------
  TDES7 |                         Transmit Time Stamp High [31:0]                                |
  ----------------------------------------------------------------------------------------------*/

/* Bit definition of TDES6 register */
 #define ETH_DMAPTPTxDesc_TTSL  ((uint32_t)0xFFFFFFFF)  /* Transmit Time Stamp Low */

/* Bit definition of TDES7 register */
 #define ETH_DMAPTPTxDesc_TTSH  ((uint32_t)0xFFFFFFFF)  /* Transmit Time Stamp High */

/**
@code 
  DMA Rx Descriptor
  --------------------------------------------------------------------------------------------------------------------
  RDES0 | OWN(31) |                                             Status [30:0]                                          |
  ---------------------------------------------------------------------------------------------------------------------
  RDES1 | CTRL(31) | Reserved[30:29] | Buffer2 ByteCount[28:16] | CTRL[15:14] | Reserved(13) | Buffer1 ByteCount[12:0] |
  ---------------------------------------------------------------------------------------------------------------------
  RDES2 |                                       Buffer1 Address [31:0]                                                 |
  ---------------------------------------------------------------------------------------------------------------------
  RDES3 |                          Buffer2 Address [31:0] / Next Descriptor Address [31:0]                             |
  ---------------------------------------------------------------------------------------------------------------------
@endcode
*/

/** 
  * @brief  Bit definition of RDES0 register: DMA Rx descriptor status register
  */ 
#define ETH_DMARxDesc_OWN         ((uint32_t)0x80000000)  /*!< OWN bit: descriptor is owned by DMA engine  */
#define ETH_DMARxDesc_AFM         ((uint32_t)0x40000000)  /*!< DA Filter Fail for the rx frame  */
#define ETH_DMARxDesc_FL          ((uint32_t)0x3FFF0000)  /*!< Receive descriptor frame length  */
#define ETH_DMARxDesc_ES          ((uint32_t)0x00008000)  /*!< Error summary: OR of the following bits: DE || OE || IPC || LC || RWT || RE || CE */
#define ETH_DMARxDesc_DE          ((uint32_t)0x00004000)  /*!< Descriptor error: no more descriptors for receive frame  */
#define ETH_DMARxDesc_SAF         ((uint32_t)0x00002000)  /*!< SA Filter Fail for the received frame */
#define ETH_DMARxDesc_LE          ((uint32_t)0x00001000)  /*!< Frame size not matching with length field */
#define ETH_DMARxDesc_OE          ((uint32_t)0x00000800)  /*!< Overflow Error: Frame was damaged due to buffer overflow */
#define ETH_DMARxDesc_VLAN        ((uint32_t)0x00000400)  /*!< VLAN Tag: received frame is a VLAN frame */
#define ETH_DMARxDesc_FS          ((uint32_t)0x00000200)  /*!< First descriptor of the frame  */
#define ETH_DMARxDesc_LS          ((uint32_t)0x00000100)  /*!< Last descriptor of the frame  */ 
#define ETH_DMARxDesc_IPV4HCE     ((uint32_t)0x00000080)  /*!< IPC Checksum Error: Rx Ipv4 header checksum error   */    
#define ETH_DMARxDesc_LC          ((uint32_t)0x00000040)  /*!< Late collision occurred during reception   */
#define ETH_DMARxDesc_FT          ((uint32_t)0x00000020)  /*!< Frame type - Ethernet, otherwise 802.3    */
#define ETH_DMARxDesc_RWT         ((uint32_t)0x00000010)  /*!< Receive Watchdog Timeout: watchdog timer expired during reception    */
#define ETH_DMARxDesc_RE          ((uint32_t)0x00000008)  /*!< Receive error: error reported by MII interface  */
#define ETH_DMARxDesc_DBE         ((uint32_t)0x00000004)  /*!< Dribble bit error: frame contains non int multiple of 8 bits  */
#define ETH_DMARxDesc_CE          ((uint32_t)0x00000002)  /*!< CRC error */
#define ETH_DMARxDesc_MAMPCE      ((uint32_t)0x00000001)  /*!< Rx MAC Address/Payload Checksum Error: Rx MAC address matched/ Rx Payload Checksum Error */

/** 
  * @brief  Bit definition of RDES1 register
  */ 
#define ETH_DMARxDesc_DIC   ((uint32_t)0x80000000)  /*!< Disable Interrupt on Completion */
#define ETH_DMARxDesc_RBS2  ((uint32_t)0x1FFF0000)  /*!< Receive Buffer2 Size */
#define ETH_DMARxDesc_RER   ((uint32_t)0x00008000)  /*!< Receive End of Ring */
#define ETH_DMARxDesc_RCH   ((uint32_t)0x00004000)  /*!< Second Address Chained */
#define ETH_DMARxDesc_RBS1  ((uint32_t)0x00001FFF)  /*!< Receive Buffer1 Size */

/** 
  * @brief  Bit definition of RDES2 register  
  */ 
#define ETH_DMARxDesc_B1AP  ((uint32_t)0xFFFFFFFF)  /*!< Buffer1 Address Pointer */

/** 
  * @brief  Bit definition of RDES3 register  
  */ 
#define ETH_DMARxDesc_B2AP  ((uint32_t)0xFFFFFFFF)  /*!< Buffer2 Address Pointer */

/*---------------------------------------------------------------------------------------------------------------------
  RDES4 |                   Reserved[31:15]              |             Extended Status [14:0]                          |
  ---------------------------------------------------------------------------------------------------------------------
  RDES5 |                                            Reserved[31:0]                                                    |
  ---------------------------------------------------------------------------------------------------------------------
  RDES6 |                                       Receive Time Stamp Low [31:0]                                          |
  ---------------------------------------------------------------------------------------------------------------------
  RDES7 |                                       Receive Time Stamp High [31:0]                                         |
  --------------------------------------------------------------------------------------------------------------------*/

/* Bit definition of RDES4 register */
#define ETH_DMAPTPRxDesc_PTPV     ((uint32_t)0x00002000)  /* PTP Version */
#define ETH_DMAPTPRxDesc_PTPFT    ((uint32_t)0x00001000)  /* PTP Frame Type */
#define ETH_DMAPTPRxDesc_PTPMT    ((uint32_t)0x00000F00)  /* PTP Message Type */
  #define ETH_DMAPTPRxDesc_PTPMT_Sync                      ((uint32_t)0x00000100)  /* SYNC message (all clock types) */
  #define ETH_DMAPTPRxDesc_PTPMT_FollowUp                  ((uint32_t)0x00000200)  /* FollowUp message (all clock types) */ 
  #define ETH_DMAPTPRxDesc_PTPMT_DelayReq                  ((uint32_t)0x00000300)  /* DelayReq message (all clock types) */ 
  #define ETH_DMAPTPRxDesc_PTPMT_DelayResp                 ((uint32_t)0x00000400)  /* DelayResp message (all clock types) */ 
  #define ETH_DMAPTPRxDesc_PTPMT_PdelayReq_Announce        ((uint32_t)0x00000500)  /* PdelayReq message (peer-to-peer transparent clock) or Announce message (Ordinary or Boundary clock) */ 
  #define ETH_DMAPTPRxDesc_PTPMT_PdelayResp_Manag          ((uint32_t)0x00000600)  /* PdelayResp message (peer-to-peer transparent clock) or Management message (Ordinary or Boundary clock)  */ 
  #define ETH_DMAPTPRxDesc_PTPMT_PdelayRespFollowUp_Signal ((uint32_t)0x00000700)  /* PdelayRespFollowUp message (peer-to-peer transparent clock) or Signaling message (Ordinary or Boundary clock) */           
#define ETH_DMAPTPRxDesc_IPV6PR   ((uint32_t)0x00000080)  /* IPv6 Packet Received */
#define ETH_DMAPTPRxDesc_IPV4PR   ((uint32_t)0x00000040)  /* IPv4 Packet Received */
#define ETH_DMAPTPRxDesc_IPCB  ((uint32_t)0x00000020)  /* IP Checksum Bypassed */
#define ETH_DMAPTPRxDesc_IPPE  ((uint32_t)0x00000010)  /* IP Payload Error */
#define ETH_DMAPTPRxDesc_IPHE  ((uint32_t)0x00000008)  /* IP Header Error */
#define ETH_DMAPTPRxDesc_IPPT  ((uint32_t)0x00000007)  /* IP Payload Type */
  #define ETH_DMAPTPRxDesc_IPPT_UDP                 ((uint32_t)0x00000001)  /* UDP payload encapsulated in the IP datagram */
  #define ETH_DMAPTPRxDesc_IPPT_TCP                 ((uint32_t)0x00000002)  /* TCP payload encapsulated in the IP datagram */ 
  #define ETH_DMAPTPRxDesc_IPPT_ICMP                ((uint32_t)0x00000003)  /* ICMP payload encapsulated in the IP datagram */

/* Bit definition of RDES6 register */
#define ETH_DMAPTPRxDesc_RTSL  ((uint32_t)0xFFFFFFFF)  /* Receive Time Stamp Low */

/* Bit definition of RDES7 register */
#define ETH_DMAPTPRxDesc_RTSH  ((uint32_t)0xFFFFFFFF)  /* Receive Time Stamp High */


/**--------------------------------------------------------------------------**/
/** 
  * @brief                     Description of common PHY registers
  */ 
/**--------------------------------------------------------------------------**/
/** @defgroup PHY_Read_write_Timeouts 
  * @{
  */ 
#define PHY_READ_TO                     ((uint32_t)0x0004FFFF)
#define PHY_WRITE_TO                    ((uint32_t)0x0004FFFF)

/** @defgroup PHY_Register_address 
  * @{
  */ 
#define PHY_BCR                          0          /*!< Transceiver Basic Control Register */
#define PHY_BSR                          1          /*!< Transceiver Basic Status Register */

/** @defgroup PHY_basic_Control_register 
  * @{
  */ 
#define PHY_Reset                       ((uint16_t)0x8000)      /*!< PHY Reset */
#define PHY_Loopback                    ((uint16_t)0x4000)      /*!< Select loop-back mode */
#define PHY_FULLDUPLEX_100M             ((uint16_t)0x2100)      /*!< Set the full-duplex mode at 100 Mb/s */
#define PHY_HALFDUPLEX_100M             ((uint16_t)0x2000)      /*!< Set the half-duplex mode at 100 Mb/s */
#define PHY_FULLDUPLEX_10M              ((uint16_t)0x0100)      /*!< Set the full-duplex mode at 10 Mb/s */
#define PHY_HALFDUPLEX_10M              ((uint16_t)0x0000)      /*!< Set the half-duplex mode at 10 Mb/s */
#define PHY_AutoNegotiation             ((uint16_t)0x1000)      /*!< Enable auto-negotiation function */
#define PHY_Restart_AutoNegotiation     ((uint16_t)0x0200)      /*!< Restart auto-negotiation function */
#define PHY_Powerdown                   ((uint16_t)0x0800)      /*!< Select the power down mode */
#define PHY_Isolate                     ((uint16_t)0x0400)      /*!< Isolate PHY from MII */

/** @defgroup PHY_basic_status_register 
  * @{
  */ 
#define PHY_AutoNego_Complete           ((uint16_t)0x0020)      /*!< Auto-Negotiation process completed */
#define PHY_Linked_Status               ((uint16_t)0x0004)      /*!< Valid link established */
#define PHY_Jabber_detection            ((uint16_t)0x0002)      /*!< Jabber condition detected */

/** @defgroup ETH_MAC_Flags 
  * @{
  */ 
#define ETH_MAC_FLAG_TST     ((uint32_t)0x00000200)  /*!< Time stamp trigger flag (on MAC) */
#define ETH_MAC_FLAG_MMCT    ((uint32_t)0x00000040)  /*!< MMC transmit flag  */
#define ETH_MAC_FLAG_MMCR    ((uint32_t)0x00000020)  /*!< MMC receive flag */
#define ETH_MAC_FLAG_MMC     ((uint32_t)0x00000010)  /*!< MMC flag (on MAC) */
#define ETH_MAC_FLAG_PMT     ((uint32_t)0x00000008)  /*!< PMT flag (on MAC) */

/** @defgroup ETH_MAC_Interrupts 
  * @{
  */ 
#define ETH_MAC_IT_TST       ((uint32_t)0x00000200)  /*!< Time stamp trigger interrupt (on MAC) */
#define ETH_MAC_IT_MMCT      ((uint32_t)0x00000040)  /*!< MMC transmit interrupt */
#define ETH_MAC_IT_MMCR      ((uint32_t)0x00000020)  /*!< MMC receive interrupt */
#define ETH_MAC_IT_MMC       ((uint32_t)0x00000010)  /*!< MMC interrupt (on MAC) */
#define ETH_MAC_IT_PMT       ((uint32_t)0x00000008)  /*!< PMT interrupt (on MAC) */

/** @defgroup ETH_MAC_addresses 
  * @{
  */ 
#define ETH_MAC_Address0     ((uint32_t)0x00000000)
#define ETH_MAC_Address1     ((uint32_t)0x00000008)
#define ETH_MAC_Address2     ((uint32_t)0x00000010)
#define ETH_MAC_Address3     ((uint32_t)0x00000018)

/** @defgroup ETH_MAC_addresses_filter_SA_DA_filed_of_received_frames 
  * @{
  */ 
#define ETH_MAC_AddressFilter_SA       ((uint32_t)0x00000000)
#define ETH_MAC_AddressFilter_DA       ((uint32_t)0x00000008)

/** @defgroup ETH_MAC_addresses_filter_Mask_bytes 
  * @{
  */ 
#define ETH_MAC_AddressMask_Byte6      ((uint32_t)0x20000000)  /*!< Mask MAC Address high reg bits [15:8] */
#define ETH_MAC_AddressMask_Byte5      ((uint32_t)0x10000000)  /*!< Mask MAC Address high reg bits [7:0] */
#define ETH_MAC_AddressMask_Byte4      ((uint32_t)0x08000000)  /*!< Mask MAC Address low reg bits [31:24] */
#define ETH_MAC_AddressMask_Byte3      ((uint32_t)0x04000000)  /*!< Mask MAC Address low reg bits [23:16] */
#define ETH_MAC_AddressMask_Byte2      ((uint32_t)0x02000000)  /*!< Mask MAC Address low reg bits [15:8] */
#define ETH_MAC_AddressMask_Byte1      ((uint32_t)0x01000000)  /*!< Mask MAC Address low reg bits [70] */

/**--------------------------------------------------------------------------**/
/** 
  * @brief                      Ethernet DMA Descriptors defines
  */ 
/**--------------------------------------------------------------------------**/

/** @defgroup ETH_DMA_Tx_descriptor_segment 
  * @{
  */ 
#define ETH_DMATxDesc_LastSegment      ((uint32_t)0x40000000)  /*!< Last Segment */
#define ETH_DMATxDesc_FirstSegment     ((uint32_t)0x20000000)  /*!< First Segment */

/** @defgroup ETH_DMA_Tx_descriptor_Checksum_Insertion_Control
  * @{
  */ 
#define ETH_DMATxDesc_ChecksumByPass             ((uint32_t)0x00000000)   /*!< Checksum engine bypass */
#define ETH_DMATxDesc_ChecksumIPV4Header         ((uint32_t)0x00400000)   /*!< IPv4 header checksum insertion  */
#define ETH_DMATxDesc_ChecksumTCPUDPICMPSegment  ((uint32_t)0x00800000)   /*!< TCP/UDP/ICMP checksum insertion. Pseudo header checksum is assumed to be present */
#define ETH_DMATxDesc_ChecksumTCPUDPICMPFull     ((uint32_t)0x00C00000)   /*!< TCP/UDP/ICMP checksum fully in hardware including pseudo header */

/** @defgroup ETH_DMA_Rx_descriptor_buffers_ 
  * @{
  */ 
#define ETH_DMARxDesc_Buffer1     ((uint32_t)0x00000000)  /*!< DMA Rx Desc Buffer1 */
#define ETH_DMARxDesc_Buffer2     ((uint32_t)0x00000001)  /*!< DMA Rx Desc Buffer2 */

/** @defgroup ETH_DMA_Flags 
  * @{
  */ 
#define ETH_DMA_FLAG_TST               ((uint32_t)0x20000000)  /*!< Time-stamp trigger interrupt (on DMA) */
#define ETH_DMA_FLAG_PMT               ((uint32_t)0x10000000)  /*!< PMT interrupt (on DMA) */
#define ETH_DMA_FLAG_MMC               ((uint32_t)0x08000000)  /*!< MMC interrupt (on DMA) */
#define ETH_DMA_FLAG_DataTransferError ((uint32_t)0x00800000)  /*!< Error bits 0-Rx DMA, 1-Tx DMA */
#define ETH_DMA_FLAG_ReadWriteError    ((uint32_t)0x01000000)  /*!< Error bits 0-write trnsf, 1-read transfr */
#define ETH_DMA_FLAG_AccessError       ((uint32_t)0x02000000)  /*!< Error bits 0-data buffer, 1-desc. access */
#define ETH_DMA_FLAG_NIS               ((uint32_t)0x00010000)  /*!< Normal interrupt summary flag */
#define ETH_DMA_FLAG_AIS               ((uint32_t)0x00008000)  /*!< Abnormal interrupt summary flag */
#define ETH_DMA_FLAG_ER                ((uint32_t)0x00004000)  /*!< Early receive flag */
#define ETH_DMA_FLAG_FBE               ((uint32_t)0x00002000)  /*!< Fatal bus error flag */
#define ETH_DMA_FLAG_ET                ((uint32_t)0x00000400)  /*!< Early transmit flag */
#define ETH_DMA_FLAG_RWT               ((uint32_t)0x00000200)  /*!< Receive watchdog timeout flag */
#define ETH_DMA_FLAG_RPS               ((uint32_t)0x00000100)  /*!< Receive process stopped flag */
#define ETH_DMA_FLAG_RBU               ((uint32_t)0x00000080)  /*!< Receive buffer unavailable flag */
#define ETH_DMA_FLAG_R                 ((uint32_t)0x00000040)  /*!< Receive flag */
#define ETH_DMA_FLAG_TU                ((uint32_t)0x00000020)  /*!< Underflow flag */
#define ETH_DMA_FLAG_RO                ((uint32_t)0x00000010)  /*!< Overflow flag */
#define ETH_DMA_FLAG_TJT               ((uint32_t)0x00000008)  /*!< Transmit jabber timeout flag */
#define ETH_DMA_FLAG_TBU               ((uint32_t)0x00000004)  /*!< Transmit buffer unavailable flag */
#define ETH_DMA_FLAG_TPS               ((uint32_t)0x00000002)  /*!< Transmit process stopped flag */
#define ETH_DMA_FLAG_T                 ((uint32_t)0x00000001)  /*!< Transmit flag */

/** @defgroup ETH_DMA_Interrupts 
  * @{
  */ 
#define ETH_DMA_IT_TST       ((uint32_t)0x20000000)  /*!< Time-stamp trigger interrupt (on DMA) */
#define ETH_DMA_IT_PMT       ((uint32_t)0x10000000)  /*!< PMT interrupt (on DMA) */
#define ETH_DMA_IT_MMC       ((uint32_t)0x08000000)  /*!< MMC interrupt (on DMA) */
#define ETH_DMA_IT_NIS       ((uint32_t)0x00010000)  /*!< Normal interrupt summary */
#define ETH_DMA_IT_AIS       ((uint32_t)0x00008000)  /*!< Abnormal interrupt summary */
#define ETH_DMA_IT_ER        ((uint32_t)0x00004000)  /*!< Early receive interrupt */
#define ETH_DMA_IT_FBE       ((uint32_t)0x00002000)  /*!< Fatal bus error interrupt */
#define ETH_DMA_IT_ET        ((uint32_t)0x00000400)  /*!< Early transmit interrupt */
#define ETH_DMA_IT_RWT       ((uint32_t)0x00000200)  /*!< Receive watchdog timeout interrupt */
#define ETH_DMA_IT_RPS       ((uint32_t)0x00000100)  /*!< Receive process stopped interrupt */
#define ETH_DMA_IT_RBU       ((uint32_t)0x00000080)  /*!< Receive buffer unavailable interrupt */
#define ETH_DMA_IT_R         ((uint32_t)0x00000040)  /*!< Receive interrupt */
#define ETH_DMA_IT_TU        ((uint32_t)0x00000020)  /*!< Underflow interrupt */
#define ETH_DMA_IT_RO        ((uint32_t)0x00000010)  /*!< Overflow interrupt */
#define ETH_DMA_IT_TJT       ((uint32_t)0x00000008)  /*!< Transmit jabber timeout interrupt */
#define ETH_DMA_IT_TBU       ((uint32_t)0x00000004)  /*!< Transmit buffer unavailable interrupt */
#define ETH_DMA_IT_TPS       ((uint32_t)0x00000002)  /*!< Transmit process stopped interrupt */
#define ETH_DMA_IT_T         ((uint32_t)0x00000001)  /*!< Transmit interrupt */

/** @defgroup ETH_DMA_transmit_process_state_ 
  * @{
  */ 
#define ETH_DMA_TransmitProcess_Stopped     ((uint32_t)0x00000000)  /*!< Stopped - Reset or Stop Tx Command issued */
#define ETH_DMA_TransmitProcess_Fetching    ((uint32_t)0x00100000)  /*!< Running - fetching the Tx descriptor */
#define ETH_DMA_TransmitProcess_Waiting     ((uint32_t)0x00200000)  /*!< Running - waiting for status */
#define ETH_DMA_TransmitProcess_Reading     ((uint32_t)0x00300000)  /*!< Running - reading the data from host memory */
#define ETH_DMA_TransmitProcess_Suspended   ((uint32_t)0x00600000)  /*!< Suspended - Tx Descriptor unavailable */
#define ETH_DMA_TransmitProcess_Closing     ((uint32_t)0x00700000)  /*!< Running - closing Rx descriptor */

/** @defgroup ETH_DMA_receive_process_state_ 
  * @{
  */ 
#define ETH_DMA_ReceiveProcess_Stopped      ((uint32_t)0x00000000)  /*!< Stopped - Reset or Stop Rx Command issued */
#define ETH_DMA_ReceiveProcess_Fetching     ((uint32_t)0x00020000)  /*!< Running - fetching the Rx descriptor */
#define ETH_DMA_ReceiveProcess_Waiting      ((uint32_t)0x00060000)  /*!< Running - waiting for packet */
#define ETH_DMA_ReceiveProcess_Suspended    ((uint32_t)0x00080000)  /*!< Suspended - Rx Descriptor unavailable */
#define ETH_DMA_ReceiveProcess_Closing      ((uint32_t)0x000A0000)  /*!< Running - closing descriptor */
#define ETH_DMA_ReceiveProcess_Queuing      ((uint32_t)0x000E0000)  /*!< Running - queuing the receive frame into host memory */

/** @defgroup ETH_DMA_overflow_ 
  * @{
  */ 
#define ETH_DMA_Overflow_RxFIFOCounter      ((uint32_t)0x10000000)  /*!< Overflow bit for FIFO overflow counter */
#define ETH_DMA_Overflow_MissedFrameCounter ((uint32_t)0x00010000)  /*!< Overflow bit for missed frame counter */
#define IS_ETH_DMA_GET_OVERFLOW(OVERFLOW) (((OVERFLOW) == ETH_DMA_Overflow_RxFIFOCounter) || \
                                           ((OVERFLOW) == ETH_DMA_Overflow_MissedFrameCounter))

/**--------------------------------------------------------------------------**/
/** 
  * @brief                           Ethernet PMT defines
  */ 
/**--------------------------------------------------------------------------**/
/**
  * @}
  */

/** @defgroup ETH_PMT_Flags 
  * @{
  */ 
#define ETH_PMT_FLAG_WUFFRPR      ((uint32_t)0x80000000)  /*!< Wake-Up Frame Filter Register Pointer Reset */
#define ETH_PMT_FLAG_WUFR         ((uint32_t)0x00000040)  /*!< Wake-Up Frame Received */
#define ETH_PMT_FLAG_MPR          ((uint32_t)0x00000020)  /*!< Magic Packet Received */

/**--------------------------------------------------------------------------**/
/** 
  * @brief                           Ethernet MMC defines
  */ 
/**--------------------------------------------------------------------------**/
/** @defgroup ETH_MMC_Tx_Interrupts 
  * @{
  */ 
#define ETH_MMC_IT_TGF       ((uint32_t)0x00200000)  /*!< When Tx good frame counter reaches half the maximum value */
#define ETH_MMC_IT_TGFMSC    ((uint32_t)0x00008000)  /*!< When Tx good multi col counter reaches half the maximum value */
#define ETH_MMC_IT_TGFSC     ((uint32_t)0x00004000)  /*!< When Tx good single col counter reaches half the maximum value */

/** @defgroup ETH_MMC_Rx_Interrupts 
  * @{
  */
#define ETH_MMC_IT_RGUF      ((uint32_t)0x10020000)  /*!< When Rx good unicast frames counter reaches half the maximum value */
#define ETH_MMC_IT_RFAE      ((uint32_t)0x10000040)  /*!< When Rx alignment error counter reaches half the maximum value */
#define ETH_MMC_IT_RFCE      ((uint32_t)0x10000020)  /*!< When Rx crc error counter reaches half the maximum value */

/** @defgroup ETH_MMC_Registers 
  * @{
  */ 
#define ETH_MMCCR            ((uint32_t)0x00000100)  /*!< MMC CR register */
#define ETH_MMCRIR           ((uint32_t)0x00000104)  /*!< MMC RIR register */
#define ETH_MMCTIR           ((uint32_t)0x00000108)  /*!< MMC TIR register */
#define ETH_MMCRIMR          ((uint32_t)0x0000010C)  /*!< MMC RIMR register */
#define ETH_MMCTIMR          ((uint32_t)0x00000110)  /*!< MMC TIMR register */ 
#define ETH_MMCTGFSCCR       ((uint32_t)0x0000014C)  /*!< MMC TGFSCCR register */
#define ETH_MMCTGFMSCCR      ((uint32_t)0x00000150)  /*!< MMC TGFMSCCR register */ 
#define ETH_MMCTGFCR         ((uint32_t)0x00000168)  /*!< MMC TGFCR register */
#define ETH_MMCRFCECR        ((uint32_t)0x00000194)  /*!< MMC RFCECR register */
#define ETH_MMCRFAECR        ((uint32_t)0x00000198)  /*!< MMC RFAECR register */
#define ETH_MMCRGUFCR        ((uint32_t)0x000001C4)  /*!< MMC RGUFCR register */


/**--------------------------------------------------------------------------**/
/** 
  * @brief                           Ethernet PTP defines
  */ 
/**--------------------------------------------------------------------------**/
/** @defgroup ETH_PTP_time_update_method 
  * @{
  */ 
#define ETH_PTP_FineUpdate        ((uint32_t)0x00000001)  /*!< Fine Update method */
#define ETH_PTP_CoarseUpdate      ((uint32_t)0x00000000)  /*!< Coarse Update method */

/** @defgroup ETH_PTP_Flags 
  * @{
  */ 
#define ETH_PTP_FLAG_TSARU        ((uint32_t)0x00000020)  /*!< Addend Register Update */
#define ETH_PTP_FLAG_TSITE        ((uint32_t)0x00000010)  /*!< Time Stamp Interrupt Trigger */
#define ETH_PTP_FLAG_TSSTU        ((uint32_t)0x00000008)  /*!< Time Stamp Update */
#define ETH_PTP_FLAG_TSSTI        ((uint32_t)0x00000004)  /*!< Time Stamp Initialize */

#define ETH_PTP_FLAG_TSTTR        ((uint32_t)0x10000002)  /* Time stamp target time reached */
#define ETH_PTP_FLAG_TSSO         ((uint32_t)0x10000001)  /* Time stamp seconds overflow */

/** @defgroup ETH_PTP_time_sign 
  * @{
  */ 
#define ETH_PTP_PositiveTime      ((uint32_t)0x00000000)  /*!< Positive time value */
#define ETH_PTP_NegativeTime      ((uint32_t)0x80000000)  /*!< Negative time value */


/** 
  * @brief  ETH PTP registers  
  */ 
#define ETH_PTPTSCR     ((uint32_t)0x00000700)  /*!< PTP TSCR register */
#define ETH_PTPSSIR     ((uint32_t)0x00000704)  /*!< PTP SSIR register */
#define ETH_PTPTSHR     ((uint32_t)0x00000708)  /*!< PTP TSHR register */
#define ETH_PTPTSLR     ((uint32_t)0x0000070C)  /*!< PTP TSLR register */
#define ETH_PTPTSHUR    ((uint32_t)0x00000710)  /*!< PTP TSHUR register */
#define ETH_PTPTSLUR    ((uint32_t)0x00000714)  /*!< PTP TSLUR register */
#define ETH_PTPTSAR     ((uint32_t)0x00000718)  /*!< PTP TSAR register */
#define ETH_PTPTTHR     ((uint32_t)0x0000071C)  /*!< PTP TTHR register */
#define ETH_PTPTTLR     ((uint32_t)0x00000720)  /* PTP TTLR register */

#define ETH_PTPTSSR     ((uint32_t)0x00000728)  /* PTP TSSR register */


/** 
  * @brief  ETHERNET PTP clock  
  */ 
#define ETH_PTP_OrdinaryClock               ((uint32_t)0x00000000)  /* Ordinary Clock */
#define ETH_PTP_BoundaryClock               ((uint32_t)0x00010000)  /* Boundary Clock */
#define ETH_PTP_EndToEndTransparentClock    ((uint32_t)0x00020000)  /* End To End Transparent Clock */
#define ETH_PTP_PeerToPeerTransparentClock  ((uint32_t)0x00030000)  /* Peer To Peer Transparent Clock */

/** 
  * @brief  ETHERNET snapshot
  */
#define ETH_PTP_SnapshotMasterMessage          ((uint32_t)0x00008000)  /* Time stamp snapshot for message relevant to master enable */
#define ETH_PTP_SnapshotEventMessage           ((uint32_t)0x00004000)  /* Time stamp snapshot for event message enable */
#define ETH_PTP_SnapshotIPV4Frames             ((uint32_t)0x00002000)  /* Time stamp snapshot for IPv4 frames enable */
#define ETH_PTP_SnapshotIPV6Frames             ((uint32_t)0x00001000)  /* Time stamp snapshot for IPv6 frames enable */
#define ETH_PTP_SnapshotPTPOverEthernetFrames  ((uint32_t)0x00000800)  /* Time stamp snapshot for PTP over ethernet frames enable */
#define ETH_PTP_SnapshotAllReceivedFrames      ((uint32_t)0x00000100)  /* Time stamp snapshot for all received frames enable */


/* ETHERNET MAC address offsets */
#define ETH_MAC_ADDR_HBASE   (ETH_MAC_BASE + 0x40)  /* ETHERNET MAC address high offset */
#define ETH_MAC_ADDR_LBASE    (ETH_MAC_BASE + 0x44)  /* ETHERNET MAC address low offset */

/* ETHERNET MACMIIAR register Mask */
#define MACMIIAR_CR_MASK    ((uint32_t)0xFFFFFFE3)

/* ETHERNET MACCR register Mask */
#define MACCR_CLEAR_MASK    ((uint32_t)0xFF20810F)  

/* ETHERNET MACFCR register Mask */
#define MACFCR_CLEAR_MASK   ((uint32_t)0x0000FF41)


/* ETHERNET DMAOMR register Mask */
#define DMAOMR_CLEAR_MASK   ((uint32_t)0xF8DE3F23)


/* ETHERNET Remote Wake-up frame register length */
#define ETH_WAKEUP_REGISTER_LENGTH      8

/* ETHERNET Missed frames counter Shift */
#define  ETH_DMA_RX_OVERFLOW_MISSEDFRAMES_COUNTERSHIFT     17

/* ETHERNET DMA Tx descriptors Collision Count Shift */
#define  ETH_DMATXDESC_COLLISION_COUNTSHIFT        3

/* ETHERNET DMA Tx descriptors Buffer2 Size Shift */
#define  ETH_DMATXDESC_BUFFER2_SIZESHIFT           16

/* ETHERNET DMA Rx descriptors Frame Length Shift */
#define  ETH_DMARXDESC_FRAME_LENGTHSHIFT           16

/* ETHERNET DMA Rx descriptors Buffer2 Size Shift */
#define  ETH_DMARXDESC_BUFFER2_SIZESHIFT           16

/* ETHERNET errors */
#define  ETH_ERROR              ((uint32_t)0)
#define  ETH_SUCCESS            ((uint32_t)1)

/*********** Portions COPYRIGHT 2012 Embest Tech. Co., Ltd.*****END OF FILE****/




//*****************************************************************************
class cHwEthernet_MCU: public cHwEthernet
{
	public:
	  cHwEthernet_MCU( cHwPort::Pin &reset, const cNetAddr<6> &addrPhyIn );

  public:


    virtual void create( const cNetAddr<6> destAddr, const WORD type );


    virtual void     PacketSend   (uint8_t* packet, uint16_t len);
		virtual bool     PacketReceive();

    virtual WORD getType(  );

		
  private:
    void  low_level_init( void );
    int   low_level_output( BYTE *buff, DWORD length );
    DWORD low_level_input ( BYTE *ibuffer, DWORD maxLen);

__IO uint32_t  EthInitStatus;
__IO uint8_t EthLinkStatus;



/******************************************************************************/
/*                           Global ETH MAC/DMA functions                     */
/******************************************************************************/
/**
  * @brief  Initializes the ETHERNET peripheral according to the specified
  *   parameters in the ETH_InitStruct .
  * @param ETH_InitStruct: pointer to a ETH_InitTypeDef structure that contains
  *   the configuration information for the specified ETHERNET peripheral.
  * @param PHYAddress: external PHY address
  * @retval ETH_ERROR: Ethernet initialization failed
  *         ETH_SUCCESS: Ethernet successfully initialized
  */
uint32_t ETH_Init( uint16_t PHYAddress)
{
  uint32_t RegValue = 0, tmpreg = 0;
  __IO uint32_t i = 0;
  uint32_t hclk = system_PCLK;
  __IO uint32_t timeout = 0;

  /*-------------------------------- MAC Config ------------------------------*/
  /*---------------------- ETHERNET MACMIIAR Configuration -------------------*/
  /* Get the ETHERNET MACMIIAR value */
  tmpreg = ETH->MACMIIAR;
  /* Clear CSR Clock Range CR[2:0] bits */
  tmpreg &= MACMIIAR_CR_MASK;

  /* Set CR bits depending on hclk value */
  if((hclk >= 20000000)&&(hclk < 35000000))
  {
    /* CSR Clock Range between 20-35 MHz */
    tmpreg |= (uint32_t)ETH_MACMIIAR_CR_Div16;
  }
  else if((hclk >= 35000000)&&(hclk < 60000000))
  {
    /* CSR Clock Range between 35-60 MHz */
    tmpreg |= (uint32_t)ETH_MACMIIAR_CR_Div26;
  }
  else if((hclk >= 60000000)&&(hclk < 100000000))
  {
    /* CSR Clock Range between 60-100 MHz */
    tmpreg |= (uint32_t)ETH_MACMIIAR_CR_Div42;
  }
  else if((hclk >= 100000000)&&(hclk < 150000000))
  {
    /* CSR Clock Range between 100-150 MHz */
    tmpreg |= (uint32_t)ETH_MACMIIAR_CR_Div62;
  }
  else /* ((hclk >= 150000000)&&(hclk <= 168000000)) */
  {
    /* CSR Clock Range between 150-168 MHz */
    tmpreg |= (uint32_t)ETH_MACMIIAR_CR_Div102;
  }

  /* Write to ETHERNET MAC MIIAR: Configure the ETHERNET CSR Clock Range */
  ETH->MACMIIAR = (uint32_t)tmpreg;
  /*-------------------- PHY initialization and configuration ----------------*/
  /* Put the PHY in reset mode */
  if(!(ETH_WritePHYRegister(PHYAddress, PHY_BCR, PHY_Reset)))
  {
    /* Return ERROR in case of write timeout */
    return ETH_ERROR;
  }

  /* Delay to assure PHY reset */
  cSystem::delayMilliSec(10);

  if( ETH_AutoNegotiation )
  {
    /* We wait for linked status... */
    do
    {
      timeout++;
    } while (!(ETH_ReadPHYRegister(PHYAddress, PHY_BSR) & PHY_Linked_Status) && (timeout < PHY_READ_TO));

    /* Return ERROR in case of timeout */
    if(timeout == PHY_READ_TO)
    {
      return ETH_ERROR;
    }

    /* Reset Timeout counter */
    timeout = 0;
    /* Enable Auto-Negotiation */
    if(!(ETH_WritePHYRegister(PHYAddress, PHY_BCR, PHY_AutoNegotiation)))
    {
      /* Return ERROR in case of write timeout */
      return ETH_ERROR;
    }

    /* Wait until the auto-negotiation will be completed */
    do
    {
      timeout++;
    } while (!(ETH_ReadPHYRegister(PHYAddress, PHY_BSR) & PHY_AutoNego_Complete) && (timeout < (uint32_t)PHY_READ_TO));

    /* Return ERROR in case of timeout */
    if(timeout == PHY_READ_TO)
    {
      return ETH_ERROR;
    }

    /* Reset Timeout counter */
    timeout = 0;

    /* Read the result of the auto-negotiation */
    RegValue = ETH_ReadPHYRegister(PHYAddress, PHY_SR);

		switch (RegValue & PHY_DUPLEX_SPEED_STATUS_MASK)
		{
		  case PHY_100BTX_FULL:
			  ETH_Mode  = ETH_MACCR_DM; // full duplex mode
				ETH_Speed = ETH_MACCR_FES; // fast mode (100M) = true
			  break;

		  case PHY_100BTX_HALF:
			  ETH_Mode  = !ETH_MACCR_DM; // full duplex mode = false
				ETH_Speed = ETH_MACCR_FES; // fast mode (100M) = true
  			break;

		  case PHY_10M_FULL:
			  ETH_Mode  = ETH_MACCR_DM; // full duplex mode
				ETH_Speed = !ETH_MACCR_FES;// fast mode (100M) = false
			  break;

		  case PHY_10M_HALF:
			  ETH_Mode  = !ETH_MACCR_DM; // full duplex mode = false
				ETH_Speed = !ETH_MACCR_FES;// fast mode (100M) = false
			  break;

		  default:
			  break;
		}
  }
  else
  {
    if(!ETH_WritePHYRegister(PHYAddress, PHY_BCR, ((uint16_t)(ETH_Mode >> 3) |
                                                   (uint16_t)(ETH_Speed >> 1))))
    {
      /* Return ERROR in case of write timeout */
      return ETH_ERROR;
    }
    /* Delay to assure PHY configuration */
    cSystem::delayMilliSec(100);

  }
  /*------------------------ ETHERNET MACCR Configuration --------------------*/
  /* Get the ETHERNET MACCR value */
  tmpreg = ETH->MACCR;
  /* Clear WD, PCE, PS, TE and RE bits */
  tmpreg &= MACCR_CLEAR_MASK;
  
  tmpreg |= (uint32_t)(ETH_Watchdog |
                       ETH_Jabber |
                  ETH_InterFrameGap |
                  ETH_CarrierSense |
                  ETH_Speed |
                  ETH_ReceiveOwn |
                  ETH_LoopbackMode |
                  ETH_Mode |
                  ETH_ChecksumOffload |
                  ETH_RetryTransmission |
                  ETH_AutomaticPadCRCStrip |
                  ETH_BackOffLimit |
                  ETH_DeferralCheck);
  /* Write to ETHERNET MACCR */
  ETH->MACCR = (uint32_t)tmpreg;

  /*----------------------- ETHERNET MACFFR Configuration --------------------*/
  ETH->MACFFR = (uint32_t)(ETH_ReceiveAll |
                          ETH_SourceAddrFilter |
                          ETH_PassControlFrames |
                          ETH_BroadcastFramesReception |
                          ETH_DestinationAddrFilter |
                          ETH_PromiscuousMode |
                          ETH_MulticastFramesFilter |
                          ETH_UnicastFramesFilter);
  
  /*--------------- ETHERNET MACHTHR and MACHTLR Configuration ---------------*/
  /* Write to ETHERNET MACHTHR */
  ETH->MACHTHR = (uint32_t)ETH_HashTableHigh;
  
  /* Write to ETHERNET MACHTLR */
  ETH->MACHTLR = (uint32_t)ETH_HashTableLow;
  
  /*----------------------- ETHERNET MACFCR Configuration --------------------*/
  /* Get the ETHERNET MACFCR value */
  tmpreg = ETH->MACFCR;
  /* Clear xx bits */
  tmpreg &= MACFCR_CLEAR_MASK;

  tmpreg |= (uint32_t)((ETH_PauseTime << 16) |
                   ETH_ZeroQuantaPause |
                   ETH_PauseLowThreshold |
                   ETH_UnicastPauseFrameDetect |
                   ETH_ReceiveFlowControl |
                   ETH_TransmitFlowControl);
  /* Write to ETHERNET MACFCR */
  ETH->MACFCR = (uint32_t)tmpreg;
  
  /*----------------------- ETHERNET MACVLANTR Configuration -----------------*/
  /* Set the ETV bit according to ETH_VLANTagComparison value */
  /* Set the VL bit according to ETH_VLANTagIdentifier value */
  ETH->MACVLANTR = (uint32_t)(ETH_VLANTagComparison |
                             ETH_VLANTagIdentifier);

  /*-------------------------------- DMA Config ------------------------------*/
  /*----------------------- ETHERNET DMAOMR Configuration --------------------*/
  /* Get the ETHERNET DMAOMR value */
  tmpreg = ETH->DMAOMR;
  /* Clear xx bits */
  tmpreg &= DMAOMR_CLEAR_MASK;

  /* Set the DT bit according to ETH_DropTCPIPChecksumErrorFrame value */
  /* Set the RSF bit according to ETH_ReceiveStoreForward value */
  /* Set the DFF bit according to ETH_FlushReceivedFrame value */
  /* Set the TSF bit according to ETH_TransmitStoreForward value */
  /* Set the TTC bit according to ETH_TransmitThresholdControl value */
  /* Set the FEF bit according to ETH_ForwardErrorFrames value */
  /* Set the FUF bit according to ETH_ForwardUndersizedGoodFrames value */
  /* Set the RTC bit according to ETH_ReceiveThresholdControl value */
  /* Set the OSF bit according to ETH_SecondFrameOperate value */
  tmpreg |= (uint32_t)(ETH_DropTCPIPChecksumErrorFrame |
                  ETH_ReceiveStoreForward |
                  ETH_FlushReceivedFrame |
                  ETH_TransmitStoreForward |
                  ETH_TransmitThresholdControl |
                  ETH_ForwardErrorFrames |
                  ETH_ForwardUndersizedGoodFrames |
                  ETH_ReceiveThresholdControl |
                  ETH_SecondFrameOperate);
  /* Write to ETHERNET DMAOMR */
  ETH->DMAOMR = (uint32_t)tmpreg;

  /*----------------------- ETHERNET DMABMR Configuration --------------------*/
  ETH->DMABMR = (uint32_t)(ETH_AddressAlignedBeats |
                          ETH_FixedBurst |
                          ETH_RxDMABurstLength | /* !! if 4xPBL is selected for Tx or Rx it is applied for the other */
                          ETH_TxDMABurstLength |
                         (ETH_DescriptorSkipLength << 2) |
                          ETH_DMAArbitration |
                          ETH_DMABMR_USP); /* Enable use of separate PBL for Rx and Tx */

  #ifdef USE_ENHANCED_DMA_DESCRIPTORS
    /* Enable the Enhanced DMA descriptors */
    ETH->DMABMR |= ETH_DMABMR_EDE;
  #endif /* USE_ENHANCED_DMA_DESCRIPTORS */

  /* Return Ethernet configuration success */
  return ETH_SUCCESS;
}

/**
  * @brief  Enables ENET MAC and DMA reception/transmission
  * @param  None
  * @retval None
  */
void ETH_Start(void)
{
  /* Enable transmit state machine of the MAC for transmission on the MII */
  ETH->MACCR |= ETH_MACCR_TE;
  
  /* Flush Transmit FIFO */
  /* Set the Flush Transmit FIFO bit */
  ETH->DMAOMR |= ETH_DMAOMR_FTF;
  
  /* Enable receive state machine of the MAC for reception from the MII */
  ETH->MACCR |= ETH_MACCR_RE;

  /* Start DMA transmission */
  /* Enable the DMA transmission */
    ETH->DMAOMR |= ETH_DMAOMR_ST;
  
  /* Start DMA reception */
/* Enable the DMA reception */
    ETH->DMAOMR |= ETH_DMAOMR_SR;
}

/**
  * @brief  Configures the selected MAC address.
  * @param  MacAddr: The MAC address to configure.
  *   This parameter can be one of the following values:
  *     @arg ETH_MAC_Address0 : MAC Address0
  *     @arg ETH_MAC_Address1 : MAC Address1
  *     @arg ETH_MAC_Address2 : MAC Address2
  *     @arg ETH_MAC_Address3 : MAC Address3
  * @param  Addr: Pointer on MAC address buffer data (6 bytes).
  * @retval None
  */
void ETH_MACAddressConfig(uint32_t MacAddr, uint8_t *Addr)
{
  uint32_t tmpreg;

  /* Calculate the selected MAC address high register */
  tmpreg = ((uint32_t)Addr[5] << 8) | (uint32_t)Addr[4];
  /* Load the selected MAC address high register */
  (*(__IO uint32_t *) (ETH_MAC_ADDR_HBASE + MacAddr)) = tmpreg;
  /* Calculate the selected MAC address low register */
  tmpreg = ((uint32_t)Addr[3] << 24) | ((uint32_t)Addr[2] << 16) | ((uint32_t)Addr[1] << 8) | Addr[0];

  /* Load the selected MAC address low register */
  (*(__IO uint32_t *) (ETH_MAC_ADDR_LBASE + MacAddr)) = tmpreg;
}



/******************************************************************************/
/*                           DMA Descriptors functions                        */
/******************************************************************************/

/**
  * @brief  This function should be called to get the received frame (to be used
  * with polling method only).
  * @param  none
  * @retval Structure of type FrameTypeDef
  */
FrameTypeDef ETH_Get_Received_Frame(void);

/**
  * @brief  Prepares DMA Tx descriptors to transmit an ethernet frame
  * @param  FrameLength : length of the frame to send
  * @retval error status
  */
uint32_t ETH_Prepare_Transmit_Descriptors(uint16_t FrameLength);


/**
  * @brief  Initializes the DMA Rx descriptors in chain mode.
  * @param  DMARxDescTab: Pointer on the first Rx desc list
  * @param  RxBuff: Pointer on the first RxBuffer list
  * @param  RxBuffCount: Number of the used Rx desc in the list
  * @retval None
  */
void ETH_DMARxDescChainInit(ETH_DMADESCTypeDef *DMARxDescTab, uint8_t *RxBuff, uint32_t RxBuffCount);

/**
  * @brief  This function polls for a frame reception
  * @param  None
  * @retval Returns 1 when a frame is received, 0 if none.
  */
uint32_t ETH_CheckFrameReceived(void);

/**
  * @brief  Initializes the DMA Tx descriptors in chain mode.
  * @param  DMATxDescTab: Pointer on the first Tx desc list
  * @param  TxBuff: Pointer on the first TxBuffer list
  * @param  TxBuffCount: Number of the used Tx desc in the list
  * @retval None
  */
void ETH_DMATxDescChainInit(ETH_DMADESCTypeDef *DMATxDescTab, uint8_t* TxBuff, uint32_t TxBuffCount);

/******************************************************************************/
/*                                PHY functions                               */
/******************************************************************************/

/**
  * @brief  Read a PHY register
  * @param PHYAddress: PHY device address, is the index of one of supported 32 PHY devices.
  *   This parameter can be one of the following values: 0,..,31
  * @param PHYReg: PHY register address, is the index of one of the 32 PHY register.
  *   This parameter can be one of the following values:
  *     @arg PHY_BCR: Transceiver Basic Control Register
  *     @arg PHY_BSR: Transceiver Basic Status Register
  *     @arg PHY_SR : Transceiver Status Register
  *     @arg More PHY register could be read depending on the used PHY
  * @retval ETH_ERROR: in case of timeout
  *         MAC MIIDR register value: Data read from the selected PHY register (correct read )
  */
uint16_t ETH_ReadPHYRegister(uint16_t PHYAddress, uint16_t PHYReg)
{
  uint32_t tmpreg = 0;
__IO uint32_t timeout = 0;

  /* Get the ETHERNET MACMIIAR value */
  tmpreg = ETH->MACMIIAR;
  /* Keep only the CSR Clock Range CR[2:0] bits value */
  tmpreg &= ~MACMIIAR_CR_MASK;
  /* Prepare the MII address register value */
  tmpreg |=(((uint32_t)PHYAddress<<11) & ETH_MACMIIAR_PA); /* Set the PHY device address */
  tmpreg |=(((uint32_t)PHYReg<<6) & ETH_MACMIIAR_MR);      /* Set the PHY register address */
  tmpreg &= ~ETH_MACMIIAR_MW;                              /* Set the read mode */
  tmpreg |= ETH_MACMIIAR_MB;                               /* Set the MII Busy bit */
  /* Write the result value into the MII Address register */
  ETH->MACMIIAR = tmpreg;
  /* Check for the Busy flag */
  do
  {
    timeout++;
    tmpreg = ETH->MACMIIAR;
  } while ((tmpreg & ETH_MACMIIAR_MB) && (timeout < (uint32_t)PHY_READ_TO));
  /* Return ERROR in case of timeout */
  if(timeout == PHY_READ_TO)
  {
    return (uint16_t)ETH_ERROR;
  }

  /* Return data register value */
  return (uint16_t)(ETH->MACMIIDR);
}

/**
  * @brief  Write to a PHY register
  * @param PHYAddress: PHY device address, is the index of one of supported 32 PHY devices.
  *   This parameter can be one of the following values: 0,..,31
  * @param PHYReg: PHY register address, is the index of one of the 32 PHY register.
  *   This parameter can be one of the following values:
  *     @arg PHY_BCR    : Transceiver Control Register
  *     @arg More PHY register could be written depending on the used PHY
  * @param  PHYValue: the value to write
  * @retval ETH_ERROR: in case of timeout
  *         ETH_SUCCESS: for correct write
  */
uint32_t ETH_WritePHYRegister(uint16_t PHYAddress, uint16_t PHYReg, uint16_t PHYValue)
{
  uint32_t tmpreg = 0;
  __IO uint32_t timeout = 0;

  /* Get the ETHERNET MACMIIAR value */
  tmpreg = ETH->MACMIIAR;
  /* Keep only the CSR Clock Range CR[2:0] bits value */
  tmpreg &= ~MACMIIAR_CR_MASK;
  /* Prepare the MII register address value */
  tmpreg |=(((uint32_t)PHYAddress<<11) & ETH_MACMIIAR_PA); /* Set the PHY device address */
  tmpreg |=(((uint32_t)PHYReg<<6) & ETH_MACMIIAR_MR);      /* Set the PHY register address */
  tmpreg |= ETH_MACMIIAR_MW;                               /* Set the write mode */
  tmpreg |= ETH_MACMIIAR_MB;                               /* Set the MII Busy bit */
  /* Give the value to the MII data register */
  ETH->MACMIIDR = PHYValue;
  /* Write the result value into the MII Address register */
  ETH->MACMIIAR = tmpreg;
  /* Check for the Busy flag */
  do
  {
    timeout++;
    tmpreg = ETH->MACMIIAR;
  } while ((tmpreg & ETH_MACMIIAR_MB) && (timeout < (uint32_t)PHY_WRITE_TO));
  /* Return ERROR in case of timeout */
  if(timeout == PHY_WRITE_TO)
  {
    return ETH_ERROR;
  }

  /* Return SUCCESS */
  return ETH_SUCCESS;
}

//###################################################################  
  
  bool     ETH_AutoNegotiation;
  uint32_t ETH_Watchdog;
  uint32_t ETH_Jabber;
  uint32_t ETH_InterFrameGap;
  uint32_t ETH_CarrierSense;
  uint32_t ETH_Speed;
  uint32_t ETH_ReceiveOwn;
  uint32_t ETH_LoopbackMode;
  uint32_t ETH_Mode;
  uint32_t ETH_ChecksumOffload;
  uint32_t ETH_RetryTransmission;
  uint32_t ETH_AutomaticPadCRCStrip;
  uint32_t ETH_BackOffLimit;
  uint32_t ETH_DeferralCheck;
  uint32_t ETH_ReceiveAll;
  uint32_t ETH_SourceAddrFilter;
  uint32_t ETH_PassControlFrames;
  uint32_t ETH_BroadcastFramesReception;
  uint32_t ETH_DestinationAddrFilter;
  uint32_t ETH_PromiscuousMode;
  uint32_t ETH_MulticastFramesFilter;
  uint32_t ETH_UnicastFramesFilter;
  uint32_t ETH_HashTableHigh;
  uint32_t ETH_HashTableLow;
  uint32_t ETH_PauseTime;
  uint32_t ETH_ZeroQuantaPause;
  uint32_t ETH_PauseLowThreshold;
  uint32_t ETH_UnicastPauseFrameDetect;
  uint32_t ETH_ReceiveFlowControl;
  uint32_t ETH_TransmitFlowControl;
  uint32_t ETH_VLANTagComparison;
  uint32_t ETH_VLANTagIdentifier;
  uint32_t ETH_DropTCPIPChecksumErrorFrame;
  uint32_t ETH_ReceiveStoreForward;
  uint32_t ETH_FlushReceivedFrame;
  uint32_t ETH_TransmitStoreForward;
  uint32_t ETH_TransmitThresholdControl;
  uint32_t ETH_ForwardErrorFrames;
  uint32_t ETH_ForwardUndersizedGoodFrames;
  uint32_t ETH_ReceiveThresholdControl;
  uint32_t ETH_SecondFrameOperate;
  uint32_t ETH_AddressAlignedBeats;
  uint32_t ETH_FixedBurst;
  uint32_t ETH_RxDMABurstLength;
  uint32_t ETH_TxDMABurstLength;
  uint32_t ETH_DescriptorSkipLength;
  uint32_t ETH_DMAArbitration;

};
#endif

