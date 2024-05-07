//*******************************************************************
/*!
\file   Disp_ILI9341spi.cpp
\author Thomas Breuer
\date   10.03.2011
*/

//*******************************************************************
// 
// cHwDisp_ILI9341spi
//
//*******************************************************************
//-------------------------------------------------------------------
cHwDisp_ILI9341spi::cHwDisp_ILI9341spi( cHwSPImaster::Device &spiIn, 
                                        cHwPort::Pin         &pinBL,
                                        cHwDisplayFont        fntIn, 
                                        BYTE                  zoomIn )

: cHwDisplayGraphic( fntIn, zoomIn ), 
  spi( spiIn )

{ 
  pinBL.setMode( cHwPort::Out );
  pinBL.clr(); // backlight off
  init();
  pinBL.set(); // backlight on
}

//-------------------------------------------------------------------
void cHwDisp_ILI9341spi::clear( void )
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
void cHwDisp_ILI9341spi::setArea( WORD x, 
                                  WORD y,
                                  WORD w,
                                  WORD h )
{
  writeCmd( 0x2A ); // Column Address Set
  writeDatWord( x     );
  writeDatWord( x+w-1 );

  writeCmd( 0x2B ); // Page Address Set
  writeDatWord( y     );
  writeDatWord( y+h-1 );

  writeCmd( 0x2C ); // Memory Write
}

//---------------------------------------------------------------
void cHwDisp_ILI9341spi::setPixel( WORD color, 
                                   WORD x, 
                                   WORD y ) 
{
  setArea( x, y, 1, 1 );   // set draw position
  writeCmd( 0x2C );        // Memory Write
  writeDatWord( color );
}

//---------------------------------------------------------------
void cHwDisp_ILI9341spi::setPixel( WORD color ) 
{
  writeDatWord( color ); 
}

//---------------------------------------------------------------
void cHwDisp_ILI9341spi::init( void ) 
{ 
  cSystem::delayMilliSec( 20 );

  writeCmd( 0x28 ); // Display OFF
                    //------------

  writeCmd( 0x01 ); // Software Reset
                    //---------------

  cSystem::delayMilliSec( 20 );
  
  writeCmd( 0xCF ); // Power control B
                    //----------------
  writeDat(  0x00 );   // fix

  writeDat( (0x81)     // fix 
           |(0<<3));   // Power control: VGH=VCIx7,VGL=-VCIx4

  writeDat(  3<<4 );   // DC ena: enable ESD protection
  

  writeCmd( 0xED ); // Power on sequence control
                    //--------------------------
  writeDat( (1<<6)     // fix
           |(2<<4)     // CP1 softstart control: 1 frame
           |(1<<2)     // fix
           |(0<<0));   // CP23 softstart control: 3 frame

  writeDat( (0<<4)     // VCL   power on seq.: first frame enable
           |(3<<0));   // DDVDH power on seq.: 4th frame enable

  writeDat( (1<<4)     // VGH power on seq.: 2nd frame enable
           |(2<<0));   // VGL power on seq.: 3rd frame enable

  writeDat( (1<<7)     // DDVDH enhance mode: enable
           |(1<<0));   // fix
  

  writeCmd( 0xE8 ); // Driver timing control A
                    // -----------------------
  writeDat( (1<<7)     // fix
           |(1<<2)     // fix
           |(1<<0));   // NOW: default+1

  writeDat( (0<<4)     // EQ: default-1
           |(1<<0));   // CR: default

  writeDat( (7<<4)     // fix
           |(1<<3)     // fix
           |(1<<0));   // PC: default-1
  

  writeCmd( 0xCB ); // Power control A
                    //----------------
  writeDat(  0x39 );   // fix
  writeDat(  0x2C );   // fix
  writeDat(  0x00 );   // fix

  writeDat( (3<<4)     // fix
           |(4<<0));   // VD: 1.65

  writeDat( (2<<0));   // VBC: 5.6
  

  writeCmd( 0xF7 ); // Pump ratio control
                    //-------------------
  writeDat( (2<<4));   // Ratio: 2xVCI
  

  writeCmd( 0xEA ); // Driver timing control B
                    //------------------------
  writeDat( (0<<6)     // VG_SW_T4: 0
           |(0<<4)     // VG_SW_T3: 0
           |(0<<2)     // VG_SW_T2: 0
           |(0<<0));   // VG_SW_T1: 0

  writeDat( 0x00 );    // fix

    
  writeCmd( 0xC0 ); // Power Control 1
                    //----------------
  writeDat( 0x26);     // VRH: 4.75V
  

  writeCmd( 0xC1 ); // Power Control 2
                    //----------------
  writeDat( 0x01 );    // step-up factor: VCIx2, VCIx7, VCIx3
  

  writeCmd( 0xC5 ); // VCOM Control
                    //-------------
  writeDat( 0x35 );    // VCOMH:  4.025 V
  writeDat( 0x3E );    // VCOML: -0.950 V
  
 
  writeCmd( 0xC7 ); // VCOM Control 2
                    //---------------
  writeDat( (1<<7)     // nVM: adjust enable
           | 0x3E );   // VMF: VMH+62, VML+62
  
   
  writeCmd( 0xB1 ); // Frame Rate Control
                    //-------------------
  writeDat( (0<<0));   // DIVA: fosc
  writeDat(  0x1B );   // RTNA: 70Hz


  writeCmd( 0xB6 ); // Display Function Control
                    //-------------------------
  writeDat( (2<<2)      // PTG: Interval scan
           |(2<<0));    // PT:  AGND

  writeDat( (1<<7)       // REV: normaly white 
           |(0<<6)       // GS:  G1 to G320
           |(0<<5)       // SS:  S1 to S720
           |(0<<4)       // SM:  see table
           |(2<<0));     // ISC: 7 frames

  writeDat( 0x27 );      // NL: 320 lines

  writeDat( 0x00 );      // PCDIV: external fosc = DOTCLK/2 
  

  writeCmd( 0xB7 ); // Entry Mode Set
                    //---------------
  writeDat( (1<<2)     // GON: normal display
           |(1<<1)     // DTE: normal display
           |(1<<0));
  

  writeCmd( 0x3A ); // COLMOD: Pixel Format Set
                    //-------------------------
  writeDat( (5<<4)     // DPI: 16 bits/pixel
           |(5<<0));   // DBI: 16 bits/pixel


  writeCmd( 0x36 ); // Memory Access Control
                    //----------------------
  writeDat( (7<<5)     // MY|MX|MV
                       //  1  1  1 -> 0°
                       //  0  1  0 -> 90°
                       //  0  0  1 -> 180°
                       //  1  0  0 -> 270°
           |(0<<4)     // ML:  vertical refresh order
           |(1<<3)     // BGR: RGB-BGR Order
           |(0<<2));   // MH:  horizontal refresh order
  
  
  writeCmd( 0x11 ); // Sleep Out
                    //----------
     
  cSystem::delayMilliSec( 20 );

  writeCmd( 0x29 ); // Display ON
                    //-----------

  cSystem::delayMilliSec( 20 );
}

//-------------------------------------------------------------------
__inline void cHwDisp_ILI9341spi::writeCmd( BYTE cmd ) 
{
  spi.writeExt( 0, cmd );
}

//-------------------------------------------------------------------
__inline void cHwDisp_ILI9341spi::writeDat( BYTE dat ) 
{
  spi.writeExt( 1, dat );
}

//-------------------------------------------------------------------
 __inline void cHwDisp_ILI9341spi::writeDatWord( WORD dat ) 
{
  spi.writeExt( 1, dat );
}

//EOF
