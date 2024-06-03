#pragma once

#include "PrioritySortedAList.h"

#include "Task.h"
#include "User.h"

#define MAX_TASK_COUNT 20

class AlarmCore
{
	PrioritySortedAList<Task*>* _taskQueue;	
	bool _alarmState;

public:
	AlarmCore();
	~AlarmCore();
	void work();
	PrioritySortedAList<Task*>* getTaskQueue();
	bool getAlarmState();

};

