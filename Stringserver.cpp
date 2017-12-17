#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Stringserver.h"
#include "val.h"

using namespace std;
string Stringserver::language = "";

map<string, string> Stringserver::textFile;
//open txt files based on user response & breakdown into keys/values
void Stringserver:: openFile(string lang) {
	string line, key, value;
	ifstream myFile;
	if (lang == "english" || lang == "English") 
		 myFile.open("text_en.txt");
	else if (lang == "spanish" || lang == "Spanish")
		 myFile.open("text_sp.txt");

		if (myFile.fail()) cout << "not open\n";
		else {

			while (myFile.good())
			{
				getline(myFile, line);
				key = line.substr(0, line.find(";"));
				value = line.substr(line.find(";") + 1);

				textFile[key] = value;
			}
			myFile.close();
			myFile.clear();
		}//end else
}

void Stringserver:: enterLanguage() {
	string userInput;
	string validInput = "English|english|Spanish|spanish";
	do {
		cout << "Enter language you prefer // Que idioma prefieres? (English / Spanish): " << endl;
		getline(cin, userInput);
	} while (!valid_input(userInput, validInput));

	stringstream(userInput) >> Stringserver::language;
}


