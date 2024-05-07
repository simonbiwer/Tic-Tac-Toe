//*******************************************************************
/*!
\file   devMotorDirection.h
\author Thomas Breuer
\date   22.02.2019
*/

//*******************************************************************
#ifndef _DEV_MOTOR_DIRECTION_H
#define _DEV_MOTOR_DIRECTION_H

//*******************************************************************
/*!
\class   cDevMotorDirection


\example
*/
class cDevMotorDirection : public cDevMotor
{
  private:
    //---------------------------------------------------------------
    cDevDigital    &cw;
    cDevDigital    &ccw;
    cDevAnalogOut  &pwm;

  public:
    //---------------------------------------------------------------
    // Konstruktor
    //
    cDevMotorDirection( cDevDigital    &cw,
                        cDevDigital    &ccw,
                        cDevAnalogOut  &pwm );

  public:
    //---------------------------------------------------------------
    /*!
    */
    virtual void run( float power );

    //---------------------------------------------------------------
    /*!
    */
 	  virtual void brake( void );

};

#endif
