#pragma once

class AlarmCore;

class Task {
protected:
	AlarmCore* _core;
public:
	Task() {};
	~Task() {};
	virtual void doTask() = 0;
	//virtual void planYourSelf(ArduinoQueue<Task*>* queue) = 0;
};