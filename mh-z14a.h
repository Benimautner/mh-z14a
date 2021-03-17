
#include <Arduino.h>

#define RXD2 16
#define TXD2 17

#define Z14A_OK 0
#define Z14A_OUT_OF_BOUNDS -1

class Z14A {
    public:
        Z14A();
        int init();
        int getValue(int& co2_concentration);

    private:
        //HardwareSerial* Serial2;
        int sendCommand(unsigned char* command, int len);
        int readValueFromSerial(char* value, int len);
        int convertRawDataToInt(char* value, int len); 
};
