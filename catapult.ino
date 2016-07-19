#define stepMotorEN 7
#define stepMotorCW 8
#define stepMotorCLK 9

#include <LB6560.h>

stepMotor shootingMotor(stepMotorEN, stepMotorCW, stepMotorCLK);

int count = 0, dir = 1;

void setup()
{
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
}

void loop()
{
  analogWrite(3,255);
	if (count < 1000)
	{
		shootingMotor.run(200, 1000);
		count += 1;
	}
	else
	{
		count = 0;
		shootingMotor.start();
		if (dir == 1)dir = 0;
		else if (dir == 0) dir = 1;
		shootingMotor.dir(dir);
	}
}
