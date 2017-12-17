#include "stdafx.h"
#include <regex>
#include <string>

using namespace std;
bool valid_input(string input, string validation) {
	const char* test = input.c_str();
	regex re(validation);
	cmatch match;
	if (regex_match(test, match, re)) return true;
	else return false;
}