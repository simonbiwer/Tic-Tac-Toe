//*******************************************************************
/*!
\file   Port_PCF8574.cpp
\author Thomas Breuer
\date   11.03.2011
*/

//*******************************************************************
// 
// cHwPort_PCF8574
//
//*******************************************************************
//-------------------------------------------------------------------
cHwPort_PCF8574::cHwPort_PCF8574( cHwI2Cmaster &i2cIn, 
                                  BYTE          hwAddrIn,
                                  cHwTimer     *tPtrIn) 
: cHwPort() , i2c(i2cIn, baseAdr | ( (hwAddrIn&maskAdr) << 1 ))

{
  tPtr = tPtrIn;
  if( tPtr )
  {
    tPtr->add( this ); // register object at timer
  }
  dir = 0x00;
}

//-------------------------------------------------------------------
void cHwPort_PCF8574::update( void )
{
  valueIn = i2c.read( );
  i2c.write( valueOut );
}

//-------------------------------------------------------------------
void cHwPort_PCF8574::setDir( MTYPE mask )
{
//  cSystem::disableInterrupt();

  // configure a pin as output: 
  // pin is completly controlled by set()/clr()
  
  dir |= mask;
  
  valueOut = (valueOut & dir) | ~dir;
  if( tPtr == 0 )
  {
    i2c.write( valueOut );
  }

//  cSystem::enableInterrupt();
}

//-------------------------------------------------------------------
void cHwPort_PCF8574::clrDir(MTYPE mask)
{
//  cSystem::disableInterrupt();

  // configure a pin as input:
  // set pin to high, external hardware may sets the pin to low

  dir &= ~mask;

  valueOut = (valueOut & dir) | ~dir;
  if( tPtr == 0 )
  {
    i2c.write( valueOut );
  }

//  cSystem::enableInterrupt();
}

//-------------------------------------------------------------------
void cHwPort_PCF8574::set( MTYPE mask )
{
//  cSystem::disableInterrupt();

  valueOut |= mask | ~dir;
  if( tPtr == 0 )
  {
    i2c.write( valueOut );
  }

//  cSystem::enableInterrupt();
}

//-------------------------------------------------------------------
void cHwPort_PCF8574::set( MTYPE mask, MTYPE value)
{
//  cSystem::disableInterrupt();

  valueOut |=  (mask &  value) | ~dir;  
  valueOut &= ~(mask & ~value) | ~dir;
  if( tPtr == 0 )
  {
    i2c.write( valueOut );
  }

//  cSystem::enableInterrupt();
}

//-------------------------------------------------------------------
void cHwPort_PCF8574::clr( MTYPE mask )
{
//  cSystem::disableInterrupt();

  valueOut &= ~mask | ~dir;
  if( tPtr == 0 )
  {
    i2c.write( valueOut );
  }

//  cSystem::enableInterrupt();
}

//-------------------------------------------------------------------
MTYPE cHwPort_PCF8574::get(void)
{

//  cSystem::disableInterrupt();

  valueIn = i2c.read();

//  cSystem::enableInterrupt();

  return(valueIn);
}

// EOF
