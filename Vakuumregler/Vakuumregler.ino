#include "hardwareIO.h"
#include <PID_v1.h>

#define PWMpin 3
#define pressurepin 18

#define psoffset 0.5
#define psscale 0.4
#define regelzielprozent 0.9


pressureinput Drucksensor(pressurepin, 0.5, 0.4);
freqoutput Wechselrichter(PWMpin, 60);


double Setpoint, Input, Output;
double Kp = 1, Ki = 2.5, Kd = 0.2;
PID PIDregler(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup() {

  Wechselrichter.setfreq(50);
  delay(10000);
  int regelziel = regelzielprozent * 10000* Drucksensor.getpressure();

  Input = regelziel / regelzielprozent;
  Setpoint = regelziel;
  PIDregler.SetMode(AUTOMATIC);
}

void loop() {


  int intinput = 10000*Drucksensor.getpressure();
  Input = intinput;
  // Serial.println(100*Drucksensor.getpressure());
  PIDregler.Compute();

  float frequenz = map(Output, 0, 1.1, 0, 50);  //Zusammenhang messen



  Serial.print(" Setp: ");
  Serial.print(Setpoint);
  Serial.print(" Inpt: ");
  Serial.print(Input);
  Serial.print(" Outp: ");
  Serial.print(Output);
  Serial.print(" freq: ");
  frequenz = 5;
  Serial.println(frequenz);
  Wechselrichter.setfreq(frequenz);
}
