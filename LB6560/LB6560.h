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

#ifndef LB6560_h
#define LB6560_h

#include "Arduino.h"

  class stepMotor
  {
  private:
    int _pinEN;
    int _pinCW;
    int _pinCLK;
    long int _steps;
    int _velocity;
    long int _stepCount;
    void lock();
  public:
    stepMotor(int pinEN, int pinCW, int pinCLK);
    void dir(bool dir);
    void run(int steps, int velocity);
    void stop();
    void start();
  };

#endif