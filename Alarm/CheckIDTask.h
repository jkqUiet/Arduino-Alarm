#pragma once

#include "AlarmCore.h"
#include "Task.h"

class CheckIDTask : public Task
{

public:
	CheckIDTask();
	~CheckIDTask();
	void doTask() override;
	//void planYourSelf(ArduinoQueue<Task*>* queue) override;
};

