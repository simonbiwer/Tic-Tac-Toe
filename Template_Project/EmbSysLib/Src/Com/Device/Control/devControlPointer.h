//*******************************************************************
/*!
\file   devControlPointer.h
\author Thomas Breuer
\date   12.04.2011
*/

//*******************************************************************
#ifndef _DEV_CONTROL_POINTER_H
#define _DEV_CONTROL_POINTER_H

//*******************************************************************
#include "Com/Hardware/Display/Touch.h"

//*******************************************************************
/*!
\class   cDevControlPointer

Screen pointer (e.g. touchscreen)

\example cDevControlPointer.cpp
*/
class cDevControlPointer
{
  public:
    //---------------------------------------------------------------
    /*!
    \class cData

    Data structure with actual pointer state
    */
    class cData
    {
      public:
        //-----------------------------------------------------------
        /*! Pointer status flags
        */
        typedef enum
        {
          NONE     = 0,            //!< No event
          PRESSED  = 0x01,         //!< Pointer is pressed
          MOVE_X   = 0x02|PRESSED, //!< X-Move with more than 15steps
          MOVE_Y   = 0x04|PRESSED, //!< Y-Move with more than 15steps
          CTRL_DWN = 0x10,         //!< Pointer is activated (event)
          CTRL_UP  = 0x20          //!< Pointer is released (event)
        } Flags;

        //-----------------------------------------------------------
        WORD  posX;  //!< X-Position of pointer
        WORD  posY;  //!< Y-Position of pointer
        int   delta; //!< Moved distance
        Flags flags; //!< Event and status flags
    };

    //---------------------------------------------------------------
    /*! Initialize pointer device with cHwTouch hardware
    */
    cDevControlPointer( cHwTouch &touch //!< Reference to hardware
               );

    //---------------------------------------------------------------
    /*! Read new data from hardware
        \return Actual pointer state
    */
    virtual cData get( void );

  private:
    //---------------------------------------------------------------
    cHwTouch &touch;
    BYTE      isTouchedPrev;
    cData     data;
    int       posXprev;
    int       posYprev;

};

#endif
