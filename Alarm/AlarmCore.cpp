#include "AlarmCore.h"

AlarmCore::AlarmCore()
{
	_taskQueue = new PrioritySortedAList<Task*>(MAX_TASK_COUNT);
	_alarmState = true;
}

AlarmCore::~AlarmCore()
{
}

void AlarmCore::work()
{
	while (!_taskQueue->isEmpty()) {
		if (millis() > _taskQueue->getMaxPriority()) {
			Task* varTaskToComplete = _taskQueue->peekItem();
			varTaskToComplete->doTask();
			//varTaskToComplete->planYourSelf(_taskQueue);
			delete varTaskToComplete;
		}
	}
}

PrioritySortedAList<Task*>* AlarmCore::getTaskQueue()
{
	return _taskQueue;
}

bool AlarmCore::getAlarmState()
{
	return _alarmState;
}


