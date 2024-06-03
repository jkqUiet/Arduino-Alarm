#pragma once

#include "Task.h"
#include "AlarmCore.h"

class SendMessageTask : public Task
{
	String _messageText;
public:
	SendMessageTask(AlarmCore* aCore, String messageText);
	~SendMessageTask();
	//void doTask(ArduinoQueue<Task*>* queue) override;

	void doTask() override;
	//void planYourSelf(ArduinoQueue<Task*>* queue) override;
};

