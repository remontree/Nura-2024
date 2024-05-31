#pragma once

#include<string.h>
#include<stdint.h>

#define READ_ONLY 0
#define WRITE_ONLY 1
#define READ_AND_WRITE 2

class Sensor{
public:
    Sensor(int8_t sensorMode){
        _sensorMode = sensorMode;
        _dataLength = 0;
        _data = NULL;
    }

    Sensor(int8_t sensorMode, int8_t dataLength){
        _sensorMode = sensorMode;
        _dataLength = dataLength;
        _data = new int8_t[_dataLength];
    }

    virtual void updateData() = 0;
    virtual void writeData() = 0;
    virtual int8_t *readData() = 0;
    
    int8_t getDataLength(){
        return _dataLength;
    }

    int8_t getSensorMode(){
        return _sensorMode;
    }
    
private:
    int8_t *_data;
    int8_t _dataLength, _sensorMode;
};