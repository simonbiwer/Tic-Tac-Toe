//*******************************************************************
// STM32L1xx
//*******************************************************************

//-------------------------------------------------------------------
#include "Peripheral/Disp_DIP204spi.h"

//-------------------------------------------------------------------
cSystem sys;

//-------------------------------------------------------------------
cHwPinConfig::MAP cHwPinConfig::table[] = 
{
  // ADC
  ADC12_IN2_PA_2,
  
  // DAC
  DAC_OUT1_PA_4,
  
  // I2C
  I2C2_SCL_PB_10,
  I2C2_SDA_PB_11,

  // SPI
  SPI2_MOSI_PB_15,
  SPI2_MISO_PB_14,
  SPI2_SCK_PB_13,

  // Timer
  TIM2_CH1_ETR_PA_0,
  TIM2_CH2_PA_1,
  TIM2_CH3_PA_2,
  TIM2_CH4_PA_3,

  TIM3_CH1_PB_4,
  TIM3_CH2_PB_5,
  TIM3_CH3_PB_0,
  TIM3_CH4_PB_1,

  TIM4_CH1_PB_6,
  TIM4_CH2_PB_7,
  TIM4_CH3_PB_8,
  TIM4_CH4_PB_9,

  // UART
  USART1_TX_PA_9,
  USART1_RX_PA_10,

  USART3_TX_PC_10,
  USART3_RX_PC_11,

  END_OF_TABLE
};

//- Timer------------------------------------------------------------
cHwTimer_N  timer   ( cHwTimer_N::TIM_2, 10000/*us*/ );
cHwTimer_N  timerPWM( cHwTimer_N::TIM_3, 16382/*us*/ );

//- Digital Port ----------------------------------------------------
cHwPort_N   portA( cHwPort_N::PA );
cHwPort_N   portB( cHwPort_N::PB );
cHwPort_N   portC( cHwPort_N::PC );
cHwPort_N   portD( cHwPort_N::PD );

//- Analog In -------------------------------------------------------
cHwADC_0         adcHw( &timer );
cDevAnalogInADC  adcA( adcHw, 2, 3.3, 0.0 ); 

//- Analog OutIn ----------------------------------------------------
cHwDAC_0         dacHw;
cDevAnalogOutDAC dacA( dacHw, 1, 3.3, 0.0 );

//- Display ---------------------------------------------------------
cHwSPImaster_N       spi2      ( cHwSPImaster_N::SPI_2, 
                                 cHwSPImaster::CR_500kHz, 
                                 cHwSPImaster::CPOL_H_CPHA_H );
cHwSPImaster::Device spiDisplay( spi2, portB, 12 );

cHwDisp_DIP204spi    dispHw      ( spiDisplay );

cDevDisplayChar  disp( dispHw );

//- Joystick --------------------------------------------------------
cDevDigital    btnRight( portA, 1, cDevDigital::InPU, 1 );
cDevDigital    btnLeft ( portA, 8, cDevDigital::InPU, 1 );
cDevDigital    btnCtrl ( portA,15, cDevDigital::InPU, 1 );

cDevControlEncoderRotaryKnob enc( &btnLeft, &btnRight, &btnCtrl, &timer);

//- Button ----------------------------------------------------------
cDevDigital    btn    ( portC, 1,cDevDigital::InPU, 1 );

//- LED -------------------------------------------------------------
cDevDigital    led    ( portC, 8, cDevDigital::Out, 0 );

//- Real Time Clock (RTC) -------------------------------------------
cHwRTC_0 rtc;

//EOF
