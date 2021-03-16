#include "mh-z14a.h"

Z14A::Z14A () {
}

int Z14A::init() {
    Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
    //Serial2 = &loc_serial;
    return 0;
}

int Z14A::getValue() {
	unsigned char command[9] = {0xFF, 0x01, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    sendCommand(command, 9);
    char value[9] = {0x00};
    readValueFromSerial(value, 9);
    return convertRawDataToInt(value, 9);
    //return 0;
}

int Z14A::sendCommand(unsigned char* command, int len) {
    char checksum = 0x00;
    for(int i = 1; i < 8; i++) {
        checksum += command[i];
    }
    checksum = 0xFF - checksum;
    checksum += 0x01;
    command[len-1] = checksum;

    Serial2.write(command, len);
    return 0;
}

int Z14A::readValueFromSerial(char* value, int len) {
    Serial2.readBytes(value, len);
    return 0;
}

int Z14A::convertRawDataToInt(char* value, int len) {
    return (int) value[2] * 256 + value[3];
}
