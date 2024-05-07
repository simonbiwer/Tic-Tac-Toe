//*******************************************************************
/*!
\file   PinConfig.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   07.09.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_PIN_CONFIG_H
#define _HW_PIN_CONFIG_H

//*******************************************************************
/*!
\class cHwPinConfig

\brief Port pin configuration

This class provides methods to
- configure GPIO mode, type, pull-up/-down, speed and alternate 
  function
- connect a GPIO to an alternate function


*/
class cHwPinConfig
{
  public:
    //---------------------------------------------------------------
    /*! Pin mode configuration
    */
    typedef enum
    {
      PU     = 0x00, //!< Pull up resistor enable
      RM     = 0x01, //!< Repeater mode
      NOPUPD = 0x02, //!< No pull up/pull down
      PD     = 0x03, //!< Pull down resistor enable
      NOD    = 0x00, //!< No open drain
      OD     = 0x10  //!< Open drain enable
    } MODE;

    //---------------------------------------------------------------
    /*! Alternate functions of the MCU
    */
    typedef enum
    {
      AD0_0,
      AD0_1,
      AD0_2,
      AD0_3,
      AD0_4,
      AD0_5,
      AD0_6,
      AD0_7,
      AOUT,
      ENET_CRS,
      ENET_MDC,
      ENET_MDIO,
      ENET_REF_CLK,
      ENET_RX_ER,
      ENET_RXD0,
      ENET_RXD1,
      ENET_TX_EN,
      ENET_TXD0,
      ENET_TXD1,
      MISO,
      MISO0,
      MISO1,
      MOSI,
      MOSI0,
      MOSI1,
      PWM1_1,
      PWM1_2,
      PWM1_3,
      PWM1_4,
      PWM1_5,
      PWM1_6,
      RXD0,
      RXD1,
      RXD2,
      RXD3,
      SCK,
      SCK0,
      SCK1,
      SCL1,
      SCL2,
      SDA1,
      SDA2,
      SSEL,
      SSEL0,
      SSEL1,
      TXD0,
      TXD1,
      TXD2,
      TXD3,
      USB_CONNECT,
      USB_Dm,
      USB_Dp,
      USB_PPWR,
      USB_PWRD,
      USB_UP_LED,
      VBUS,
    } Function;

