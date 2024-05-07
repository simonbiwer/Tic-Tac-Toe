//*******************************************************************
/*!
\file   devControlPointer.cpp
\author Thomas Breuer
\date   12.04.2011
*/

//*******************************************************************
//
// cDevControlPointer
//
//*******************************************************************
//-------------------------------------------------------------------
cDevControlPointer::cDevControlPointer( cHwTouch &touchIn )

: touch( touchIn )

{
  data.flags = cData::NONE;
  data.posX  = 0;
  data.posY  = 0;
  data.delta = 0;
}

//-------------------------------------------------------------------
cDevControlPointer::cData cDevControlPointer::get( void )
{
  touch.update();

  int x = RANGE((short)touch.getPosX(),(short)0,(short)0x7FFF);
  int y = RANGE((short)touch.getPosY(),(short)0,(short)0x7FFF);
  BYTE isTouched = touch.isTouched();

  if( isTouched && !isTouchedPrev )
  {
    data.flags = cData::CTRL_DWN;
    data.posX  = x;
    data.posY  = y;
    data.delta = 0;
    posXprev    = x;
    posYprev    = y;
  }
  else if( !isTouched  && isTouchedPrev )
  {
    data.flags = cData::CTRL_UP;
    data.posX  = x;
    data.posY  = y;
    data.delta = 0;
  }
  else if( isTouched  && isTouchedPrev )
  {
    data.flags = cData::PRESSED;
    data.posX  = x;
    data.posY  = y;
    data.delta = 0;

    if( x != posXprev || y != posYprev )
    {
      if( abs(posXprev-x) > 15 || abs(posYprev-y) > 15 )
      {
        int deltaX = x-posXprev;
        int deltaY = y-posYprev;
        if( abs(deltaX) > abs(deltaY) )
        {
          data.flags = cData::MOVE_X;
          data.delta = deltaX;
        }
        else
        {
          data.flags = cData::MOVE_Y;
          data.delta = -deltaY;
        }
        posXprev = x;
        posYprev = y;
      }
    }
  }
  else
  {
    data.flags = cData::NONE;
    data.delta = 0;
  }
  isTouchedPrev = isTouched ;
  return( data );
}

//EOF
