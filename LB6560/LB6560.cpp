/*
LB6560.cpp - Library for driving step motor using board LB6560.
Created by Feliks 7/19/2016.

Functions describtion:
private:
  lock() - Lock the temp motor. Torque on the step motor.
public:
  start() - restart the step motor.
  stop() - Stop the step motor. No torque on the step motor.
    * Important: Need start() to restart the step motor.
  run(int steps, int velocity) - run 'steps' at 'velocity' with 'dir' direction.
  	‘velocity’ is inversely proportional to real rpm. Namely, higher 'velocity', low rpm.
  	* Important: 'velocity' > 400. Or pocket loss will occur.
    * Important: Need start() to restart the step motor.
  dir(bool dir) - 1 as closkwise, 0 as counterclockwise.
*/

  #include "Arduino.h"
  #include "LB6560.h"

  stepMotor::stepMotor(int EN, int CW, int CLK)
  {
    _pinEN = EN;
    _pinCW = CW;
    _pinCLK = CLK;
    _stepCount = 0;
    _steps = 0;
  _velocity = 500; // default velocity
  pinMode(_pinEN,OUTPUT);
  pinMode(_pinCW,OUTPUT);
  pinMode(_pinCLK,OUTPUT);
  digitalWrite(_pinEN,LOW); // LOW enable work
  digitalWrite(_pinCW, LOW); //LOW clockwise 
}

void stepMotor::dir(bool dir)
{
  if(dir == 0)   digitalWrite(_pinCW, HIGH);
  else if(dir == 1)   digitalWrite(_pinCW, LOW);
}

void stepMotor::run(int steps, int velocity)
{
  if(_stepCount < steps)
  {
    digitalWrite(_pinCLK, LOW);
    delayMicroseconds(velocity);
    digitalWrite(_pinCLK, HIGH);
    delayMicroseconds(velocity);
    _stepCount += 1; 
  }
  else
  {
    lock();
  }
}

void stepMotor::lock()
{
  digitalWrite(_pinCLK,HIGH);
  delay(1);
}

void stepMotor::stop()
{
  digitalWrite(_pinEN,HIGH);
}

void stepMotor::start()
{
  digitalWrite(_pinEN,LOW);
  _stepCount = 0;
}
