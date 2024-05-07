//*******************************************************************
/*!
\file   devMotorBipolar.h
\author Thomas Breuer
\date   22.02.2019
*/

//*******************************************************************
#ifndef _DEV_MOTOR_BIPOLAR_H
#define _DEV_MOTOR_BIPOLAR_H

//*******************************************************************
/*!
\class   cDevMotorBipolar


\example
*/
class cDevMotorBipolar : public cDevMotor
{
  private:
    //---------------------------------------------------------------
    cDevAnalogOut  &plus;
    cDevAnalogOut  &minus;

  public:
    //---------------------------------------------------------------
    // Konstruktor
    //
    cDevMotorBipolar( cDevAnalogOut &plus,
                      cDevAnalogOut &minus );

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
