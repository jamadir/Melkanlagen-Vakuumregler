#include "Arduino.h"
#include "hardwareIO.h"

pressureinput::pressureinput(int pin, float offset, float scale) {
  pin = pin;
  offset = offset;
  scale = scale;
  analogReference(INTERNAL);
}

float pressureinput::getpressure() {
  float voltage = analogRead(pin) * 0.0051;
  float pressure = voltage * 0.4 + 0.5;
  return pressure;
}


freqoutput::freqoutput(int pin, int maxfreq) {
  pin = pin;
  maxfreq = maxfreq;
}

void freqoutput::setfreq(float frequency) {
  int frequency_PWM = frequency * 4.25;
  analogWrite(pin, frequency_PWM);
}