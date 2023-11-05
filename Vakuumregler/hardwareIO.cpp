#include "Arduino.h"
#include "hardwareIO.h"

pressureinput::pressureinput(int pin, float offset, float scale) {
  _pin = pin;
  _offset = offset;
  _scale = scale;
  analogReference(INTERNAL);
}

float pressureinput::getpressure() {
  int readval = analogRead(_pin);
  float voltage = readval * 0.0051 * 0.47;
  float pressure = voltage * 0.4 + 0.5;
  // Serial.print("anR: ");
  // Serial.print(analogRead(A0));
  // Serial.print(_pin);
  // Serial.print(A0);

  // Serial.print(" vlt: ");
  // Serial.print(voltage);
  // Serial.print(" drk: ");
  // Serial.println(pressure);
  return pressure;
}


freqoutput::freqoutput(int pin, int maxfreq) {
  _pin = pin;
  _maxfreq = maxfreq;
}

void freqoutput::setfreq(float frequency) {
  int frequency_PWM = frequency * 4.25;
  Serial.print(" fpwm:\t");
  Serial.print(frequency_PWM);
  analogWrite(3, frequency_PWM);
  
}