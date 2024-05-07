//*******************************************************************
/*!
\file   Touch_STMPE811i2c.cpp
\author Thomas Breuer
\date   15.10.2013

\see STMPE811 reference code for touchscreen controller operation,\n
     AN2807,\n
     STMicroelectronics,\n
     http://www.st.com/st-web-ui/static/active/en/resource/technical/document/application_note/CD00203648.pdf
*/

#include "lib.h"
#include "Peripheral/Touch_STMPE811i2c.h"
//*******************************************************************
//
// cHwTouch_STMPE811i2c
//
//*******************************************************************
//-------------------------------------------------------------------
cHwTouch_STMPE811i2c::cHwTouch_STMPE811i2c( cHwI2Cmaster &i2cIn, 
                                            BYTE          addrIn, 
                                            WORD          widthIn, 
                                            WORD          heightIn )

: cHwTouch(widthIn, heightIn ), 
  i2c( i2cIn, (addrIn ? 0x88 : 0x82) )
{
  i2c.write(  (BYTE)0x03, // SYS_CTRL1, reset the device
                           (0<<0)   // HIBERNATE: off
                          |(1<<1)); // SOFT_RESET: Reset Touchscreen controller
  
  cSystem::delayMilliSec( 10 );
  
  i2c.write(  (BYTE)0x04, // SYS_CTRL2, switch clock supply switch
                           (0<<0)   // ADC_OFF:  ADC on
                          |(0<<1)   // TSC_OFF:  Touchscreen controller on 
                          |(1<<2)   // GPIO_OFF: GPIO off
                          |(1<<3)); // TS_OFF:   Temperature sensor off

  i2c.write(  (BYTE)0x0A, // INT_EN, interrupt enable
                            (0<<0)   // TOUCH_DET:  off
                           |(0<<1)   // FIFO_TH:    off
                           |(0<<2)   // FIFO_OFLOW: off
                           |(0<<3)   // FIFO_FULL:  off
                           |(0<<4)   // FIFO_EMPTY: off
                           |(0<<5)   // TEMP_SENS:  off
                           |(0<<6)   // ADC:        off
                           |(0<<7)); // GPIO:       off
  
  i2c.write(  (BYTE)0x20, // ADC_CTRL1
                            (1<<0)   // RESERVED:    (setting this bit is recommended by data sheet)
                           |(0<<1)   // REF_SEL:     internal
                           |(1<<3)   // MOD_12B:     12 bit ADC
                           |(6<<4)); // SAMPLE_TIME: 124 clock ticks
  
  cSystem::delayMilliSec( 2 );

  i2c.write(  (BYTE)0x21, // ADC_CTRL2
                           (1<<0)); // ADC_FREQ: 3.25MHz
  
  i2c.write(  (BYTE)0x17, // GPIO_ALT_FUNCT, alternate function 
                          (0<<0)); // no alternate functions

  i2c.write(  (BYTE)0x41, // TSC_CFG, touchscreen controller configuration
                           (0<<0)   // SETTLING:        10us
                          |(0<<3)   // TOUCH_DET_DELAY: 10us
                          |(0<<6)); // AVE_CTRL:        1 sample average
                          
  i2c.write(  (BYTE)0x4A, // FIFO_TH, threshold value
                            (1<<0)); // FIFO_TH: 1 (single point reading) 
    
  i2c.write(  (BYTE)0x4B, // FIFO_STA
                           (1<<0)); // FIFO_RESET: clear FIFO
                           
  i2c.write(  (BYTE)0x4B, // FIFO_STA
                           (0<<0)); // FIFO_RESET: operating mode
                           
  i2c.write(  (BYTE)0x56, // TSC_FRACTION_Z, range and accuracy of pressure measurement
                           (7<<0)); // FRACTION_Z: fractional part is 7, whole part is 1
  
  i2c.write(  (BYTE)0x58, // TSC_I_DRIVE, current limit
                            (1<<0)); // DRIVE: 50mA typ./80 mA max
  
  i2c.write(  (BYTE)0x40, // TSC_CTRL, 4-wire touchscreen controller setup
                           (1<<0)   // EN:     enable TSC
                          |(0<<1)   // OP_MOD: X,Y, Z accquisition
                          |(0<<4)); // TRACK:  no window tracking
  
  i2c.write(  (BYTE)0x0B, // INT_STA, interrupt status and clear
                            (1<<0)   // TOUCH_DET:  clear
                           |(1<<1)   // FIFO_TH:    clear
                           |(1<<2)   // FIFO_OFLOW: clear
                           |(1<<3)   // FIFO_FULL:  clear
                           |(1<<4)   // FIFO_EMPTY: clear
                           |(1<<5)   // TEMP_SENS:  clear
                           |(1<<6)   // ADC:        clear
                           |(1<<7)); // GPIO:       clear
               
  i2c.write(  (BYTE)0x09, // INT_CTRL, enable interrupt
                            (1<<0)   // GLOBAL_INT:   enable
                           |(0<<1)   // INT_TYPE:     level interrupt
                           |(0<<2)); // INT_POLARITY: active low/falling edge
}

//-------------------------------------------------------------------
void cHwTouch_STMPE811i2c::update( void )
{
  if( i2c.read(  (BYTE)0x0B ) ) // any interrupt pending?
  {
    BYTE dat[5];

    i2c.read ( (BYTE)0x4D, dat, 5 );
    i2c.write( (BYTE)0x4B, 0x01 );   // FIFO_RESET
    i2c.write( (BYTE)0x4B, 0x00 );
                           
    WORD x = (WORD)256*dat[0] + dat[1];
    WORD y = (WORD)256*dat[2] + dat[3];
    BYTE z = dat[4];
    
    if( !i2c.isError() )
    {
      if( z > 10 )
      {
        if( 10 < x && x <= 0xFF0 && 10 < y && y <= 0xFF0 ) 
        {          
          xPos = RANGE( (int)(         width  * y/0x1000), 0, (int)width  - 1 );
          yPos = RANGE( (int)(height - height * x/0x1000), 0, (int)height - 1 );  
        }
        isTouchedFlag = true;
      }
      else
      {
        isTouchedFlag = false;
      } 
    }
  }
}

//EOF
