#include <mh-z14a.h>

Z14A sensor;

void setup() {
  sensor.init();
}

void loop() {
  int co2Value = 0;
  if(sensor.getValue(co2Value) == Z14A_OK) {
    Serial.println("CO2 Value: " + co2Value);
  } else {
    Serial.println("Something went wrong!");
  }

  delay(1000);
}

