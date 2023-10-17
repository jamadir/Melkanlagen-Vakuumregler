#include "hardwareIO.h"
#include <PID_v1.h>

#define PWMpin 5
#define pressurepin 10

#define psoffset 0.5
#define psscale 0.4
#define regelzielprozent 0.9


pressureinput Drucksensor(pressurepin, 0.5, 0.4);
freqoutput Wechselrichter(PWMpin, 60);


double Setpoint, Input, Output;
double Kp = 2, Ki = 5, Kd = 1;
PID PIDregler(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup() {

  Wechselrichter.setfreq(60);
  delay(10000);
  float regelziel = regelzielprozent * Drucksensor.getpressure();

  Input = regelziel / regelzielprozent;
  Setpoint = regelziel;
  PIDregler.SetMode(AUTOMATIC);
}

void loop() {

  Input = Drucksensor.getpressure();
  PIDregler.Compute();

  float frequenz = map(Output, 0, 1.1, 0, 60);  //Zusammenhang messen
  Wechselrichter.setfreq(frequenz);
}
