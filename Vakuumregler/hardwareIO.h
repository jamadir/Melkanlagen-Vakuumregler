#include <Arduino.h>

class pressureinput {
private:
  int pin;
  float offset;
  float scale;

public:
  pressureinput(int pin, float offset, float scale);
  float getpressure();
};


class freqoutput {
private:
  int pin;
public:
  freqoutput(int pin, int maxfreq);
  void setfreq(float frequency);
};