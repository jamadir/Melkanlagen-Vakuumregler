#define hardwareIO_h
#include <Arduino.h>

class pressureinput {
private:
  int _pin;
  float _offset;
  float _scale;

public:
  pressureinput(int pin, float offset, float scale);
  float getpressure();
};


class freqoutput {
private:
  int _pin;
  int _maxfreq;
public:
  freqoutput(int pin, int maxfreq);
  void setfreq(float frequency);
};