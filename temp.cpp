#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include "val.h"
#include "temp.h"

using namespace std;

void temperature_t::enterTemp() {
	string userInput;
	string validInput = "[+-]?[0-9]+";
	do {
		cout << file.textFile["getTemp"]  << endl;
		getline(cin, userInput);
	} while (!valid_input(userInput, validInput));

	stringstream(userInput) >> this->temperature;
}

void temperature_t::printTemp() {
	cout << temperature<< " F"<<endl;
}

