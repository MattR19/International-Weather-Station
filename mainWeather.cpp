#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include "val.h"
#include "Weather_Measurement.h"
#include <fstream>
#include <map>
#include "Stringserver.h"
#include "mRodriguezWeatherStation.h"
#include <iterator>


using namespace std;

map <string, mRodriguezWeatherStation*> stations;
Stringserver obj;
int numElements;
int numCities=0;

//makes new instance of cities and adds it to stations array
mRodriguezWeatherStation * newCity() {
	mRodriguezWeatherStation *newStation = new mRodriguezWeatherStation();
	stations[newStation->getStationName()]=newStation;
	numCities++;
	return newStation;
}

void printCities() {
	map<string, mRodriguezWeatherStation*>::iterator it;

	for (it = stations.begin(); it != stations.end(); it++)
	{
		std::cout << it->first << "\t";  // string (key)
		it->second->printWeather();
	}
}

//menu for "outside" the cities
int newMenu(){
	int result;
	string userInput;
	string validInput = "[1-5]";
	do {
		cout << obj.textFile["EnterNewCity"]<<endl;
		cout << obj.textFile["printAll"] << endl;
		cout << obj.textFile["pickCity"] << endl;
		cout << obj.textFile["quit"] << endl;
		getline(cin, userInput);
	} while (!valid_input(userInput, validInput));
	stringstream(userInput) >> result;
	return result;
}

//finds city given from user and returns it to do more weather readings, printouts, etc
mRodriguezWeatherStation* findCity() {
	//if user's input is = to the key in station's map, return that city
	
	string arrayOfCityNames[5];
	map<string, mRodriguezWeatherStation*>::iterator it;

	for (it = stations.begin(); it != stations.end(); it++)
	{
		std::cout << it->first  // string (key)
			<< ':'
		//	<< it->second   // string's value 
			<< std::endl;
	}
	string myString;
	cout << "which city would you like to manage: ";
	getline(cin, myString);
	stations[myString]->mainWeather();



	/*
	for (int i = 0; i < numCities; i++) {
		if (userInput == arrayOfCityNames[i].getStationName())
			return stations[userInput];
		else
			return NULL;
	}*/
	return NULL;
}

int main() {
	int i = 0;
	//char input[20];
	int sval = 0;
	string myString,userCity;
	mRodriguezWeatherStation *currentStation;
	
	obj.enterLanguage();
	obj.openFile(obj.language);
	
	
	do {
		sval = newMenu();
		switch (sval) {
		case 1:
			//add new station
			currentStation=newCity();
			currentStation->mainWeather();
			//stations[currentStation->getStationName()] = currentStation;
			break;
		case 2:
			//display weather for ALL stations
			printCities();
			break;
		case 3:
			//manage/select weather station
			
			
			
			findCity();
			//finds city to go "back into" city to add or print said weather readings
			break;
		case 4:
			//quit
			exit(0);
			break;
		default: cout << "improper input";

		}
	} while (true);



	return 0;

}
