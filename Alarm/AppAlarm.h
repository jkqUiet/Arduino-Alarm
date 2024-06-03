#pragma once

#include "SDManager.h"
#include "AlarmCore.h"
#include "User.h"

class AppAlarm
{

public:
	AppAlarm();
	~AppAlarm();
	void work();
	bool addTask();

	User* checkDatabase(String& userID);

};