    //---------------------------------------------------------------
    /*! Pin function mapping
        
        Maps an alternate function to a port pin and alternate function ID.
       'ADC12_IN4_PA_4' means: The function 'ADC12_IN4' is mapped to pin PA4
    */
    typedef enum
    {
      AD0_0_P0_23        = (AD0_0       <<16)|(0<<12)|(23<<4)|(1<<0),  //!< Not available on 80-pin package.
      AD0_1_P0_24        = (AD0_1       <<16)|(0<<12)|(24<<4)|(1<<0),  //!< Not available on 80-pin package.
      AD0_2_P0_25        = (AD0_2       <<16)|(0<<12)|(25<<4)|(1<<0),  //!< .
      AD0_3_P0_26        = (AD0_3       <<16)|(0<<12)|(26<<4)|(1<<0),  //!< .
      AD0_4_P1_30        = (AD0_4       <<16)|(1<<12)|(30<<4)|(3<<0),  //!< .
      AD0_5_P1_31        = (AD0_5       <<16)|(1<<12)|(31<<4)|(3<<0),  //!< .
      AD0_6_P0_3         = (AD0_6       <<16)|(0<<12)|( 3<<4)|(2<<0),  //!< .
      AD0_7_P0_2         = (AD0_7       <<16)|(0<<12)|( 2<<4)|(2<<0),  //!< .
      AOUT_P0_26         = (AOUT        <<16)|(0<<12)|(26<<4)|(2<<0),  //!< .
      ENET_CRS_P1_8      = (ENET_CRS    <<16)|(1<<12)|( 8<<4)|(1<<0),  //!< .
      ENET_MDC_P2_8      = (ENET_MDC    <<16)|(2<<12)|( 8<<4)|(3<<0),  //!< .
      ENET_MDIO_P2_9     = (ENET_MDIO   <<16)|(2<<12)|( 9<<4)|(3<<0),  //!< .
      ENET_REF_CLK_P1_15 = (ENET_REF_CLK<<16)|(1<<12)|(15<<4)|(1<<0),  //!< .
      ENET_RX_ER_P1_14   = (ENET_RX_ER  <<16)|(1<<12)|(14<<4)|(1<<0),  //!< .
      ENET_RXD0_P1_9     = (ENET_RXD0   <<16)|(1<<12)|( 9<<4)|(1<<0),  //!< .
      ENET_RXD1_P1_10    = (ENET_RXD1   <<16)|(1<<12)|(10<<4)|(1<<0),  //!< .
      ENET_TX_EN_P1_4    = (ENET_TX_EN  <<16)|(1<<12)|( 4<<4)|(1<<0),  //!< .
      ENET_TXD0_P1_0     = (ENET_TXD0   <<16)|(1<<12)|( 0<<4)|(1<<0),  //!< .
      ENET_TXD1_P1_1     = (ENET_TXD1   <<16)|(1<<12)|( 1<<4)|(1<<0),  //!< .
      MISO_P0_17         = (MISO        <<16)|(0<<12)|(17<<4)|(3<<0),  //!< .
      MISO0_P0_17        = (MISO0       <<16)|(0<<12)|(17<<4)|(2<<0),  //!< .
      MISO0_P1_23        = (MISO0       <<16)|(1<<12)|(23<<4)|(3<<0),  //!< .
      MISO1_P0_8         = (MISO1       <<16)|(0<<12)|( 8<<4)|(2<<0),  //!< .
      MOSI_P0_18         = (MOSI        <<16)|(0<<12)|(18<<4)|(3<<0),  //!< .
      MOSI0_P0_18        = (MOSI0       <<16)|(0<<12)|(18<<4)|(2<<0),  //!< .
      MOSI0_P1_24        = (MOSI0       <<16)|(1<<12)|(24<<4)|(3<<0),  //!< .
      MOSI1_P0_9         = (MOSI1       <<16)|(0<<12)|( 9<<4)|(2<<0),  //!< .
      PWM1_1_P2_0        = (PWM1_1      <<16)|(2<<12)|( 0<<4)|(1<<0),  //!< .
      PWM1_1_P1_18       = (PWM1_1      <<16)|(1<<12)|(18<<4)|(2<<0),  //!< .
      PWM1_2_P2_1        = (PWM1_2      <<16)|(2<<12)|( 1<<4)|(1<<0),  //!< .
      PWM1_2_P1_20       = (PWM1_2      <<16)|(1<<12)|(20<<4)|(2<<0),  //!< .
      PWM1_3_P2_2        = (PWM1_3      <<16)|(2<<12)|( 2<<4)|(1<<0),  //!< .
      PWM1_4_P2_3        = (PWM1_4      <<16)|(2<<12)|( 3<<4)|(1<<0),  //!< .
      PWM1_4_P1_23       = (PWM1_4      <<16)|(1<<12)|(23<<4)|(2<<0),  //!< .
      PWM1_5_P2_4        = (PWM1_5      <<16)|(2<<12)|( 4<<4)|(1<<0),  //!< .
      PWM1_5_P1_24       = (PWM1_5      <<16)|(1<<12)|(24<<4)|(2<<0),  //!< .
      PWM1_6_P2_5        = (PWM1_6      <<16)|(2<<12)|( 5<<4)|(1<<0),  //!< .
      PWM1_6_P1_26       = (PWM1_6      <<16)|(1<<12)|(26<<4)|(2<<0),  //!< .
      RXD0_P0_3          = (RXD0        <<16)|(0<<12)|( 3<<4)|(1<<0),  //!< .
      RXD1_P0_16         = (RXD1        <<16)|(0<<12)|(16<<4)|(1<<0),  //!< .
      RXD1_P2_1          = (RXD1        <<16)|(2<<12)|( 1<<4)|(2<<0),  //!< .
      RXD2_P0_11         = (RXD2        <<16)|(0<<12)|(11<<4)|(1<<0),  //!< .
      RXD2_P2_9          = (RXD2        <<16)|(2<<12)|( 9<<4)|(2<<0),  //!< .
      RXD3_P0_1          = (RXD3        <<16)|(0<<12)|( 1<<4)|(2<<0),  //!< .
      RXD3_P0_26         = (RXD3        <<16)|(0<<12)|(26<<4)|(3<<0),  //!< .
      RXD3_P4_29         = (RXD3        <<16)|(4<<12)|(29<<4)|(3<<0),  //!< .
      SCK_P0_15          = (SCK         <<16)|(0<<12)|(15<<4)|(3<<0),  //!< .
      SCK0_P0_15         = (SCK0        <<16)|(0<<12)|(15<<4)|(2<<0),  //!< .
      SCK0_P1_20         = (SCK0        <<16)|(1<<12)|(20<<4)|(3<<0),  //!< .
      SCK1_P0_7          = (SCK1        <<16)|(0<<12)|( 7<<4)|(2<<0),  //!< .
      SCK1_P1_31         = (SCK1        <<16)|(1<<12)|(31<<4)|(2<<0),  //!< .
      SCL1_P0_1          = (SCL1        <<16)|(0<<12)|( 1<<4)|(3<<0),  //!< .
      SCL2_P0_11         = (SCL2        <<16)|(0<<12)|(11<<4)|(2<<0),  //!< .
      SDA1_P0_0          = (SDA1        <<16)|(0<<12)|( 0<<4)|(3<<0),  //!< .
      SDA2_P0_10         = (SDA2        <<16)|(0<<12)|(10<<4)|(2<<0),  //!< .
          SSEL_P0_16 = (SSEL<<16)|(0<<12)|(16<<4)|(3<<0),  //!< .
          SSEL0_P0_16 = (SSEL0<<16)|(0<<12)|(16<<4)|(2<<0),  //!< .
          SSEL1_P0_6 = (SSEL1<<16)|(0<<12)|(6<<4)|(2<<0),  //!< .
      TXD0_P0_2          = (TXD0        <<16)|(0<<12)|( 2<<4)|(1<<0),  //!< .
      TXD1_P0_15         = (TXD1        <<16)|(0<<12)|(15<<4)|(1<<0),  //!< .
      TXD1_P2_0          = (TXD1        <<16)|(2<<12)|( 0<<4)|(2<<0),  //!< .
      TXD2_P0_10         = (TXD2        <<16)|(0<<12)|(10<<4)|(1<<0),  //!< .
      TXD2_P2_8          = (TXD2        <<16)|(2<<12)|( 8<<4)|(2<<0),  //!< .
      TXD3_P0_0          = (TXD3        <<16)|(0<<12)|( 0<<4)|(2<<0),  //!< .
      TXD3_P0_25         = (TXD3        <<16)|(0<<12)|(25<<4)|(3<<0),  //!< .
      TXD3_P4_28         = (TXD3        <<16)|(4<<12)|(28<<4)|(3<<0),  //!< .
      USB_CONNECT_P2_9   = (USB_CONNECT <<16)|(2<<12)|( 9<<4)|(1<<0),  //!< .
      USB_Dm_P0_30       = (USB_Dm      <<16)|(0<<12)|(30<<4)|(1<<0),  //!< .
      USB_Dp_P0_29       = (USB_Dp      <<16)|(0<<12)|(29<<4)|(1<<0),  //!< .
      USB_PPWR_P1_19     = (USB_PPWR    <<16)|(1<<12)|(19<<4)|(2<<0),  //!< .
      USB_PWRD_P1_22     = (USB_PWRD    <<16)|(1<<12)|(22<<4)|(2<<0),  //!< .
      USB_UP_LED_P1_18   = (USB_UP_LED  <<16)|(1<<12)|(18<<4)|(1<<0),  //!< .
      VBUS_P1_30         = (VBUS        <<16)|(1<<12)|(30<<4)|(2<<0),  //!< .
      END_OF_TABLE = 0
    } MAP;

  public:
    //---------------------------------------------------------------
    /*! Set PINSEL, PINMODE and PINMODE_OD
        This function uses \b table[]
    */
    static void set( Function func,    //!< Alternate function
                     DWORD    mode = 0 //!< PINMODE (optional) 
                   );

  public:
    //---------------------------------------------------------------
    /*! This table defines how a alternate function is mapped to the 
        port pins. It must be filled within the application software
    */
    static MAP table[];

}; //cHwPinConfig

#endif
