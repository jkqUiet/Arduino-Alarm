#pragma once
#include "Arduino.h"

class User
{
	String _name;
	bool _adminType;
	String _cardID;
	String _passCode;
public:
	User(String name, bool adminType, String cardId, String passCode) :
		_name(name), _adminType(adminType), _cardID(cardId), _passCode(passCode) {};
	~User() {};
	String getName() { return _name; };
	String getCardID() { return _cardID; }
	bool getAdminType() { return _adminType; }
	String getPassCode() { return _passCode; }	
};

