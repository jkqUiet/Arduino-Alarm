
#include "PirControlTask.h"
#include "SendMessageTask.h"
#include "CheckIDTask.h"

#include "AlarmCore.h"

PirControlTask::PirControlTask(AlarmCore* aCore, AList<PirSensor*>* sensors) : _sensors(sensors)
{
	Task::_core = aCore;
}

PirControlTask::~PirControlTask()
{
}

void PirControlTask::doTask()
{
	PirSensor* vS = nullptr;
	for (PirSensor* varSensor : *_sensors) {
		/*if (varSensor->getSensValue()) {
			SendMessageTask* varTaskAdding = new SendMessageTask(_core, String("Neznamy pohyb v " + varSensor->getRoomName()));
			_core->getTaskQueue()->enqueue((Task*)varTaskAdding);

		}*/
	}

	if (_core->getAlarmState()) {
		//_core->getTaskQueue()->enqueue(new CheckIDTask());
		_core->getTaskQueue()->insert(millis() + 3000,new PirControlTask(_core, _sensors));
		//_core->getTaskQueue()->enqueue(new PirControlTask(_core, _sensors));
	}

	Serial.println("Pocet senzorov " + String(_sensors->size()));
	for (PirSensor* varSensor : *_sensors) {
		Serial.println(String(varSensor->getRoomName()) +"  "+ String(varSensor->getSensValue()) + " ," + millis());
	}
	Serial.println("Pocet taskov : " + String(_core->getTaskQueue()->size()));
}
/*
void PirControlTask::planYourSelf(ArduinoQueue<Task*>* queue)
{
}*/
