#pragma once
#include <string>
#include "Stringserver.h"
using namespace std;

 class wind_t {
 public: 
	 int speed;
	string direction;
	void enterWind();
	void enterDirection();
	void enterSpeed();
	void printWind();
	Stringserver file;
 };

