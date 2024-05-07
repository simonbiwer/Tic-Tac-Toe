//*******************************************************************
/*!
\file   devControlEncoder.cpp
\author Thomas Breuer
\date   12.04.2011
*/

//*******************************************************************
//
// cDevControlEncoder
//
//*******************************************************************
//-------------------------------------------------------------------
cDevControlEncoder::cDevControlEncoder( cDevDigital *btnCtrlIn,
                          cHwTimer    *timerPtr )

: fifo( 20 ),
  btnCtrl( btnCtrlIn )

{
  if(timerPtr)
  {
    timerPtr->add(this);
  }
}

//-------------------------------------------------------------------
cDevControlEncoder::tEvent cDevControlEncoder::get( void )
{
  if( fifo.isEmpty() )
  {
    return( NONE );
  }
  else
  {
    tEvent event = NONE;
    fifo >> event;
    return( event );
  }
}

//-------------------------------------------------------------------
void cDevControlEncoder::update( void )
{
  if( !fifo.isFull() )
  {
    switch( getIncrement() )
    {
      case LEFT:  fifo << LEFT;    break;
      case RIGHT: fifo << RIGHT;   break;
      default:                     break;
    }
  }

  if( !fifo.isFull() )
  {
    switch( getCtrl() )
    {
      case CTRL_DWN:  fifo << CTRL_DWN;  break;
      case CTRL_UP:   fifo << CTRL_UP;   break;
      default:                           break;
    }
  }
}

//-------------------------------------------------------------------
cDevControlEncoder::tEvent cDevControlEncoder::getCtrl( void )
{
  if( btnCtrl )
  {
    switch( btnCtrl->getEvent() )
    {
      case cDevDigital::ACTIVATED:
        return( CTRL_DWN );
      case cDevDigital::RELEASED:
        return( CTRL_UP );
    }
  }
  return( NONE );
}

//EOF
