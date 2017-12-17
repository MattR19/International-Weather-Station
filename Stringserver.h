#pragma once
#include <string>
#include <map>

using namespace std;

class Stringserver {
public:
	static string language;
	static map<string, string> textFile;
	void openFile(string lang);
	void enterLanguage();
};
