#pragma once

#include "Arduino.h"

class PirSensor
{
	byte _pirPin;
	String _roomName;
public:
	PirSensor(byte pirPin, String roomName);
	~PirSensor();

	bool getSensValue();
	byte getPirPin();
	String getRoomName();
};

