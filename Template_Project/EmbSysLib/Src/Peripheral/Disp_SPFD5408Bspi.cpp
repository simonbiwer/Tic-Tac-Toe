//*******************************************************************
/*!
\file   Disp_SPFD5408Bspi.cpp
\author Thomas Breuer
\date   10.03.2011
*/

#include "lib.h"
#include "Disp_SPFD5408Bspi.h"

//*******************************************************************
//
// cHwDisp_SPFD5408Bspi
//
//*******************************************************************
//-------------------------------------------------------------------
cHwDisp_SPFD5408Bspi::cHwDisp_SPFD5408Bspi( cHwSPImaster::Device  &spiIn, 
                                            cHwPort::Pin          &pinBL,
                                            cHwDisplayFont         fontIn, 
                                            BYTE                   zoomIn )

: cHwDisplayGraphic( fontIn, zoomIn ),
  spi( spiIn )

{
  pinBL.setMode( cHwPort::Out );
  pinBL.clr(); // backlight off
  init();
  pinBL.set(); // backlight on
}

//-------------------------------------------------------------------
void cHwDisp_SPFD5408Bspi::clear( void )
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
__inline void cHwDisp_SPFD5408Bspi::maxWindow( void )
{
  if( !isMaxWindow )
  {
    // Define plotting area
    writeReg( 0x50,        0 ); // Window Horizontal RAM Address Start
    writeReg( 0x51, HEIGHT-1 ); // Window Horizontal RAM Address End
    writeReg( 0x52,        0 ); // Window Vertical RAM Address Start
    writeReg( 0x53,  WIDTH-1 ); // Window Vertical RAM Address End

    isMaxWindow = true;
  }
}

//---------------------------------------------------------------
__inline void cHwDisp_SPFD5408Bspi::setArea( WORD x,
                                            WORD y,
                                            WORD w,
                                            WORD h )
{
  // Define plotting area
  writeReg( 0x50, y     ); // Window Horizontal RAM Address Start
  writeReg( 0x51, y+h-1 ); // Window Horizontal RAM Address End
  writeReg( 0x52, x     ); // Window Vertical RAM Address Start
  writeReg( 0x53, x+w-1 ); // Window Vertical RAM Address End

  // Set start coordinates
  writeReg( 0x20, y );     // GRAM address Set Horizontal Address
  writeReg( 0x21, x );     // GRAM address Set Vertical Address

  // Start data transfer (auto-increment)
  writeCmd( 0x22 );        // Write Data to GRAM (command part only)

  isMaxWindow = false;
}

//---------------------------------------------------------------
__inline void cHwDisp_SPFD5408Bspi::setPixel( WORD color,
                                             WORD x,
                                             WORD y )
{
  maxWindow();

  // Set start coordinates
  writeReg( 0x20, y );     // GRAM address Set Horizontal Address
  writeReg( 0x21, x );     // GRAM address Set Vertical Address
  writeReg( 0x22, color ); // Write Data to GRAM
}

//---------------------------------------------------------------
__inline void cHwDisp_SPFD5408Bspi::setPixel( WORD color )
{
  // Write color with auto increment
  writeDat( color ); // Write Data to GRAM (data part only)
}

