#include "SendMessageTask.h"

SendMessageTask::SendMessageTask(AlarmCore* aCore, String messageText) : _messageText(messageText)
{
	_core = aCore;
}

SendMessageTask::~SendMessageTask()
{
}

void SendMessageTask::doTask()
{
	// TODO odoslanie cez GSM


}

/*void SendMessageTask::planYourSelf(ArduinoQueue<Task*>* queue)
{
}*/
