#pragma once

#include "Arduino.h"
#include <SPI.h>
#include <SD.h>
#include <ArduinoQueue.h>
#include "Task.h"

class SDManager : Task
{
	int _sdPin;
	File* _file;

public:
	SDManager(int sdPin);
	~SDManager();
	bool openFile(String filePath);
	void closeFile();

	ArduinoQueue<String>* readFile();
};

