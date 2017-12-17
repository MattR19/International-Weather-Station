// mRodriguezWeatherStation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include "val.h"
#include "Weather_Measurement.h"
#include <fstream>
#include "Stringserver.h"
#include "mRodriguezWeatherStation.h"

using namespace std;

mRodriguezWeatherStation::mRodriguezWeatherStation() {
	string myString;
	cout << obj.textFile["Welcome"] << endl;
	getline(cin, myString);
	stringstream(myString) >> stationName;
	numElements = 0;
	sizeOfArray = enterSizeOfArray();
	report = new weatherMeasurement_t[sizeOfArray];
}
string mRodriguezWeatherStation::getStationName() {
	return stationName;
}

void mRodriguezWeatherStation::printWeather() {
	report[0].printWeather();
}

int mRodriguezWeatherStation::enterSizeOfArray() {
	int result;
	string userInput;
	string validInput = "[0-9]+";
	do {
		cout << obj.textFile["arrSize"] << endl;
		getline(cin, userInput);
	} while (!valid_input(userInput, validInput) || userInput == "0");
	stringstream(userInput) >> result;
	return result;
}

void mRodriguezWeatherStation::setArrays(int size) {
	tempArray = new int[size];
	speedArray = new int[size];
	directionArray = new string[size];
	maxArray = size - 1;}

//menu within a city
int mRodriguezWeatherStation::enterMenu() {
	int result;
	string userInput;
	string validInput = "[1-5]";
	do {
	
		cout << "\n"+  obj.textFile["EnterWeather"] << endl;
		cout << obj.textFile["printCurrent"] << endl;
		cout << obj.textFile["printHistory"] << endl;
		cout << obj.textFile["quit"] << endl;
		
		getline(cin, userInput);
	} while (!valid_input(userInput, validInput));

	stringstream(userInput) >> result;
	return result;
}

int mRodriguezWeatherStation::mainWeather() {
	//int sval=0, numElements=0,i=0;
	do {
	
		sval = enterMenu();
		cin.clear();

		switch (sval) {
		case 1:
			i = sizeOfArray - 1;
			while (i > 0) {
				report[i] = report[i - 1];
				i--;
			};
			report[0].enterWeather();

			if (numElements != sizeOfArray) numElements++;
			break;
		case 2:
			if (numElements > 0) report[0].printWeather();
			else	cout << obj.textFile["noElements"] << endl;
			break;
		case 3:
			for (int i = 0; i < numElements; i++) {
				cout << "\n";  report[i].printWeather();
			}
			break;
		case 4:
			return(0);
			break;
		}

	} while (true);
}
