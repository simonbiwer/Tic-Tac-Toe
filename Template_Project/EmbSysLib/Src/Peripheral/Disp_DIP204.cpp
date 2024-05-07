//*******************************************************************
/*!
\file   Disp_DIP204.cpp
\author Thomas Breuer
\date   10.03.2011
*/

//*******************************************************************
//
// cHwDisp_DIP204
//
//*******************************************************************
//-------------------------------------------------------------------
cHwDisp_DIP204::cHwDisp_DIP204( cHwPort &portIn )

: cHwDisplay( NUM_OF_LINE, NUM_OF_COLUM ), port(portIn)

{
  port.setMode( 0xFF, cHwPort::Out );
  init();
}

//---------------------------------------------------------------
void cHwDisp_DIP204::clear( void )
{
  writeCmd( 0x01 );	// Clear Display
}

//---------------------------------------------------------------
void cHwDisp_DIP204::gotoTextPos( BYTE lineIn, BYTE columIn )
{
  line  = lineIn;
  colum = columIn;
  // Startadresse fuer Display-Speicher schreiben
  if(line < NUM_OF_LINE && colum < NUM_OF_COLUM)
  {
    writeCmd(0x80 | ((line<<5)+(colum&0x1F)) ); // gotoPos, Format: rrrccccc
  }
}

//---------------------------------------------------------------
void cHwDisp_DIP204::putChar( char c )
{
  if(line < NUM_OF_LINE && colum < NUM_OF_COLUM)
  {
    writeDat( c ); // putchar at current pos
    colum++;       // emulate cursor increment
  }
}

//*******************************************************************
//-------------------------------------------------------------------
/*#define DIP204_RES   0x10
#define DIP204_EN    0x20
#define DIP204_RW    0x40
#define DIP204_RS    0x80
*/
//-------------------------------------------------------------------
void cHwDisp_DIP204::init( void )
{
  // LCD reset
  port.clr(       0xFF );
  port.set( DIP204_RES );

  waitBusy();

  // enter 4-bit-mode:
  // send MSB of Function set command with DL = 0
  port.set( DIP204_EN   | 0x02 );
  port.clr( DIP204_EN          );
  port.clr(~DIP204_RES         );

  waitBusy();

  writeCmd(  (1<<5)  // Function set (RE=0)
            |(0<<4)	 //   DL:  4-bit,
            |(0<<3)  //   N :  1-line,
            |(1<<2)  //   RE:  1
            |(0<<1)  //   DH:  dot scroll
            |(0<<0));//   REV: normal

  writeCmd(  (1<<3)  // extended Function set (RE=1)
            |(0<<2)  //  FW:  5-dot font width
            |(1<<1)  //  BW:  inverting cursor
            |(1<<0));//  NW:  4-line display

  writeCmd(  (1<<5)  // Function set (RE=1)
            |(0<<4)	 //   DL:  4-bit,
            |(0<<3)  //   N :  1-line,
            |(0<<2)  //   RE:  0
            |(0<<1)  //   BE:  CG/SEG-RAM blink disable
            |(0<<0));//   LP:  normal mode

  writeCmd(  (1<<0));// Clear Display

  writeCmd(  (1<<3)  // Display On/Off Control
            |(1<<2)  //  D:  display on
            |(0<<1)  //  C:  cursor off
            |(0<<0));//  B:  blink off

  // leaving with RE-Bit = 0
}

//-------------------------------------------------------------------
void cHwDisp_DIP204::waitBusy( void )
{
  BYTE ret;

  do
  {
    port.set(  DIP204_RW|DIP204_EN|DIP204_RES | 0x0F );
    ret = port.get();
    port.clr(~(                    DIP204_RES       ));
    port.set(  DIP204_RW|DIP204_EN|DIP204_RES | 0x0F );
    port.get();
    port.clr(~(                    DIP204_RES       ));
  } while( ret & 0x08);
}

//-------------------------------------------------------------------
void cHwDisp_DIP204::writeCmd( BYTE cmd )
{
  port.set(  DIP204_EN|DIP204_RES | (cmd>>4  ));
  port.clr(  DIP204_EN                        );
  port.clr(~(          DIP204_RES            ));
  port.set(  DIP204_EN|DIP204_RES | (cmd&0x0f));
  port.clr(  DIP204_EN                        );
  port.clr(~(          DIP204_RES            ));
  waitBusy();
}

//-------------------------------------------------------------------
void cHwDisp_DIP204::writeDat( BYTE dat )
{
  port.set(        DIP204_RS|DIP204_EN|DIP204_RES | (dat>>4  ));
  port.clr(                  DIP204_EN                        );
  port.clr((BYTE)~(DIP204_RS|          DIP204_RES            ));
  port.set(        DIP204_RS|DIP204_EN|DIP204_RES | (dat&0x0f));
  port.clr(                  DIP204_EN                        );
  port.clr(~(                          DIP204_RES            ));
  waitBusy();
}

//EOF
