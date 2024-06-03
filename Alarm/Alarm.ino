/*
 Name:		Alarm.ino
 Created:	7/6/2022 4:29:46 PM
 Author:	qUiet
*/

#include "AList.h"
#include <ArduinoQueue.h>

#include "AlarmCore.h"
#include "PirControlTask.h"

int pirPin = 8; // toto mam zapojene teraz
int pirStat = 0;

AlarmCore* core;
AList<PirSensor*>* v;
//PirSensor* sens;


// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	v = new AList<PirSensor*>(15);
	
	core = new AlarmCore();
	String room = " Obyvacka ";
	//sens = new PirSensor(pirPin, room);
	v->push(new PirSensor(8, "Obyvacka"));
	v->push(new PirSensor(9, "Moja Izba"));

	core->getTaskQueue()->insert(3000, new PirControlTask(core, v));
	
}

void loop() {
	for (PirSensor* sensor : *v) {
		Serial.println(sensor->getRoomName());
	}
	core->work();
}
