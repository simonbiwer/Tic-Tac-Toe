//*******************************************************************
/*!
\file   devAnalog.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
//
// cDevAnalog
//
//*******************************************************************
//-------------------------------------------------------------------
cDevAnalog::cDevAnalog( BYTE  channelIn,
                        float gainIn,
                        float offsetIn )
{
  channel = channelIn;
  gain    = gainIn;
  offs    = offsetIn;
}

//EOF
