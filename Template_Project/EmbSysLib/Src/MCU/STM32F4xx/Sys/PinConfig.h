//*******************************************************************
/*!
\file   PinConfig.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

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
      // MODER
      INPUT          = 0x0000, //!< Input mode
      OUTPUT         = 0x0001, //!< Output mode
      ALTERNATE_FUNC = 0x0002, //!< Alternate function
      ANALOG         = 0x0003, //!< Analog I/O
      
      // OTYPER
      PUSH_PULL      = 0x0000, //!< Enable push-pull
      OPEN_DRAIN     = 0x0010, //!< Disable push-pull
      
      //PUPDR
      NO_PUPD        = 0x0000, //!< No pull-up or pull down 
      PULL_UP        = 0x0100, //!< Enable pull-up
      PULL_DOWN      = 0x0200, //!< Enable pull-down

      //OSPEEDR
      LOW_SPEED      = 0x0000, //!< Low speed mode
      MEDIUM_SPEED   = 0x1000, //!< Medium speed mode
      FAST_SPEED     = 0x2000, //!< Fast speed mode
      HIGH_SPEED     = 0x3000  //!< High speed mode
      
    } MODE;

    //---------------------------------------------------------------
    /*! Alternate functions of the MCU
    */
    typedef enum
    {
      ADC12_IN4,
      ADC12_IN5,
      ADC12_IN6,
      ADC12_IN7,
      ADC12_IN8,
      ADC12_IN9,
      ADC12_IN14,
      ADC12_IN15,
      ADC123_IN0,
      ADC123_IN1,
      ADC123_IN2,
      ADC123_IN3,
      ADC123_IN10,
      ADC123_IN11,
      ADC123_IN12,
      ADC123_IN13,
      ADC3_IN4  = ADC12_IN4,
      ADC3_IN5  = ADC12_IN5,
      ADC3_IN6  = ADC12_IN6,
      ADC3_IN7  = ADC12_IN7,
      ADC3_IN8  = ADC12_IN8,
      ADC3_IN9  = ADC12_IN9,
      ADC3_IN14 = ADC12_IN14,
      ADC3_IN15 = ADC12_IN15,
      CAN1_RX,
      CAN1_TX,
      CAN2_RX,
      CAN2_TX,
      DAC1_OUT,
      DAC2_OUT,
      ETH_MDC,
      ETH_MDIO,
      ETH_MII_COL,
      ETH_MII_CRS,
      ETH_MII_RX_CLK,
      ETH_MII_RX_DV,
      ETH_MII_RX_ER,
      ETH_MII_RXD0,
      ETH_MII_RXD1,
      ETH_MII_RXD2,
      ETH_MII_RXD3,
      ETH_MII_TX_CLK,
      ETH_MII_TX_EN,
      ETH_MII_TXD0,
      ETH_MII_TXD1,
      ETH_MII_TXD2,
      ETH_MII_TXD3,
      ETH_PPS_OUT,
      ETH_RMII_CRS_DV,
      ETH_RMII_RXD0,
      ETH_RMII_TX_EN,
      ETH_RMII_TXD0,
      ETH_RMII_TXD1,
      FSMC_A0,
      FSMC_A1,
      FSMC_A10,
      FSMC_A11,
      FSMC_A12,
      FSMC_A13,
      FSMC_A14,
      FSMC_A15,
      FSMC_A16,
      FSMC_A17,
      FSMC_A18,
      FSMC_A19,
      FSMC_A2,
      FSMC_A20,
      FSMC_A21,
      FSMC_A22,
      FSMC_A23,
      FSMC_A24,
      FSMC_A25,
      FSMC_A3,
      FSMC_A4,
      FSMC_A5,
      FSMC_A6,
      FSMC_A7,
      FSMC_A8,
      FSMC_A9,
      FSMC_BLN1,
      FSMC_CD,
      FSMC_CLK,
      FSMC_D0,
      FSMC_D1,
      FSMC_D10,
      FSMC_D11,
      FSMC_D12,
      FSMC_D13,
      FSMC_D14,
      FSMC_D15,
      FSMC_D2,
      FSMC_D3,
      FSMC_D4,
      FSMC_D5,
      FSMC_D6,
      FSMC_D7,
      FSMC_D8,
      FSMC_D9,
      FSMC_INT2,
      FSMC_INT3,
      FSMC_INTR,
      FSMC_NBL0,
      FSMC_NCE2,
      FSMC_NCE3,
      FSMC_NCE4_1,
      FSMC_NCE4_2,
      FSMC_NE1,
      FSMC_NE2,
      FSMC_NE3,
      FSMC_NE4,
      FSMC_NIORD,
      FSMC_NIOWR,
      FSMC_NL,
      FSMC_NOE,
      FSMC_NREG,
      FSMC_NWAIT,
      FSMC_NWE,
      I2C1_SCL,
      I2C1_SDA,
      I2C1_SMBA,
      I2C2_SCL,
      I2C2_SDA,
      I2C2_SMBA,
      I2C3_SCL,
      I2C3_SDA,
      I2C3_SMBA,
      I2S_CKIN,
      I2S2_CK,
      I2S2_MCK,
      I2S2_SD,
      I2S2_WS,
      I2S2ext_SD,
      I2S3_CK,
      I2S3_MCK,
      I2S3_SD,
      I2S3_WS,
      I2S3ext_SD,
      I2S3S_CK,
      I2S3S_WS,
      OTG_FS_DM,
      OTG_FS_DP,
      OTG_FS_ID,
      OTG_FS_SOF,
      OTG_HS_DM,
      OTG_HS_DP,
      OTG_HS_ID,
      OTG_HS_SOF,
      OTG_HS_ULPI_CK,
      OTG_HS_ULPI_D0,
      OTG_HS_ULPI_D1,
      OTG_HS_ULPI_D2,
      OTG_HS_ULPI_D3,
      OTG_HS_ULPI_D4,
      OTG_HS_ULPI_D5,
      OTG_HS_ULPI_D6,
      OTG_HS_ULPI_D7,
      OTG_HS_ULPI_DIR,
      OTG_HS_ULPI_NXT,
      OTG_HS_ULPI_STP,
      SDIO_CK,
      SDIO_CMD,
      SDIO_D0,
      SDIO_D1,
      SDIO_D2,
      SDIO_D3,
      SDIO_D4,
      SDIO_D5,
      SDIO_D6,
      SDIO_D7,
      SPI1_MISO,
      SPI1_MOSI,
      SPI1_NSS,
      SPI1_SCK,
      SPI2_MISO,
      SPI2_MOSI,
      SPI2_NSS,
      SPI2_SCK,
      SPI3_MISO,
      SPI3_MOSI,
      SPI3_NSS,
      SPI3_SCK,
      TIM1_BKIN,
      TIM1_CH1,
      TIM1_CH1N = TIM1_CH1,
      TIM1_CH2,
      TIM1_CH2N = TIM1_CH2,
      TIM1_CH3,
      TIM1_CH3N = TIM1_CH3,
      TIM1_CH4,
      TIM1_ETR,
      TIM10_CH1,
      TIM11_CH1,
      TIM12_CH1,
      TIM12_CH2,
      TIM13_CH1,
      TIM14_CH1,
      TIM2_CH1,
      TIM2_CH2,
      TIM2_CH3,
      TIM2_CH4,
      TIM2_ETR,
      TIM3_CH1,
      TIM3_CH2,
      TIM3_CH3,
      TIM3_CH4,
      TIM3_ETR,
      TIM4_CH1,
      TIM4_CH2,
      TIM4_CH3,
      TIM4_CH4,
      TIM4_ETR,
      TIM5_CH1,
      TIM5_CH2,
      TIM5_CH3,
      TIM5_CH4,
      TIM8_BKIN,
      TIM8_CH1,
      TIM8_CH1N = TIM8_CH1,
      TIM8_CH2,
      TIM8_CH2N = TIM8_CH2,
      TIM8_CH3,
      TIM8_CH3N = TIM8_CH3,
      TIM8_CH4,
      TIM8_ETR,
      TIM9_CH1,
      TIM9_CH2,
      UART4_RX,
      UART4_TX,
      UART5_RX,
      UART5_TX,
      UART6_CTS,
      USART1_CK,
      USART1_CTS,
      USART1_RTS,
      USART1_RX,
      USART1_TX,
      USART2_CK,
      USART2_CTS,
      USART2_RTS,
      USART2_RX,
      USART2_TX,
      USART3_CK,
      USART3_CTS,
      USART3_RTS,
      USART3_RX,
      USART3_TX,
      USART6_CK,
      USART6_CTS,
      USART6_RTS,
      USART6_RX,
      USART6_TX,
    } Function;

    //---------------------------------------------------------------
    /*! Pin function mapping
        
        Maps an alternate function to a port pin and alternate function ID.
       'ADC12_IN4_PA_4' means: The function 'ADC12_IN4' is mapped to pin PA4
    */
    typedef enum
    {
      // Key                  Function              Port     Pin     AF      
      ADC12_IN4_PA_4       = (ADC12_IN4      <<16)|(0<<12)|( 4<<4)|( 0<<0),  //!< .
      ADC12_IN5_PA_5       = (ADC12_IN5      <<16)|(0<<12)|( 5<<4)|( 0<<0),  //!< .
      ADC12_IN6_PA_6       = (ADC12_IN6      <<16)|(0<<12)|( 6<<4)|( 0<<0),  //!< .
      ADC12_IN7_PA_7       = (ADC12_IN7      <<16)|(0<<12)|( 7<<4)|( 0<<0),  //!< .
      ADC12_IN8_PB_0       = (ADC12_IN8      <<16)|(1<<12)|( 0<<4)|( 0<<0),  //!< .
      ADC12_IN9_PB_1       = (ADC12_IN9      <<16)|(1<<12)|( 1<<4)|( 0<<0),  //!< .
      ADC12_IN14_PC_4      = (ADC12_IN14     <<16)|(2<<12)|( 4<<4)|( 0<<0),  //!< .
      ADC12_IN15_PC_5      = (ADC12_IN15     <<16)|(2<<12)|( 5<<4)|( 0<<0),  //!< .
      ADC123_IN0_PA_0      = (ADC123_IN0     <<16)|(0<<12)|( 0<<4)|( 0<<0),  //!< .
      ADC123_IN1_PA_1      = (ADC123_IN1     <<16)|(0<<12)|( 1<<4)|( 0<<0),  //!< .
      ADC123_IN2_PA_2      = (ADC123_IN2     <<16)|(0<<12)|( 2<<4)|( 0<<0),  //!< .
      ADC123_IN3_PA_3      = (ADC123_IN3     <<16)|(0<<12)|( 3<<4)|( 0<<0),  //!< .
      ADC123_IN10_PC_0     = (ADC123_IN10    <<16)|(2<<12)|( 0<<4)|( 0<<0),  //!< .
      ADC123_IN11_PC_1     = (ADC123_IN11    <<16)|(2<<12)|( 1<<4)|( 0<<0),  //!< .
      ADC123_IN12_PC_2     = (ADC123_IN12    <<16)|(2<<12)|( 2<<4)|( 0<<0),  //!< .
      ADC123_IN13_PC_3     = (ADC123_IN13    <<16)|(2<<12)|( 3<<4)|( 0<<0),  //!< .
      ADC3_IN4_PF_6        = (ADC3_IN4       <<16)|(5<<12)|( 6<<4)|( 0<<0),  //!< .
      ADC3_IN5_PF_7        = (ADC3_IN5       <<16)|(5<<12)|( 7<<4)|( 0<<0),  //!< .
      ADC3_IN6_PF_8        = (ADC3_IN6       <<16)|(5<<12)|( 8<<4)|( 0<<0),  //!< .
      ADC3_IN7_PF_9        = (ADC3_IN7       <<16)|(5<<12)|( 9<<4)|( 0<<0),  //!< .
      ADC3_IN8_PE_10       = (ADC3_IN8       <<16)|(4<<12)|(10<<4)|( 0<<0),  //!< .
      ADC3_IN9_PF_3        = (ADC3_IN9       <<16)|(5<<12)|( 3<<4)|( 0<<0),  //!< .
      ADC3_IN14_PF_4       = (ADC3_IN14      <<16)|(5<<12)|( 4<<4)|( 0<<0),  //!< .
      ADC3_IN15_PF_5       = (ADC3_IN15      <<16)|(5<<12)|( 5<<4)|( 0<<0),  //!< .
      CAN1_RX_PA_11        = (CAN1_RX        <<16)|(0<<12)|(11<<4)|( 9<<0),  //!< .
      CAN1_RX_PB_8         = (CAN1_RX        <<16)|(1<<12)|( 8<<4)|( 9<<0),  //!< .
      CAN1_RX_PD_0         = (CAN1_RX        <<16)|(3<<12)|( 0<<4)|( 9<<0),  //!< .
      CAN1_RX_PI_9         = (CAN1_RX        <<16)|(8<<12)|( 9<<4)|( 9<<0),  //!< .
      CAN1_TX_PA_12        = (CAN1_TX        <<16)|(0<<12)|(12<<4)|( 9<<0),  //!< .
      CAN1_TX_PB_9         = (CAN1_TX        <<16)|(1<<12)|( 9<<4)|( 9<<0),  //!< .
      CAN1_TX_PD_1         = (CAN1_TX        <<16)|(3<<12)|( 1<<4)|( 9<<0),  //!< .
      CAN1_TX_PH_13        = (CAN1_TX        <<16)|(7<<12)|(13<<4)|( 9<<0),  //!< .
      CAN2_RX_PB_5         = (CAN2_RX        <<16)|(1<<12)|( 5<<4)|( 9<<0),  //!< .
      CAN2_RX_PB_12        = (CAN2_RX        <<16)|(1<<12)|(12<<4)|( 9<<0),  //!< .
      CAN2_TX_PB_6         = (CAN2_TX        <<16)|(1<<12)|( 6<<4)|( 9<<0),  //!< .
      CAN2_TX_PB_13        = (CAN2_TX        <<16)|(1<<12)|(13<<4)|( 9<<0),  //!< .
      DAC1_OUT_PA_4        = (DAC1_OUT       <<16)|(0<<12)|( 4<<4)|( 0<<0),  //!< .
      DAC2_OUT_PA_5        = (DAC2_OUT       <<16)|(0<<12)|( 5<<4)|( 0<<0),  //!< .
      ETH_MDC_PC_1         = (ETH_MDC        <<16)|(2<<12)|( 1<<4)|(11<<0),  //!< .
      ETH_MDIO_PA_2        = (ETH_MDIO       <<16)|(0<<12)|( 2<<4)|(11<<0),  //!< .
      ETH_MII_COL_PA_3     = (ETH_MII_COL    <<16)|(0<<12)|( 3<<4)|(11<<0),  //!< .
      ETH_MII_COL_PH_3     = (ETH_MII_COL    <<16)|(7<<12)|( 3<<4)|(11<<0),  //!< .
      ETH_MII_CRS_PA_0     = (ETH_MII_CRS    <<16)|(0<<12)|( 0<<4)|(11<<0),  //!< .
      ETH_MII_CRS_PH_2     = (ETH_MII_CRS    <<16)|(7<<12)|( 2<<4)|(11<<0),  //!< .
      ETH_MII_RX_CLK_PA_1  = (ETH_MII_RX_CLK <<16)|(0<<12)|( 1<<4)|(11<<0),  //!< .
      ETH_MII_RX_DV_PA_7   = (ETH_MII_RX_DV  <<16)|(0<<12)|( 7<<4)|(11<<0),  //!< .
      ETH_MII_RX_ER_PB_10  = (ETH_MII_RX_ER  <<16)|(1<<12)|(10<<4)|(11<<0),  //!< .
      ETH_MII_RX_ER_PI_10  = (ETH_MII_RX_ER  <<16)|(8<<12)|(10<<4)|(11<<0),  //!< .
      ETH_MII_RXD0_PC_4    = (ETH_MII_RXD0   <<16)|(2<<12)|( 4<<4)|(11<<0),  //!< .
      ETH_MII_RXD1_PC_5    = (ETH_MII_RXD1   <<16)|(2<<12)|( 5<<4)|(11<<0),  //!< .
      ETH_MII_RXD2_PB_0    = (ETH_MII_RXD2   <<16)|(1<<12)|( 0<<4)|(11<<0),  //!< .
      ETH_MII_RXD2_PH_6    = (ETH_MII_RXD2   <<16)|(7<<12)|( 6<<4)|(11<<0),  //!< .
      ETH_MII_RXD3_PB_1    = (ETH_MII_RXD3   <<16)|(1<<12)|( 1<<4)|(11<<0),  //!< .
      ETH_MII_RXD3_PH_7    = (ETH_MII_RXD3   <<16)|(7<<12)|( 7<<4)|(11<<0),  //!< .
      ETH_MII_TX_CLK_PC_3  = (ETH_MII_TX_CLK <<16)|(2<<12)|( 3<<4)|(11<<0),  //!< .
      ETH_MII_TX_EN_PB_11  = (ETH_MII_TX_EN  <<16)|(1<<12)|(11<<4)|(11<<0),  //!< .
      ETH_MII_TX_EN_PG_11  = (ETH_MII_TX_EN  <<16)|(6<<12)|(11<<4)|(11<<0),  //!< .
      ETH_MII_TXD0_PB_12   = (ETH_MII_TXD0   <<16)|(1<<12)|(12<<4)|(11<<0),  //!< .
      ETH_MII_TXD0_PG_13   = (ETH_MII_TXD0   <<16)|(6<<12)|(13<<4)|(11<<0),  //!< .
      ETH_MII_TXD1_PB_13   = (ETH_MII_TXD1   <<16)|(1<<12)|(13<<4)|(11<<0),  //!< .
      ETH_MII_TXD1_PG_14   = (ETH_MII_TXD1   <<16)|(6<<12)|(14<<4)|(11<<0),  //!< .
      ETH_MII_TXD2_PC_2    = (ETH_MII_TXD2   <<16)|(2<<12)|( 2<<4)|(11<<0),  //!< .
      ETH_MII_TXD3_PB_8    = (ETH_MII_TXD3   <<16)|(1<<12)|( 8<<4)|(11<<0),  //!< .
      ETH_MII_TXD3_PE_2    = (ETH_MII_TXD3   <<16)|(4<<12)|( 2<<4)|(11<<0),  //!< .
      ETH_PPS_OUT_PB_5     = (ETH_PPS_OUT    <<16)|(1<<12)|( 5<<4)|(11<<0),  //!< .
      ETH_PPS_OUT_PG_8     = (ETH_PPS_OUT    <<16)|(6<<12)|( 8<<4)|(11<<0),  //!< .
      ETH_RMII_CRS_DV_PA_7 = (ETH_RMII_CRS_DV<<16)|(0<<12)|( 7<<4)|(11<<0),  //!< .
      ETH_RMII_RXD0_PC_4   = (ETH_RMII_RXD0  <<16)|(2<<12)|( 4<<4)|(11<<0),  //!< .
      ETH_RMII_TX_EN_PB_11 = (ETH_RMII_TX_EN <<16)|(1<<12)|(11<<4)|(11<<0),  //!< .
      ETH_RMII_TX_EN_PG_11 = (ETH_RMII_TX_EN <<16)|(6<<12)|(11<<4)|(11<<0),  //!< .
      ETH_RMII_TXD0_PB_12  = (ETH_RMII_TXD0  <<16)|(1<<12)|(12<<4)|(11<<0),  //!< .
      ETH_RMII_TXD0_PG_13  = (ETH_RMII_TXD0  <<16)|(6<<12)|(13<<4)|(11<<0),  //!< .
      ETH_RMII_TXD1_PB_13  = (ETH_RMII_TXD1  <<16)|(1<<12)|(13<<4)|(11<<0),  //!< .
      ETH_RMII_TXD1_PG_14  = (ETH_RMII_TXD1  <<16)|(6<<12)|(14<<4)|(11<<0),  //!< .
      FSMC_A0_PF_0         = (FSMC_A0        <<16)|(5<<12)|( 0<<4)|(12<<0),  //!< .
      FSMC_A1_PF_1         = (FSMC_A1        <<16)|(5<<12)|( 1<<4)|(12<<0),  //!< .
      FSMC_A10_PG_0        = (FSMC_A10       <<16)|(6<<12)|( 0<<4)|(12<<0),  //!< .
      FSMC_A11_PG_1        = (FSMC_A11       <<16)|(6<<12)|( 1<<4)|(12<<0),  //!< .
      FSMC_A12_PG_2        = (FSMC_A12       <<16)|(6<<12)|( 2<<4)|(12<<0),  //!< .
      FSMC_A13_PG_3        = (FSMC_A13       <<16)|(6<<12)|( 3<<4)|(12<<0),  //!< .
      FSMC_A14_PG_4        = (FSMC_A14       <<16)|(6<<12)|( 4<<4)|(12<<0),  //!< .
      FSMC_A15_PG_5        = (FSMC_A15       <<16)|(6<<12)|( 5<<4)|(12<<0),  //!< .
      FSMC_A16_PD_11       = (FSMC_A16       <<16)|(3<<12)|(11<<4)|(12<<0),  //!< .
      FSMC_A17_PD_12       = (FSMC_A17       <<16)|(3<<12)|(12<<4)|(12<<0),  //!< .
      FSMC_A18_PD_13       = (FSMC_A18       <<16)|(3<<12)|(13<<4)|(12<<0),  //!< .
      FSMC_A19_PE_3        = (FSMC_A19       <<16)|(4<<12)|( 3<<4)|(12<<0),  //!< .
      FSMC_A2_PF_2         = (FSMC_A2        <<16)|(5<<12)|( 2<<4)|(12<<0),  //!< .
      FSMC_A20_PE_4        = (FSMC_A20       <<16)|(4<<12)|( 4<<4)|(12<<0),  //!< .
      FSMC_A21_PE_5        = (FSMC_A21       <<16)|(4<<12)|( 5<<4)|(12<<0),  //!< .
      FSMC_A22_PE_6        = (FSMC_A22       <<16)|(4<<12)|( 6<<4)|(12<<0),  //!< .
      FSMC_A23_PE_2        = (FSMC_A23       <<16)|(4<<12)|( 2<<4)|(12<<0),  //!< .
      FSMC_A24_PG_13       = (FSMC_A24       <<16)|(6<<12)|(13<<4)|(12<<0),  //!< .
      FSMC_A25_PG_14       = (FSMC_A25       <<16)|(6<<12)|(14<<4)|(12<<0),  //!< .
      FSMC_A3_PF_3         = (FSMC_A3        <<16)|(5<<12)|( 3<<4)|(12<<0),  //!< .
      FSMC_A4_PF_4         = (FSMC_A4        <<16)|(5<<12)|( 4<<4)|(12<<0),  //!< .
      FSMC_A5_PF_5         = (FSMC_A5        <<16)|(5<<12)|( 5<<4)|(12<<0),  //!< .
      FSMC_A6_PF_12        = (FSMC_A6        <<16)|(5<<12)|(12<<4)|(12<<0),  //!< .
      FSMC_A7_PF_13        = (FSMC_A7        <<16)|(5<<12)|(13<<4)|(12<<0),  //!< .
      FSMC_A8_PF_14        = (FSMC_A8        <<16)|(5<<12)|(14<<4)|(12<<0),  //!< .
      FSMC_A9_PF_15        = (FSMC_A9        <<16)|(5<<12)|(15<<4)|(12<<0),  //!< .
      FSMC_BLN1_PE_1       = (FSMC_BLN1      <<16)|(4<<12)|( 1<<4)|(12<<0),  //!< .
      FSMC_CD_PF_9         = (FSMC_CD        <<16)|(5<<12)|( 9<<4)|(12<<0),  //!< .
      FSMC_CLK_PD_3        = (FSMC_CLK       <<16)|(3<<12)|( 3<<4)|(12<<0),  //!< .
      FSMC_D0_PD_14        = (FSMC_D0        <<16)|(3<<12)|(14<<4)|(12<<0),  //!< .
      FSMC_D1_PD_15        = (FSMC_D1        <<16)|(3<<12)|(15<<4)|(12<<0),  //!< .
      FSMC_D10_PE_13       = (FSMC_D10       <<16)|(4<<12)|(13<<4)|(12<<0),  //!< .
      FSMC_D11_PE_14       = (FSMC_D11       <<16)|(4<<12)|(14<<4)|(12<<0),  //!< .
      FSMC_D12_PE_15       = (FSMC_D12       <<16)|(4<<12)|(15<<4)|(12<<0),  //!< .
      FSMC_D13_PD_8        = (FSMC_D13       <<16)|(3<<12)|( 8<<4)|(12<<0),  //!< .
      FSMC_D14_PD_9        = (FSMC_D14       <<16)|(3<<12)|( 9<<4)|(12<<0),  //!< .
      FSMC_D15_PD_10       = (FSMC_D15       <<16)|(3<<12)|(10<<4)|(12<<0),  //!< .
      FSMC_D2_PD_0         = (FSMC_D2        <<16)|(3<<12)|( 0<<4)|(12<<0),  //!< .
      FSMC_D3_PD_1         = (FSMC_D3        <<16)|(3<<12)|( 1<<4)|(12<<0),  //!< .
      FSMC_D4_PE_7         = (FSMC_D4        <<16)|(4<<12)|( 7<<4)|(12<<0),  //!< .
      FSMC_D5_PE_8         = (FSMC_D5        <<16)|(4<<12)|( 8<<4)|(12<<0),  //!< .
      FSMC_D6_PE_9         = (FSMC_D6        <<16)|(4<<12)|( 9<<4)|(12<<0),  //!< .
      FSMC_D7_PE_10        = (FSMC_D7        <<16)|(4<<12)|(10<<4)|(12<<0),  //!< .
      FSMC_D8_PE_11        = (FSMC_D8        <<16)|(4<<12)|(11<<4)|(12<<0),  //!< .
      FSMC_D9_PE_12        = (FSMC_D9        <<16)|(4<<12)|(12<<4)|(12<<0),  //!< .
      FSMC_INT2_PG_6       = (FSMC_INT2      <<16)|(6<<12)|( 6<<4)|(12<<0),  //!< .
      FSMC_INT3_PG_7       = (FSMC_INT3      <<16)|(6<<12)|( 7<<4)|(12<<0),  //!< .
      FSMC_INTR_PF_10      = (FSMC_INTR      <<16)|(5<<12)|(10<<4)|(12<<0),  //!< .
      FSMC_NBL0_PE_0       = (FSMC_NBL0      <<16)|(4<<12)|( 0<<4)|(12<<0),  //!< .
      FSMC_NCE2_PD_7       = (FSMC_NCE2      <<16)|(3<<12)|( 7<<4)|(12<<0),  //!< .
      FSMC_NCE3_PG_9       = (FSMC_NCE3      <<16)|(6<<12)|( 9<<4)|(12<<0),  //!< .
      FSMC_NCE4_1_PG_10    = (FSMC_NCE4_1    <<16)|(6<<12)|(10<<4)|(12<<0),  //!< .
      FSMC_NCE4_2_PG_11    = (FSMC_NCE4_2    <<16)|(6<<12)|(11<<4)|(12<<0),  //!< .
      FSMC_NE1_PD_7        = (FSMC_NE1       <<16)|(3<<12)|( 7<<4)|(12<<0),  //!< .
      FSMC_NE2_PG_9        = (FSMC_NE2       <<16)|(6<<12)|( 9<<4)|(12<<0),  //!< .
      FSMC_NE3_PG_10       = (FSMC_NE3       <<16)|(6<<12)|(10<<4)|(12<<0),  //!< .
      FSMC_NE4_PG_12       = (FSMC_NE4       <<16)|(6<<12)|(12<<4)|(12<<0),  //!< .
      FSMC_NIORD_PF_6      = (FSMC_NIORD     <<16)|(5<<12)|( 6<<4)|(12<<0),  //!< .
      FSMC_NIOWR_PF_8      = (FSMC_NIOWR     <<16)|(5<<12)|( 8<<4)|(12<<0),  //!< .
      FSMC_NL_PB_7         = (FSMC_NL        <<16)|(1<<12)|( 7<<4)|(12<<0),  //!< .
      FSMC_NOE_PD_4        = (FSMC_NOE       <<16)|(3<<12)|( 4<<4)|(12<<0),  //!< .
      FSMC_NREG_PF_7       = (FSMC_NREG      <<16)|(5<<12)|( 7<<4)|(12<<0),  //!< .
      FSMC_NWAIT_PD_6      = (FSMC_NWAIT     <<16)|(3<<12)|( 6<<4)|(12<<0),  //!< .
      FSMC_NWE_PD_5        = (FSMC_NWE       <<16)|(3<<12)|( 5<<4)|(12<<0),  //!< .
      I2C1_SCL_PB_6        = (I2C1_SCL       <<16)|(1<<12)|( 6<<4)|( 4<<0),  //!< .
      I2C1_SCL_PB_8        = (I2C1_SCL       <<16)|(1<<12)|( 8<<4)|( 4<<0),  //!< .
      I2C1_SDA_PB_7        = (I2C1_SDA       <<16)|(1<<12)|( 7<<4)|( 4<<0),  //!< .
      I2C1_SDA_PB_9        = (I2C1_SDA       <<16)|(1<<12)|( 9<<4)|( 4<<0),  //!< .
      I2C1_SMBA_PB_5       = (I2C1_SMBA      <<16)|(1<<12)|( 5<<4)|( 4<<0),  //!< .
      I2C2_SCL_PB_10       = (I2C2_SCL       <<16)|(1<<12)|(10<<4)|( 4<<0),  //!< .
      I2C2_SCL_PF_1        = (I2C2_SCL       <<16)|(5<<12)|( 1<<4)|( 4<<0),  //!< .
      I2C2_SCL_PH_4        = (I2C2_SCL       <<16)|(7<<12)|( 4<<4)|( 4<<0),  //!< .
      I2C2_SDA_PB_11       = (I2C2_SDA       <<16)|(1<<12)|(11<<4)|( 4<<0),  //!< .
      I2C2_SDA_PF_0        = (I2C2_SDA       <<16)|(5<<12)|( 0<<4)|( 4<<0),  //!< .
      I2C2_SDA_PH_5        = (I2C2_SDA       <<16)|(7<<12)|( 5<<4)|( 4<<0),  //!< .
      I2C2_SMBA_PB_12      = (I2C2_SMBA      <<16)|(1<<12)|(12<<4)|( 4<<0),  //!< .
      I2C2_SMBA_PF_2       = (I2C2_SMBA      <<16)|(5<<12)|( 2<<4)|( 4<<0),  //!< .
      I2C2_SMBA_PH_6       = (I2C2_SMBA      <<16)|(7<<12)|( 6<<4)|( 4<<0),  //!< .
      I2C3_SCL_PA_8        = (I2C3_SCL       <<16)|(0<<12)|( 8<<4)|( 4<<0),  //!< .
      I2C3_SCL_PH_7        = (I2C3_SCL       <<16)|(7<<12)|( 7<<4)|( 4<<0),  //!< .
      I2C3_SDA_PC_9        = (I2C3_SDA       <<16)|(2<<12)|( 9<<4)|( 4<<0),  //!< .
      I2C3_SDA_PH_8        = (I2C3_SDA       <<16)|(7<<12)|( 8<<4)|( 4<<0),  //!< .
      I2C3_SMBA_PA_9       = (I2C3_SMBA      <<16)|(0<<12)|( 9<<4)|( 4<<0),  //!< .
      I2C3_SMBA_PH_9       = (I2C3_SMBA      <<16)|(7<<12)|( 9<<4)|( 4<<0),  //!< .
      I2S_CKIN_PC_9        = (I2S_CKIN       <<16)|(2<<12)|( 9<<4)|( 5<<0),  //!< .
      I2S2_CK_PB_10        = (I2S2_CK        <<16)|(1<<12)|(10<<4)|( 5<<0),  //!< .
      I2S2_CK_PB_13        = (I2S2_CK        <<16)|(1<<12)|(13<<4)|( 5<<0),  //!< .
      I2S2_CK_PI_1         = (I2S2_CK        <<16)|(8<<12)|( 1<<4)|( 5<<0),  //!< .
      I2S2_MCK_PC_6        = (I2S2_MCK       <<16)|(2<<12)|( 6<<4)|( 5<<0),  //!< .
      I2S2_SD_PB_15        = (I2S2_SD        <<16)|(1<<12)|(15<<4)|( 5<<0),  //!< .
      I2S2_SD_PC_3         = (I2S2_SD        <<16)|(2<<12)|( 3<<4)|( 5<<0),  //!< .
      I2S2_SD_PI_3         = (I2S2_SD        <<16)|(8<<12)|( 3<<4)|( 5<<0),  //!< .
      I2S2_WS_PB_9         = (I2S2_WS        <<16)|(1<<12)|( 9<<4)|( 5<<0),  //!< .
      I2S2_WS_PB_12        = (I2S2_WS        <<16)|(1<<12)|(12<<4)|( 5<<0),  //!< .
      I2S2_WS_PI_0         = (I2S2_WS        <<16)|(8<<12)|( 0<<4)|( 5<<0),  //!< .
      I2S2ext_SD_PB_14     = (I2S2ext_SD     <<16)|(1<<12)|(14<<4)|( 6<<0),  //!< .
      I2S2ext_SD_PC_2      = (I2S2ext_SD     <<16)|(2<<12)|( 2<<4)|( 6<<0),  //!< .
      I2S2ext_SD_PI_2      = (I2S2ext_SD     <<16)|(8<<12)|( 2<<4)|( 6<<0),  //!< .
      I2S3_CK_PB_3         = (I2S3_CK        <<16)|(1<<12)|( 3<<4)|( 6<<0),  //!< .
      I2S3_MCK_PC_7        = (I2S3_MCK       <<16)|(2<<12)|( 7<<4)|( 6<<0),  //!< .
      I2S3_SD_PB_5         = (I2S3_SD        <<16)|(1<<12)|( 5<<4)|( 6<<0),  //!< .
      I2S3_SD_PC_12        = (I2S3_SD        <<16)|(2<<12)|(12<<4)|( 6<<0),  //!< .
      I2S3_WS_PA_4         = (I2S3_WS        <<16)|(0<<12)|( 4<<4)|( 6<<0),  //!< .
      I2S3ext_SD_PB_4      = (I2S3ext_SD     <<16)|(1<<12)|( 4<<4)|( 7<<0),  //!< .
      I2S3ext_SD_PC_11     = (I2S3ext_SD     <<16)|(2<<12)|(11<<4)|( 5<<0),  //!< .
      I2S3S_CK_PC_10       = (I2S3S_CK       <<16)|(2<<12)|(10<<4)|( 6<<0),  //!< .
      I2S3S_WS_PA_15       = (I2S3S_WS       <<16)|(0<<12)|(15<<4)|( 6<<0),  //!< .
      OTG_FS_DM_PA_11      = (OTG_FS_DM      <<16)|(0<<12)|(11<<4)|(10<<0),  //!< .
      OTG_FS_DP_PA_12      = (OTG_FS_DP      <<16)|(0<<12)|(12<<4)|(10<<0),  //!< .
      OTG_FS_ID_PA_10      = (OTG_FS_ID      <<16)|(0<<12)|(10<<4)|(10<<0),  //!< .
      OTG_FS_SOF_PA_8      = (OTG_FS_SOF     <<16)|(0<<12)|(8<<4)|(10<<0),  //!< .
      OTG_HS_DM_PB_14      = (OTG_HS_DM      <<16)|(1<<12)|(14<<4)|(12<<0),  //!< .
      OTG_HS_DP_PB_15      = (OTG_HS_DP      <<16)|(1<<12)|(15<<4)|(12<<0),  //!< .
      OTG_HS_ID_PB_12      = (OTG_HS_ID      <<16)|(1<<12)|(12<<4)|(12<<0),  //!< .
      OTG_HS_SOF_PA_4      = (OTG_HS_SOF     <<16)|(0<<12)|(4<<4)|(12<<0),  //!< .
      OTG_HS_ULPI_CK_PA_5  = (OTG_HS_ULPI_CK <<16)|(0<<12)|(5<<4)|(10<<0),  //!< .
      OTG_HS_ULPI_D0_PA_3  = (OTG_HS_ULPI_D0 <<16)|(0<<12)|(3<<4)|(10<<0),  //!< .
      OTG_HS_ULPI_D1_PB_0  = (OTG_HS_ULPI_D1 <<16)|(1<<12)|(0<<4)|(10<<0),  //!< .
      OTG_HS_ULPI_D2_PB_1  = (OTG_HS_ULPI_D2 <<16)|(1<<12)|(1<<4)|(10<<0),  //!< .
      OTG_HS_ULPI_D3_PB_10 = (OTG_HS_ULPI_D3 <<16)|(1<<12)|(10<<4)|(10<<0),  //!< .
      OTG_HS_ULPI_D4_PB_11 = (OTG_HS_ULPI_D4 <<16)|(1<<12)|(11<<4)|(10<<0),  //!< .
      OTG_HS_ULPI_D5_PB_12 = (OTG_HS_ULPI_D5 <<16)|(1<<12)|(12<<4)|(10<<0),  //!< .
      OTG_HS_ULPI_D6_PB_13 = (OTG_HS_ULPI_D6 <<16)|(1<<12)|(13<<4)|(10<<0),  //!< .
      OTG_HS_ULPI_D7_PB_5  = (OTG_HS_ULPI_D7 <<16)|(1<<12)|(5<<4)|(10<<0),  //!< .
      OTG_HS_ULPI_DIR_PC_2 = (OTG_HS_ULPI_DIR<<16)|(2<<12)|(2<<4)|(10<<0),  //!< .
      OTG_HS_ULPI_DIR_PI_11= (OTG_HS_ULPI_DIR<<16)|(8<<12)|(11<<4)|(10<<0),  //!< .
      OTG_HS_ULPI_NXT_PC_3 = (OTG_HS_ULPI_NXT<<16)|(2<<12)|(3<<4)|(10<<0),  //!< .
      OTG_HS_ULPI_NXT_PH_4 = (OTG_HS_ULPI_NXT<<16)|(7<<12)|(4<<4)|(10<<0),  //!< .
      OTG_HS_ULPI_STP_PC_0 = (OTG_HS_ULPI_STP<<16)|(2<<12)|(0<<4)|(10<<0),  //!< .
      SDIO_CK_PC_12        = (SDIO_CK        <<16)|(2<<12)|(12<<4)|(12<<0),  //!< .
      SDIO_CMD_PD_2        = (SDIO_CMD       <<16)|(3<<12)|( 2<<4)|(12<<0),  //!< .
      SDIO_D0_PC_8         = (SDIO_D0        <<16)|(2<<12)|( 8<<4)|(12<<0),  //!< .
      SDIO_D1_PC_9         = (SDIO_D1        <<16)|(2<<12)|( 9<<4)|(12<<0),  //!< .
      SDIO_D2_PC_10        = (SDIO_D2        <<16)|(2<<12)|(10<<4)|(12<<0),  //!< .
      SDIO_D3_PC_11        = (SDIO_D3        <<16)|(2<<12)|(11<<4)|(12<<0),  //!< .
      SDIO_D4_PB_8         = (SDIO_D4        <<16)|(1<<12)|( 8<<4)|(12<<0),  //!< .
      SDIO_D5_PB_9         = (SDIO_D5        <<16)|(1<<12)|( 9<<4)|(12<<0),  //!< .
      SDIO_D6_PC_6         = (SDIO_D6        <<16)|(2<<12)|( 6<<4)|(12<<0),  //!< .
      SDIO_D7_PC_7         = (SDIO_D7        <<16)|(2<<12)|( 7<<4)|(12<<0),  //!< .
      SPI1_MISO_PA_6       = (SPI1_MISO      <<16)|(0<<12)|( 6<<4)|( 5<<0),  //!< .
      SPI1_MISO_PB_4       = (SPI1_MISO      <<16)|(1<<12)|( 4<<4)|( 5<<0),  //!< .
      SPI1_MOSI_PA_7       = (SPI1_MOSI      <<16)|(0<<12)|( 7<<4)|( 5<<0),  //!< .
      SPI1_MOSI_PB_5       = (SPI1_MOSI      <<16)|(1<<12)|( 5<<4)|( 5<<0),  //!< .
      SPI1_NSS_PA_4        = (SPI1_NSS       <<16)|(0<<12)|( 4<<4)|( 5<<0),  //!< .
      SPI1_NSS_PA_15       = (SPI1_NSS       <<16)|(0<<12)|(15<<4)|( 5<<0),  //!< .
      SPI1_SCK_PA_5        = (SPI1_SCK       <<16)|(0<<12)|( 5<<4)|( 5<<0),  //!< .
      SPI1_SCK_PB_3        = (SPI1_SCK       <<16)|(1<<12)|( 3<<4)|( 5<<0),  //!< .
      SPI2_MISO_PB_14      = (SPI2_MISO      <<16)|(1<<12)|(14<<4)|( 5<<0),  //!< .
      SPI2_MISO_PC_2       = (SPI2_MISO      <<16)|(2<<12)|( 2<<4)|( 5<<0),  //!< .
      SPI2_MISO_PI_2       = (SPI2_MISO      <<16)|(8<<12)|( 2<<4)|( 5<<0),  //!< .
      SPI2_MOSI_PB_15      = (SPI2_MOSI      <<16)|(1<<12)|(15<<4)|( 5<<0),  //!< .
      SPI2_MOSI_PC_3       = (SPI2_MOSI      <<16)|(2<<12)|( 3<<4)|( 5<<0),  //!< .
      SPI2_MOSI_PI_3       = (SPI2_MOSI      <<16)|(8<<12)|( 3<<4)|( 5<<0),  //!< .
      SPI2_NSS_PB_9        = (SPI2_NSS       <<16)|(1<<12)|( 9<<4)|( 5<<0),  //!< .
      SPI2_NSS_PB_12       = (SPI2_NSS       <<16)|(1<<12)|(12<<4)|( 5<<0),  //!< .
      SPI2_NSS_PI_0        = (SPI2_NSS       <<16)|(8<<12)|( 0<<4)|( 5<<0),  //!< .
      SPI2_SCK_PB_10       = (SPI2_SCK       <<16)|(1<<12)|(10<<4)|( 5<<0),  //!< .
      SPI2_SCK_PB_13       = (SPI2_SCK       <<16)|(1<<12)|(13<<4)|( 5<<0),  //!< .
      SPI2_SCK_PI_1        = (SPI2_SCK       <<16)|(8<<12)|( 1<<4)|( 5<<0),  //!< .
      SPI3_MISO_PB_4       = (SPI3_MISO      <<16)|(1<<12)|( 4<<4)|( 6<<0),  //!< .
      SPI3_MISO_PC_11      = (SPI3_MISO      <<16)|(2<<12)|(11<<4)|( 6<<0),  //!< .
      SPI3_MOSI_PB_5       = (SPI3_MOSI      <<16)|(1<<12)|( 5<<4)|( 6<<0),  //!< .
      SPI3_MOSI_PC_12      = (SPI3_MOSI      <<16)|(2<<12)|(12<<4)|( 6<<0),  //!< .
      SPI3_NSS_PA_4        = (SPI3_NSS       <<16)|(0<<12)|( 4<<4)|( 6<<0),  //!< .
      SPI3_NSS_PA_15       = (SPI3_NSS       <<16)|(0<<12)|(15<<4)|( 6<<0),  //!< .
      SPI3_SCK_PB_3        = (SPI3_SCK       <<16)|(1<<12)|( 3<<4)|( 6<<0),  //!< .
      SPI3_SCK_PC_10       = (SPI3_SCK       <<16)|(2<<12)|(10<<4)|( 6<<0),  //!< .
      TIM1_BKIN_PA_6       = (TIM1_BKIN      <<16)|(0<<12)|( 6<<4)|( 1<<0),  //!< .
      TIM1_BKIN_PB_12      = (TIM1_BKIN      <<16)|(1<<12)|(12<<4)|( 1<<0),  //!< .
      TIM1_BKIN_PE_15      = (TIM1_BKIN      <<16)|(4<<12)|(15<<4)|( 1<<0),  //!< .
      TIM1_CH1_PA_8        = (TIM1_CH1       <<16)|(0<<12)|( 8<<4)|( 1<<0),  //!< .
      TIM1_CH1_PE_9        = (TIM1_CH1       <<16)|(4<<12)|( 9<<4)|( 1<<0),  //!< .
      TIM1_CH1N_PA_7       = (TIM1_CH1N      <<16)|(0<<12)|( 7<<4)|( 1<<0),  //!< .
      TIM1_CH1N_PB_13      = (TIM1_CH1N      <<16)|(1<<12)|(13<<4)|( 1<<0),  //!< .
      TIM1_CH1N_PE_8       = (TIM1_CH1N      <<16)|(4<<12)|( 8<<4)|( 1<<0),  //!< .
      TIM1_CH2_PA_9        = (TIM1_CH2       <<16)|(0<<12)|( 9<<4)|( 1<<0),  //!< .
      TIM1_CH2_PE_11       = (TIM1_CH2       <<16)|(4<<12)|(11<<4)|( 1<<0),  //!< .
      TIM1_CH2N_PB_0       = (TIM1_CH2N      <<16)|(1<<12)|( 0<<4)|( 1<<0),  //!< .
      TIM1_CH2N_PB_14      = (TIM1_CH2N      <<16)|(1<<12)|(14<<4)|( 1<<0),  //!< .
      TIM1_CH2N_PE_10      = (TIM1_CH2N      <<16)|(4<<12)|(10<<4)|( 1<<0),  //!< .
      TIM1_CH3_PA_10       = (TIM1_CH3       <<16)|(0<<12)|(10<<4)|( 1<<0),  //!< .
      TIM1_CH3_PE_13       = (TIM1_CH3       <<16)|(4<<12)|(13<<4)|( 1<<0),  //!< .
      TIM1_CH3N_PB_1       = (TIM1_CH3N      <<16)|(1<<12)|( 1<<4)|( 1<<0),  //!< .
      TIM1_CH3N_PB_15      = (TIM1_CH3N      <<16)|(1<<12)|(15<<4)|( 1<<0),  //!< .
      TIM1_CH3N_PE_12      = (TIM1_CH3N      <<16)|(4<<12)|(12<<4)|( 1<<0),  //!< .
      TIM1_CH4_PA_11       = (TIM1_CH4       <<16)|(0<<12)|(11<<4)|( 1<<0),  //!< .
      TIM1_CH4_PE_14       = (TIM1_CH4       <<16)|(4<<12)|(14<<4)|( 1<<0),  //!< .
      TIM1_ETR_PA_12       = (TIM1_ETR       <<16)|(0<<12)|(12<<4)|( 1<<0),  //!< .
      TIM1_ETR_PE_7        = (TIM1_ETR       <<16)|(4<<12)|( 7<<4)|( 1<<0),  //!< .
      TIM10_CH1_PB_8       = (TIM10_CH1      <<16)|(1<<12)|( 8<<4)|( 3<<0),  //!< .
      TIM10_CH1_PF_6       = (TIM10_CH1      <<16)|(5<<12)|( 6<<4)|( 3<<0),  //!< .
      TIM11_CH1_PB_9       = (TIM11_CH1      <<16)|(1<<12)|( 9<<4)|( 3<<0),  //!< .
      TIM11_CH1_PF_7       = (TIM11_CH1      <<16)|(5<<12)|( 7<<4)|( 3<<0),  //!< .
      TIM12_CH1_PB_14      = (TIM12_CH1      <<16)|(1<<12)|(14<<4)|( 9<<0),  //!< .
      TIM12_CH1_PH_6       = (TIM12_CH1      <<16)|(7<<12)|( 6<<4)|( 9<<0),  //!< .
      TIM12_CH2_PB_15      = (TIM12_CH2      <<16)|(1<<12)|(15<<4)|( 9<<0),  //!< .
      TIM12_CH2_PH_9       = (TIM12_CH2      <<16)|(7<<12)|( 9<<4)|( 9<<0),  //!< .
      TIM13_CH1_PA_6       = (TIM13_CH1      <<16)|(0<<12)|( 6<<4)|( 9<<0),  //!< .
      TIM13_CH1_PF_8       = (TIM13_CH1      <<16)|(5<<12)|( 8<<4)|( 9<<0),  //!< .
      TIM14_CH1_PA_7       = (TIM14_CH1      <<16)|(0<<12)|( 7<<4)|( 9<<0),  //!< .
      TIM14_CH1_PF_9       = (TIM14_CH1      <<16)|(5<<12)|( 9<<4)|( 9<<0),  //!< .
      TIM2_CH1_PA_0        = (TIM2_CH1       <<16)|(0<<12)|( 0<<4)|( 1<<0),  //!< .
      TIM2_CH1_PA_5        = (TIM2_CH1       <<16)|(0<<12)|( 5<<4)|( 1<<0),  //!< .
      TIM2_CH1_PA_15       = (TIM2_CH1       <<16)|(0<<12)|(15<<4)|( 1<<0),  //!< .
      TIM2_CH2_PA_1        = (TIM2_CH2       <<16)|(0<<12)|( 1<<4)|( 1<<0),  //!< .
      TIM2_CH2_PB_3        = (TIM2_CH2       <<16)|(1<<12)|( 3<<4)|( 1<<0),  //!< .
      TIM2_CH3_PA_2        = (TIM2_CH3       <<16)|(0<<12)|( 2<<4)|( 1<<0),  //!< .
      TIM2_CH3_PB_10       = (TIM2_CH3       <<16)|(1<<12)|(10<<4)|( 1<<0),  //!< .
      TIM2_CH4_PA_3        = (TIM2_CH4       <<16)|(0<<12)|( 3<<4)|( 1<<0),  //!< .
      TIM2_CH4_PB_11       = (TIM2_CH4       <<16)|(1<<12)|(11<<4)|( 1<<0),  //!< .
      TIM2_ETR_PA_0        = (TIM2_ETR       <<16)|(0<<12)|( 0<<4)|( 1<<0),  //!< .
      TIM2_ETR_PA_5        = (TIM2_ETR       <<16)|(0<<12)|( 5<<4)|( 1<<0),  //!< .
      TIM2_ETR_PA_15       = (TIM2_ETR       <<16)|(0<<12)|(15<<4)|( 1<<0),  //!< .
      TIM3_CH1_PA_6        = (TIM3_CH1       <<16)|(0<<12)|( 6<<4)|( 2<<0),  //!< .
      TIM3_CH1_PB_4        = (TIM3_CH1       <<16)|(1<<12)|( 4<<4)|( 2<<0),  //!< .
      TIM3_CH1_PC_6        = (TIM3_CH1       <<16)|(2<<12)|( 6<<4)|( 2<<0),  //!< .
      TIM3_CH2_PA_7        = (TIM3_CH2       <<16)|(0<<12)|( 7<<4)|( 2<<0),  //!< .
      TIM3_CH2_PB_5        = (TIM3_CH2       <<16)|(1<<12)|( 5<<4)|( 2<<0),  //!< .
      TIM3_CH2_PC_7        = (TIM3_CH2       <<16)|(2<<12)|( 7<<4)|( 2<<0),  //!< .
      TIM3_CH3_PB_0        = (TIM3_CH3       <<16)|(1<<12)|( 0<<4)|( 2<<0),  //!< .
      TIM3_CH3_PC_8        = (TIM3_CH3       <<16)|(2<<12)|( 8<<4)|( 2<<0),  //!< .
      TIM3_CH4_PB_1        = (TIM3_CH4       <<16)|(1<<12)|( 1<<4)|( 2<<0),  //!< .
      TIM3_CH4_PC_9        = (TIM3_CH4       <<16)|(2<<12)|( 9<<4)|( 2<<0),  //!< .
      TIM3_ETR_PD_2        = (TIM3_ETR       <<16)|(3<<12)|( 2<<4)|( 2<<0),  //!< .
      TIM4_CH1_PB_6        = (TIM4_CH1       <<16)|(1<<12)|( 6<<4)|( 2<<0),  //!< .
      TIM4_CH1_PD_12       = (TIM4_CH1       <<16)|(3<<12)|(12<<4)|( 2<<0),  //!< .
      TIM4_CH2_PB_7        = (TIM4_CH2       <<16)|(1<<12)|( 7<<4)|( 2<<0),  //!< .
      TIM4_CH2_PD_13       = (TIM4_CH2       <<16)|(3<<12)|(13<<4)|( 2<<0),  //!< .
      TIM4_CH3_PB_8        = (TIM4_CH3       <<16)|(1<<12)|( 8<<4)|( 2<<0),  //!< .
      TIM4_CH3_PD_14       = (TIM4_CH3       <<16)|(3<<12)|(14<<4)|( 2<<0),  //!< .
      TIM4_CH4_PB_9        = (TIM4_CH4       <<16)|(1<<12)|( 9<<4)|( 2<<0),  //!< .
      TIM4_CH4_PD_15       = (TIM4_CH4       <<16)|(3<<12)|(15<<4)|( 2<<0),  //!< .
      TIM4_ETR_PE_0        = (TIM4_ETR       <<16)|(4<<12)|( 0<<4)|( 2<<0),  //!< .
      TIM5_CH1_PA_0        = (TIM5_CH1       <<16)|(0<<12)|( 0<<4)|( 2<<0),  //!< .
      TIM5_CH1_PH_10       = (TIM5_CH1       <<16)|(7<<12)|(10<<4)|( 2<<0),  //!< .
      TIM5_CH2_PA_1        = (TIM5_CH2       <<16)|(0<<12)|( 1<<4)|( 2<<0),  //!< .
      TIM5_CH2_PH_11       = (TIM5_CH2       <<16)|(7<<12)|(11<<4)|( 2<<0),  //!< .
      TIM5_CH3_PA_2        = (TIM5_CH3       <<16)|(0<<12)|( 2<<4)|( 2<<0),  //!< .
      TIM5_CH3_PH_12       = (TIM5_CH3       <<16)|(7<<12)|(12<<4)|( 2<<0),  //!< .
      TIM5_CH4_PA_3        = (TIM5_CH4       <<16)|(0<<12)|( 3<<4)|( 2<<0),  //!< .
      TIM5_CH4_PI_0        = (TIM5_CH4       <<16)|(8<<12)|( 0<<4)|( 2<<0),  //!< .
      TIM8_BKIN_PA_6       = (TIM8_BKIN      <<16)|(0<<12)|( 6<<4)|( 3<<0),  //!< .
      TIM8_BKIN_PI_4       = (TIM8_BKIN      <<16)|(8<<12)|( 4<<4)|( 3<<0),  //!< .
      TIM8_CH1_PC_6        = (TIM8_CH1       <<16)|(2<<12)|( 6<<4)|( 3<<0),  //!< .
      TIM8_CH1_PI_5        = (TIM8_CH1       <<16)|(8<<12)|( 5<<4)|( 3<<0),  //!< .
      TIM8_CH1N_PA_5       = (TIM8_CH1N      <<16)|(0<<12)|( 5<<4)|( 3<<0),  //!< .
      TIM8_CH1N_PA_7       = (TIM8_CH1N      <<16)|(0<<12)|( 7<<4)|( 3<<0),  //!< .
      TIM8_CH1N_PH_13      = (TIM8_CH1N      <<16)|(7<<12)|(13<<4)|( 3<<0),  //!< .
      TIM8_CH2_PC_7        = (TIM8_CH2       <<16)|(2<<12)|( 7<<4)|( 3<<0),  //!< .
      TIM8_CH2_PI_6        = (TIM8_CH2       <<16)|(8<<12)|( 6<<4)|( 3<<0),  //!< .
      TIM8_CH2N_PB_0       = (TIM8_CH2N      <<16)|(1<<12)|( 0<<4)|( 3<<0),  //!< .
      TIM8_CH2N_PB_14      = (TIM8_CH2N      <<16)|(1<<12)|(14<<4)|( 3<<0),  //!< .
      TIM8_CH2N_PH_14      = (TIM8_CH2N      <<16)|(7<<12)|(14<<4)|( 3<<0),  //!< .
      TIM8_CH3_PC_8        = (TIM8_CH3       <<16)|(2<<12)|( 8<<4)|( 3<<0),  //!< .
      TIM8_CH3_PI_7        = (TIM8_CH3       <<16)|(8<<12)|( 7<<4)|( 3<<0),  //!< .
      TIM8_CH3N_PB_1       = (TIM8_CH3N      <<16)|(1<<12)|( 1<<4)|( 3<<0),  //!< .
      TIM8_CH3N_PB_15      = (TIM8_CH3N      <<16)|(1<<12)|(15<<4)|( 3<<0),  //!< .
      TIM8_CH3N_PH_15      = (TIM8_CH3N      <<16)|(7<<12)|(15<<4)|( 3<<0),  //!< .
      TIM8_CH4_PC_9        = (TIM8_CH4       <<16)|(2<<12)|( 9<<4)|( 3<<0),  //!< .
      TIM8_CH4_PI_2        = (TIM8_CH4       <<16)|(8<<12)|( 2<<4)|( 3<<0),  //!< .
      TIM8_ETR_PA_0        = (TIM8_ETR       <<16)|(0<<12)|( 0<<4)|( 3<<0),  //!< .
      TIM8_ETR_PI_3        = (TIM8_ETR       <<16)|(8<<12)|( 3<<4)|( 3<<0),  //!< .
      TIM9_CH1_PA_2        = (TIM9_CH1       <<16)|(0<<12)|( 2<<4)|( 3<<0),  //!< .
      TIM9_CH1_PE_5        = (TIM9_CH1       <<16)|(4<<12)|( 5<<4)|( 3<<0),  //!< .
      TIM9_CH2_PA_3        = (TIM9_CH2       <<16)|(0<<12)|( 3<<4)|( 3<<0),  //!< .
      TIM9_CH2_PE_6        = (TIM9_CH2       <<16)|(4<<12)|( 6<<4)|( 3<<0),  //!< .
      UART4_RX_PA_1        = (UART4_RX       <<16)|(0<<12)|( 1<<4)|( 8<<0),  //!< .
      UART4_RX_PC_11       = (UART4_RX       <<16)|(2<<12)|(11<<4)|( 8<<0),  //!< .
      UART4_TX_PA_0        = (UART4_TX       <<16)|(0<<12)|( 0<<4)|( 8<<0),  //!< .
      UART4_TX_PC_10       = (UART4_TX       <<16)|(2<<12)|(10<<4)|( 8<<0),  //!< .
      UART5_RX_PD_2        = (UART5_RX       <<16)|(3<<12)|( 2<<4)|( 8<<0),  //!< .
      UART5_TX_PC_12       = (UART5_TX       <<16)|(2<<12)|(12<<4)|( 8<<0),  //!< .
      UART6_CTS_PG_13      = (UART6_CTS      <<16)|(6<<12)|(13<<4)|( 8<<0),  //!< .
      USART1_CK_PA_8       = (USART1_CK      <<16)|(0<<12)|( 8<<4)|( 7<<0),  //!< .
      USART1_CTS_PA_11     = (USART1_CTS     <<16)|(0<<12)|(11<<4)|( 7<<0),  //!< .
      USART1_RTS_PA_12     = (USART1_RTS     <<16)|(0<<12)|(12<<4)|( 7<<0),  //!< .
      USART1_RX_PA_10      = (USART1_RX      <<16)|(0<<12)|(10<<4)|( 7<<0),  //!< .
      USART1_RX_PB_7       = (USART1_RX      <<16)|(1<<12)|( 7<<4)|( 7<<0),  //!< .
      USART1_TX_PA_9       = (USART1_TX      <<16)|(0<<12)|( 9<<4)|( 7<<0),  //!< .
      USART1_TX_PB_6       = (USART1_TX      <<16)|(1<<12)|( 6<<4)|( 7<<0),  //!< .
      USART2_CK_PA_4       = (USART2_CK      <<16)|(0<<12)|( 4<<4)|( 7<<0),  //!< .
      USART2_CK_PD_7       = (USART2_CK      <<16)|(3<<12)|( 7<<4)|( 7<<0),  //!< .
      USART2_CTS_PA_0      = (USART2_CTS     <<16)|(0<<12)|( 0<<4)|( 7<<0),  //!< .
      USART2_CTS_PD_3      = (USART2_CTS     <<16)|(3<<12)|( 3<<4)|( 7<<0),  //!< .
      USART2_RTS_PA_1      = (USART2_RTS     <<16)|(0<<12)|( 1<<4)|( 7<<0),  //!< .
      USART2_RTS_PD_4      = (USART2_RTS     <<16)|(3<<12)|( 4<<4)|( 7<<0),  //!< .
      USART2_RX_PA_3       = (USART2_RX      <<16)|(0<<12)|( 3<<4)|( 7<<0),  //!< .
      USART2_RX_PD_6       = (USART2_RX      <<16)|(3<<12)|( 6<<4)|( 7<<0),  //!< .
      USART2_TX_PA_2       = (USART2_TX      <<16)|(0<<12)|( 2<<4)|( 7<<0),  //!< .
      USART2_TX_PD_5       = (USART2_TX      <<16)|(3<<12)|( 5<<4)|( 7<<0),  //!< .
      USART3_CK_PB_12      = (USART3_CK      <<16)|(1<<12)|(12<<4)|( 7<<0),  //!< .
      USART3_CK_PC_12      = (USART3_CK      <<16)|(2<<12)|(12<<4)|( 7<<0),  //!< .
      USART3_CK_PD_10      = (USART3_CK      <<16)|(3<<12)|(10<<4)|( 7<<0),  //!< .
      USART3_CTS_PB_13     = (USART3_CTS     <<16)|(1<<12)|(13<<4)|( 7<<0),  //!< .
      USART3_CTS_PD_11     = (USART3_CTS     <<16)|(3<<12)|(11<<4)|( 7<<0),  //!< .
      USART3_RTS_PB_14     = (USART3_RTS     <<16)|(1<<12)|(14<<4)|( 7<<0),  //!< .
      USART3_RTS_PD_12     = (USART3_RTS     <<16)|(3<<12)|(12<<4)|( 7<<0),  //!< .
      USART3_RX_PB_11      = (USART3_RX      <<16)|(1<<12)|(11<<4)|( 7<<0),  //!< .
      USART3_RX_PC_11      = (USART3_RX      <<16)|(2<<12)|(11<<4)|( 7<<0),  //!< .
      USART3_RX_PD_9       = (USART3_RX      <<16)|(3<<12)|( 9<<4)|( 7<<0),  //!< .
      USART3_TX_PB_10      = (USART3_TX      <<16)|(1<<12)|(10<<4)|( 7<<0),  //!< .
      USART3_TX_PD_8       = (USART3_TX      <<16)|(3<<12)|( 8<<4)|( 7<<0),  //!< .
      USART3_TX_PC_10      = (USART3_TX      <<16)|(2<<12)|(10<<4)|( 7<<0),  //!< .
      USART6_CK_PC_8       = (USART6_CK      <<16)|(2<<12)|( 8<<4)|( 8<<0),  //!< .
      USART6_CK_PG_7       = (USART6_CK      <<16)|(6<<12)|( 7<<4)|( 8<<0),  //!< .
      USART6_CTS_PG_15     = (USART6_CTS     <<16)|(6<<12)|(15<<4)|( 8<<0),  //!< .
      USART6_RTS_PG_8      = (USART6_RTS     <<16)|(6<<12)|( 8<<4)|( 8<<0),  //!< .
      USART6_RTS_PG_12     = (USART6_RTS     <<16)|(6<<12)|(12<<4)|( 8<<0),  //!< .
      USART6_RX_PC_7       = (USART6_RX      <<16)|(2<<12)|( 7<<4)|( 8<<0),  //!< .
      USART6_RX_PG_9       = (USART6_RX      <<16)|(6<<12)|( 9<<4)|( 8<<0),  //!< .
      USART6_TX_PC_6       = (USART6_TX      <<16)|(2<<12)|( 6<<4)|( 8<<0),  //!< .
      USART6_TX_PG_14      = (USART6_TX      <<16)|(6<<12)|(14<<4)|( 8<<0),  //!< .
      END_OF_TABLE     = 0
    } MAP;

  public:
    //---------------------------------------------------------------
    /*! Set configuration of a GPIO
        \param gpio  Pointer to function register. 
                     Use predefined constant \a 'GPIOx'
        \param pinId GPIO pin number (0,...15)
        \param mode  Selected pin mode. 
                     Use constants defined in \b MODE, the constants
                     can be combined using bit-or operations. 
        \param af    Number of selected alternate function. This 
                     parameter is used only, when \b ALTERNATE_FUNC 
                     is selected.
    */
    static void set( GPIO_TypeDef *gpio, 
                     BYTE          pinId, 
                     DWORD         mode, 
                     BYTE          af = 0 );

    //---------------------------------------------------------------
    /*! Set GPIO to alternate function
    
        A GPIO can be connected to a onchip peripheral module. The 
        enum \b 'Function' lists all peripheral signals which can be 
        connected to a GPIO. This method uses a application specific 
        mapping \b 'table'. The application has to define 
        this \b 'table' on global scope. The entries of this table 
        define on which port pin a peripheral signal is mapped. 
        \param func  Selected peripheral signal as alternate function
        \param mode  Selected pin mode. 
                     Use constants defined in \b MODE, the constants
                     can be combined using bit-or operations. 
        \return 
                - true, if \b func is included in \b table
                - false otherwise    
    */
    static bool set( Function func,
                     DWORD    mode = 0 );

  public:
    //---------------------------------------------------------------
    /*! This table defines how an alternate function is mapped to the 
        port pins. It must be defined by application software. The 
        last entry of this table has to be \b 'END_OF_TABLE'.
    */
    static MAP table[];

}; //cHwPinConfig

#endif
