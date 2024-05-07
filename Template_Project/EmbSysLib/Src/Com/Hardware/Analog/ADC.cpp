//*******************************************************************
/*!
\file   ADC.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/


//*******************************************************************
#include "ADC.h"

//*******************************************************************
//
// cHwADC
//
//*******************************************************************
//-------------------------------------------------------------------
cHwADC::cHwADC( BYTE numIn, cHwTimer *tPtrIn )
{
  if( tPtrIn ) // update by timer ?
  {
    tPtrIn->add( this ); // add to update list
  }

  currentCh      = 0;
  currentId      = 0;
  numActivatedCh = 0;
  numOfChannels  = numIn;
  result[0]      = new WORD[numIn];
  result[1]      = new WORD[numIn];
  chList         = new BYTE[numIn];
  idx            = 0;
  isRunning      = false;
}

//-------------------------------------------------------------------
void cHwADC::enable( BYTE ch, BYTE para )
{
  if(    ch             < numOfChannels )  // is requested channel supported?
  {
      for(int i=0;i<numActivatedCh;i++)
          if( chList[i]  == ch)
          {
              configCh( ch, para );
              return;
          }


      if( numActivatedCh < numOfChannels )  //
      {
        result[0][numActivatedCh] = 0;
        result[1][numActivatedCh] = 0;
        chList[numActivatedCh++]  = ch; // add to list
        configCh( ch, para );                 // call hardware configuration
      }
  }
}

//-------------------------------------------------------------------
inline WORD cHwADC::get( BYTE ch )
{
  cSystem::disableInterrupt();    // the method is may called from a
                                  // different task context
  WORD ret = result[idx?0:1][ch]; // get result of this ch

  cSystem::enableInterrupt();

  return( ret );
}

//-------------------------------------------------------------------
inline BYTE cHwADC::getNumberOfChannels( void )
{
  return( numOfChannels );
}

//-------------------------------------------------------------------
inline void cHwADC::update( void )
{
  if( numActivatedCh && !isRunning ) // while sampling is running, we
                                     // must not update. Otherwise it
                                     // stops actual scan
  {
    currentId = 0;                   // start with first one
    currentCh = chList[currentId];   // get channel from list
    idx = idx?0:1;                   // switch result buffer
    isRunning = true;                // set flag ...
    startCh( currentCh );            // ... and start with sampling
  }
}

//-------------------------------------------------------------------
inline void cHwADC::isr( void )
{
  result[idx?1:0][currentCh]       // get Result from HW and
    = getResult();                 // store it in result
                                   // buffer
  currentId++;                     // next channel

  if( currentId < numActivatedCh ) // is there a next one?
  {
    currentCh = chList[currentId]; // get next ch from list
    startCh( currentCh );          // start with sampling
  }
  else                             // ready, all channels are sampled
  {
    currentId = 0;
    currentCh = chList[currentId];
    isRunning = false;
  }
}

//EOF
