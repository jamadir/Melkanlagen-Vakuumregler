#include "hardwareIO.h"
#include <PID_v1.h>

#define PWMpin 3
#define pressurepin 18

#define psoffset 0.5
#define psscale 0.4
#define regelzielprozent 0.9




double Setpoint, Input, Output;
double Kp = 1, Ki = 2.5, Kd = 0.2;
PID PIDregler(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup() {

  analogWrite(PWMpin, 255);
  delay(20000);
  int analogval = 0;

  int c = 0;
  while (c < 10) {
    analogval = analogRead(pressurepin) + analogval;
    c++;
  }
  analogval = analogval / c;


  int regelziel = regelzielprozent * (1024 - analogval);

  Input = regelziel * regelzielprozent;
  Setpoint = regelziel;
  PIDregler.SetMode(AUTOMATIC);
}

void loop() {


  int intinput = 1024 - analogRead(pressurepin);
  Input = intinput;

  PIDregler.Compute();

  float frequenz = map(Output, 0, 1.1, 0, 50);  //Zusammenhang messen



  Serial.print(" Setp: ");
  Serial.print(Setpoint);
  Serial.print(" Inpt: ");
  Serial.print(Input);
  Serial.print(" Outp: ");
  Serial.print(Output);
  Serial.print(" freq: ");
  Serial.println(frequenz);
  analogWrite(PWMpin, Output);
}
