//*******************************************************************
/*!
\file   Disp_SSD2119.cpp
\author Thomas Breuer
\date   09.10.2018
*/

#include "lib.h"
#include "Disp_SSD2119.h"

// see: www.element14.com/community, STM: Software examples for STM32F4xx, STM32F4xx_LCD_Example.zip

//*******************************************************************
// 
// cHwDisp_SSD2119
//
//*******************************************************************
//-------------------------------------------------------------------
cHwDisp_SSD2119::cHwDisp_SSD2119(  DWORD           cmdAddr, 
                                   DWORD           dataAddr,
                                   cHwPort::Pin   &pinReset,
                                   cHwPort::Pin   &pinBL,
                                   cHwDisplayFont  fntIn, 
                                   BYTE            zoomIn )

: cHwDisplayGraphic( fntIn, zoomIn ),
  reset(pinReset)

{ 
  Hsize = HEIGHT;
  Vsize = WIDTH;

  ptrCmd  = (__IO WORD *)cmdAddr;
  ptrData = (__IO WORD *)dataAddr;
  
  reset.setMode( cHwPort::Out );
    
  pinBL.setMode( cHwPort::Out );
  pinBL.clr(); // backlight off
  init();
  pinBL.set(); // backlight on
}

//-------------------------------------------------------------------
void cHwDisp_SSD2119::clear( void )
{
  setArea( 0, 0, WIDTH, HEIGHT );
  
  for( WORD x = 0; x < WIDTH; x++)
  {
    for( WORD y = 0; y < HEIGHT; y++)
    {
      setPixel( BackColor );
    }
  }
}

//---------------------------------------------------------------
void cHwDisp_SSD2119::setArea( WORD x, 
                               WORD y,
                               WORD w,
                               WORD h )
{
  writeCmd( H_RAM_START, x );
  writeCmd( H_RAM_END,   x+w-1 );		
  writeCmd( V_RAM_POS,   x | ((y+h) << 8) );
  writeCmd( X_RAM_ADDR,  x );
  writeCmd( Y_RAM_ADDR,  y );
  writeCmd( RAM_DATA );
}

//---------------------------------------------------------------
void cHwDisp_SSD2119::setPixel( WORD color, 
                                   WORD x, 
                                   WORD y ) 
{
  setArea( x, y, 1, 1 );   // set draw position
  writeCmd( RAM_DATA );
  writeDat( color );
}

//---------------------------------------------------------------
void cHwDisp_SSD2119::setPixel( WORD color ) 
{
  writeDat( color );
}

//---------------------------------------------------------------
void cHwDisp_SSD2119::init( void ) 
{ 
  /* Reset LCD */
  reset.clr(); //
  cSystem::delayMilliSec( 20 );
  reset.set();
	cSystem::delayMilliSec( 20 );

  writeCmd( SLEEP_MODE_1,      0x0001 ); // Enter sleep mode
  writeCmd( PWR_CTRL_5,        0x00B2 );
  writeCmd( VCOM_OTP_1,        0x0006 );
  writeCmd( OSC_START,         0x0001 );
  writeCmd( OUTPUT_CTRL,       0x30EF ); // Set pixel format and basic display orientation (scanning direction)
  writeCmd( LCD_DRIVE_AC_CTRL, 0x0600 );
  writeCmd( SLEEP_MODE_1,      0x0000 ); // Exit sleep mode

  cSystem::delayMilliSec( 20 );
	  
  writeCmd( ENTRY_MODE,        0x6830 ); // Pixel color format and MCU interface parameters
  writeCmd( SLEEP_MODE_2,      0x0999 ); // Analog parameters
  writeCmd( ANALOG_SET,        0x3800 );
  writeCmd( DISPLAY_CTRL,      0x0033 ); // Enable the display
  writeCmd( PWR_CTRL_2,        0x0005 ); // Set VCIX2 voltage to 6.1V
  writeCmd( PWR_CTRL_3,        0x000A ); // Configure Vlcd63 and VCOMl
  writeCmd( PWR_CTRL_4,        0x2E00 );
  
  /* Configure gamma correction.*/
  writeCmd( GAMMA_CTRL_1,  0x0000 );
  writeCmd( GAMMA_CTRL_2,  0x0303 );
  writeCmd( GAMMA_CTRL_3,  0x0407 );
  writeCmd( GAMMA_CTRL_4,  0x0301 );
  writeCmd( GAMMA_CTRL_5,  0x0301 );
  writeCmd( GAMMA_CTRL_6,  0x0403 );
  writeCmd( GAMMA_CTRL_7,  0x0707 );
  writeCmd( GAMMA_CTRL_8,  0x0400 );
  writeCmd( GAMMA_CTRL_9,  0x0a00 );
  writeCmd( GAMMA_CTRL_10, 0x1000 );

  clear();
}

//-------------------------------------------------------------------
__inline void cHwDisp_SSD2119::writeCmd( BYTE reg, WORD value ) 
{
  *ptrCmd  = reg;
  *ptrData = value;
}

//-------------------------------------------------------------------
 __inline void cHwDisp_SSD2119::writeCmd( BYTE reg ) 
{
	*ptrCmd = reg; 
}

//-------------------------------------------------------------------
__inline void cHwDisp_SSD2119::writeDat( WORD dat ) 
{
  /* Write 16-bit GRAM Reg */
  *ptrData = dat;
}

//EOF
