#include "PirSensor.h"

PirSensor::PirSensor(byte pirPin, String roomName) : _pirPin(pirPin), _roomName(roomName)
{
    pinMode(_pirPin, INPUT);
}

PirSensor::~PirSensor()
{
}

bool PirSensor::getSensValue()
{
    return digitalRead(_pirPin);
}

byte PirSensor::getPirPin()
{
    return _pirPin;
}

String PirSensor::getRoomName()
{
    return _roomName;
}
