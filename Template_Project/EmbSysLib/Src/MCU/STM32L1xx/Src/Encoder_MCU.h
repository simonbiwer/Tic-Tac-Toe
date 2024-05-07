//*******************************************************************
/*!
\file   Encoder_MCU.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_ENCODER_MCU_H
#define _HW_ENCODER_MCU_H

//*******************************************************************
#include "Com/Hardware/Timer/Encoder.h"

//*******************************************************************
/*! 
\class cHwEncoder_N

\brief Implementation of encoder in timer 2/3/4

\example cHwTimer.cpp
*/
class cHwEncoder_N : public cHwEncoder
{
  public:
    //---------------------------------------------------------------
    /*! \enum TimerId
        \brief Timer identification
    */
    typedef enum
    {
      TIM_2 = 2,  //!< Timer 2 
      TIM_3,      //!< Timer 3 
      TIM_4,      //!< Timer 4
    } TimerId;

  public:
    //---------------------------------------------------------------
    /*! Instantiate encoder
        \param timerId Timer hardware selection 
        \param mode    Operating mode
    */
    cHwEncoder_N( TimerId timerId, Mode mode );

    //---------------------------------------------------------------
    virtual int get();

  private:
    //---------------------------------------------------------------
    TIM_TypeDef *ptr;
    WORD         cntLast;

}; //cHwEncoder_N

#endif
