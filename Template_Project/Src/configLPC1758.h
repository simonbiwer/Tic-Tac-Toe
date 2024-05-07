//*******************************************************************
// LPC1758
//*******************************************************************

//-------------------------------------------------------------------
#include "Peripheral/Disp_SPFD5408Bspi.h"
#include "Peripheral/Touch_STMPE811i2c.h"

//-------------------------------------------------------------------
#include "Com/Hardware/Display/Font/Font_8x12.h"


//*******************************************************************
cSystem sys;

cHwPinConfig::MAP cHwPinConfig::table[] =
  {
  // UART
  TXD1_P2_0,
  RXD1_P2_1,

  // ADC
  AD0_0_P0_23,
  AD0_1_P0_24,
  AD0_2_P0_25,
  AD0_3_P0_26,
  AD0_4_P1_30,
  AD0_5_P1_31,
  AD0_6_P0_3,
  AD0_7_P0_2,

  // DAC
  AOUT_P0_26,

  // Timer
  PWM1_1_P2_0,
  PWM1_2_P2_1,
  PWM1_3_P2_2,
  PWM1_4_P2_3,
  PWM1_5_P2_4,
  PWM1_6_P2_5,

  // SPI
  SCK1_P0_7,
  MISO1_P0_8,
  MOSI1_P0_9,

  // I2C
  SDA2_P0_10,
  SCL2_P0_11,

  
  END_OF_TABLE
};

//- Timer------------------------------------------------------------
cHwTimer_N   timer   ( cHwTimer_N::TIM_1,   1000 );
cHwTimer_N   timer2   ( cHwTimer_N::TIM_2,   1000 );
cHwTimer_N   timerPWM( cHwTimer_N::TIM_PWM, 4095 );

//- Digital Port ----------------------------------------------------
cHwPort_N    port0   ( cHwPort_N::P0 );
cHwPort_N    port1   ( cHwPort_N::P1 );
cHwPort_N    port2   ( cHwPort_N::P2 );
cHwPort_N    port4   ( cHwPort_N::P4 );

//- Analog In -------------------------------------------------------
cHwADC_0         adcHw( &timer );
cDevAnalogInADC  adcA( adcHw, 0, 3.3, 0.0 ); 

//- Analog OutIn ----------------------------------------------------
cHwDAC_0         dacHw;
cDevAnalogOutDAC dacA( dacHw, 0, 3.3, 0.0 );

//- Display ---------------------------------------------------------
cHwSPImaster_1       spi1        ( cHwSPImaster::CR_8000kHz, cHwSPImaster::CPOL_H_CPHA_H );
cHwSPImaster::Device spiDisplay  ( spi1, port0, 6 );
cHwPort::Pin         pinBackLight( port4, 28 );
cHwDisp_SPFD5408Bspi dispHw      ( spiDisplay,
                                   pinBackLight ,
                                   fontFont_8x12, // font
                                   1 );           // actual zoom factor
cDevDisplayGraphic disp( dispHw );

//- Touch -----------------------------------------------------------
cHwI2Cmaster_N       i2c( cHwI2Cmaster_N::I2C_2, cHwI2Cmaster::CR_100kHz);
cHwTouch_STMPE811i2c touch( i2c, 0, 320, 240);
cDevControlPointer   pointer( touch );

//- Joystick --------------------------------------------------------
cDevDigital btnRight( port1, 26, cDevDigital::In, 1 );
cDevDigital btnLeft ( port1, 24, cDevDigital::In, 1 );
cDevDigital btnCtrl ( port1, 20, cDevDigital::In, 1 );

cDevControlEncoderJoystick enc( &btnRight, &btnLeft, &btnCtrl, &timer, 200/*ms*/ );

//- Button ----------------------------------------------------------
cDevDigital      btn( port2, 10, cDevDigital::In, 1 );

//- LED -------------------------------------------------------------
cDevDigital      led( port1, 31, cDevDigital::Out,  0 );

//- Real Time Clock (RTC) -------------------------------------------
cHwRTC_0         rtc;

//EOF