//---------------------------------------------------------------
void cHwDisp_SPFD5408Bspi::init( void )
{
  cSystem::delayMilliSec( 50 );

  //----------
  // Power off
  //----------
  writeReg(0x07, 0); // Display Control: OFF

  //------------------------------
  // Initialize display controller
  //------------------------------
  writeReg(0x01, // Driver Output Control Register
                 (1<<8));    // SS=1

  writeReg(0x02, // LCD Driving Waveform Control
                 (6<<8));    // B/C=1: 1-line inversion

  writeReg(0x04, // Scaling Control register
                 0);         // No scaling

  writeReg(0x08, // Display Control 2
                 (0x07<<0)   // 7 lines back porch
                |(0x02<<8)); // 2 lines front porch

  writeReg(0x09, // Display Control 3
                 0);         // No scan cycle in non-display area

  writeReg(0x0A, // Frame Cycle Control
                 0);        // Output FMARK disable

  writeReg(0x0C, // External Display Interface Control 1: Still pictures
                 (0<<0)     // RGB Interface Mode: 18-bit RGB
                |(0<<4)     // Display Interface: Internal clock operation
                |(0<<8));   // Interface for RAM Access: System interface

  writeReg(0x0D, // Frame Maker Position
                 0);        // RAM data write cycle: immediate

  writeReg(0x0F, // External Display Interface Control 2
                 (0<<0)     // DPL: rising edge of the DOTCLK
                |(0<<1)     // EPL: low active
                |(0<<3)     // HSPL: low active
                |(0<<4));   // VSPL: low active

  //------------------
  // Power On sequence
  //------------------
  writeReg(0x10, 0); // Reset Power Control 1
  writeReg(0x11, 0); // Reset Power Control 2
  writeReg(0x12, 0); // Reset Power Control 3
  writeReg(0x13, 0); // Reset Power Control 4

  cSystem::delayMilliSec( 200 ); // Discharge cap power voltage

  writeReg(0x10, // Power Control 1
                 (0<< 1)  // SLP:  No sleep mode
                |(0<< 2)  // DSTB: No standby mode
                |(3<< 4)  // AP:   OP bias current=1.0
                |(1<< 7)  // APE:  Enable liquid crystal power supply
                |(2<< 8)  // BT:   see table
                |(1<<12));// SAP:  Enable gamma voltage generation circuit

  writeReg(0x11, // Power Control 2
                 (7<<0)  // VC:  1.00 x VCI
                |(0<<4)  // DC0: step-up freq. = Oscillation clock / 16
                |(0<<8));// DC1: DC/DC charge pump circuit 1 freq. = Oscillation clock

  cSystem::delayMilliSec( 50 );

  writeReg(0x12, // Power Control 3
                 (5<<0)  // VRH:    VREG1OUT = VCIx1.85
                |(1<<7)  // VREG1R: VCIR (internal) as reference voltage
                |(1<<8));// ---

  cSystem::delayMilliSec( 50 );

  writeReg(0x13, // Power Control 4
                 (0x14<<8));//VDV: VREG1OUT x 1.10

  writeReg(0x29, // NVM read data 2 (factor for generating VCOMH)
                  (0x0E<<0));// VCM1: VREG1OUT x 0.83

  writeReg(0x2A, // NVM read data 3 (factor for generating VCOMH)
                   (0<<0)   // VCM2: ---
                  |(0<<0)); // VCMSEL: use VCM1

  cSystem::delayMilliSec( 50 );

  //------------------
  // Set Driver Output
  //------------------
  writeReg(0x60, // Driver Output Control
                  (   0<< 0)  // SCN: Scan Start Position = G1
                 |(0x27<< 8)  // NL:  Display size 720x320 dots
                 |(   0<<15));// GS:  Gate driver shift G1 to G3

  writeReg(0x61, // Driver Output Control
                  (1<<0)  // REV: see table
                 |(0<<1)  // VLE: no scrolling function
                 |(0<<2));// NDL: 0

  writeReg(0x6A, // Vertical Scroll Control
                  0); // VL: no scrolling

  //------------------------
  // Partial Display Control
  //------------------------
  // Partial Display 1
  writeReg(0x80, 0x0000); // PTDP0, Display Position
  writeReg(0x81, 0x0000); // PTSA0, RAM Address Start
  writeReg(0x82, 0x0000); // PTEA0, RAM Address End

  // Partial Display 2
  writeReg(0x83, 0x0000); // PTDP1, Display Position
  writeReg(0x84, 0x0000); // PTSA1, RAM Address Start
  writeReg(0x85, 0x0000); // PTEA1, RAM Address End

  //--------------
  // Panel Control
  //--------------
  writeReg(0x90, // Panel Interface Control 1
                  (0x10<<0)  // RTNI: 16 clocks
                 |(   0<<8));// DIVI: fosc / 1

  writeReg(0x92, // Panel Interface Control 2
                  (0<<8));   // NOWI: 0 clocks

  writeReg(0x93, // Panel Interface control 3
                  (3<<0));   // MCPI: 0 clocks

  writeReg(0x95, // Panel Interface control 4
                  (0x10<<0)  // RTNE: 16 clocks
                 |(   1<<8));// DIVE: fosc / 4

  writeReg(0x97, // Panel Interface Control 5
                  (0<<8));   // NOWE: 0 clocks

  writeReg(0x98, // Panel Interface Control 6
                  (0<<0));   // MCPE: 0 clocks

  //-----------------
  // Set GRAM control
  //-----------------
  writeReg(0x03, // Entry Mode
                 (1<<3)   // AM:     data write = vertical direction
                |(3<<4)   // I/D:    address counter = decrement vert / decrement hor
                |(0<<7)   // ORG:    start adress = window start addr
                |(1<<12)  // BGR:    inverse RGB allocation
                |(0<<14)  // DFM:    ---
                |(0<<15));// TRIREG: ---

  isMaxWindow = false;

  maxWindow();

  //--------------
  // Start Display
  //--------------
  writeReg(0x07, // Display Control
                  (1<< 1)  // D1:   normal display, ON
                 |(0<< 3)  // COL:  color mode = normal
                 |(1<< 4)  // DTE:  VGH/VGL
                 |(1<< 8)  // BASEE:Base image is displayed on LCD
                 |(0<<12));// PTDE: Partial image 1=off, 2=off
}

//-------------------------------------------------------------------
__inline void cHwDisp_SPFD5408Bspi::writeCmd( WORD cmd )
{
  BYTE buf[] = { (   0x70   // Device ID code
                   |(0<<1)  // RS: Index register
                   |(0<<0)),// RW: write
                  (BYTE)(cmd>>8),
                  (BYTE)(cmd&0xFF) };

  spi.write( buf, sizeof(buf) );
}

//-------------------------------------------------------------------
__inline void cHwDisp_SPFD5408Bspi::writeDat( WORD dat )
{
  BYTE buf[] = { (  0x70     // Device ID code
                   |(1<<1)   // RS: Control register
                   |(0<<0)), // RW: write
                 (BYTE)(dat>>8),
                 (BYTE)(dat&0xFF) };

  spi.write( buf, sizeof(buf) );
}

//-------------------------------------------------------------------
 __inline void cHwDisp_SPFD5408Bspi::writeReg( BYTE reg, WORD val )
{
  writeCmd( reg );
  writeDat( val );
}

//EOF
