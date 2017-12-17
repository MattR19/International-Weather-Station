#pragma once
#include "stdafx.h"
using namespace std;

class mRodriguezWeatherStation {
	public:
		mRodriguezWeatherStation();
	int enterSizeOfArray();
	void setArrays(int size);
	int enterMenu();
	int mainWeather();
	string getStationName();
	int sval , numElements , i ;
	string stationName = "", windDirection = "";
	int currentTemp, windSpeed, sizeOfArray=0;
	int *tempArray;
	int *speedArray;
	string *directionArray;
	int index = 0, maxArray = 0;
	weatherMeasurement_t *report;
	void printWeather();
	Stringserver obj;
};