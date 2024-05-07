//*******************************************************************
/*!
\file   devMotor.h
\author Thomas Breuer
\date   22.02.2019
*/

//*******************************************************************
#ifndef _DEV_MOTOR_H
#define _DEV_MOTOR_H

//*******************************************************************
/*!
\class   cDevMotor


\example 
*/
class cDevMotor
{
  public:
    static const WORD maxPwr = 1000;
    
  protected:
    //---------------------------------------------------------------
    // Konstruktor
    //
    cDevMotor( void );

  public:
    //---------------------------------------------------------------
    /*! 
    */
    virtual void run( float power ) = 0;

    //---------------------------------------------------------------
    /*! 
    */
 	  virtual void brake( void ) = 0;

};

#endif
