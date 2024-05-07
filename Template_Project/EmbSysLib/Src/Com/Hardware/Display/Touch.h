//*******************************************************************
/*!
\file   Touch.h
\author Thomas Breuer
\date   10.03.2013
*/

//*******************************************************************
#ifndef _HW_TOUCH_H
#define _HW_TOUCH_H

//*******************************************************************
/*!
\class cHwTouch

\brief Abstract class supporting touch sensor of graphic displays

The display position is given by the coordinates (x,y), with a 
starting point in the (left,top)-corner

Derived classes should at least:
 - initialize the hardware inteface
 - implement the method update() 
 - set the member variables xpos, ypos, isTouchedFlag

\example cHwTouch.cpp
*/
class cHwTouch
{
  protected:
    //---------------------------------------------------------------
    // Initialize the touch controller
    // width:  Display area width [pixel]
    // height: Display area height [pixel]
    cHwTouch( WORD width, 
              WORD height );

  public:
    //---------------------------------------------------------------
    /*! Update coordinates and flags. This method must be called to 
        read new data from the touch controller
    */
    virtual void update( void ) = 0;

    //---------------------------------------------------------------
    /*! Get x-position of the point, where the display is touched
        \return 
                - X position, if touched
                - 0, if display is not touched
    */
    virtual WORD getPosX( void );

    //---------------------------------------------------------------
    /*! Get y-position of the point, where the display is touched
        \return 
                - Y position, if touched
                - 0, if display is not touched
    */
    virtual WORD getPosY( void );

    //---------------------------------------------------------------
    /*! Return wether the display is touched or not
        \return
                - false: Display is NOT touched
                - true:  Display is touched
    */
    virtual BYTE isTouched( void );

  protected:
    //---------------------------------------------------------------
    WORD xPos;
    WORD yPos;
    BYTE isTouchedFlag;

    WORD width;
    WORD height;

}; //cHwTouch;

#endif
