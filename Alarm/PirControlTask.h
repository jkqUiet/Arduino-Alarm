#pragma once

#include "Task.h"
#include "PirSensor.h"
#include "AList.h"


class PirControlTask : public Task
{
	AList<PirSensor*>* _sensors;

public:
	PirControlTask(AlarmCore* aCore, AList<PirSensor*>* sensors);// , //LinkedList<PirSensor*>* sensors);
	~PirControlTask();
	//void doTask(ArduinoQueue<Task*>* queue) override;
	void doTask() override;
	//void planYourSelf(ArduinoQueue<Task*>* queue) override;
};