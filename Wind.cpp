#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include "val.h"
#include "Wind.h"

using namespace std;

void wind_t:: enterSpeed() {
	string userInput;
	string validInput = "[0-9]+";
	do {
		cout << file.textFile["getSpeed"]<< endl;
		getline(cin, userInput);
	} while (!valid_input(userInput, validInput));

	stringstream(userInput) >> this->speed;
}

void wind_t:: enterDirection() {
	string result;
	string userInput;
	string validInput = "N|S|E|W|NE|NW|SE|SW|n|s|e|w|ne|nw|se|sw";
	do {
		cout << file.textFile["getDirection"] << endl;
		getline(cin, userInput);
	} while (!valid_input(userInput, validInput));

	stringstream(userInput) >> this->direction;
}

void wind_t::enterWind() {
	//wind_t result;
	enterSpeed();
	enterDirection();

}

void wind_t::printWind() {
	cout << file.textFile["S_wind"] << speed << " mph\n" << file.textFile["D_wind"] << direction << endl;
}