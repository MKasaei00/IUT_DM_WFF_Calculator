#pragma once

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::string;

const unsigned short int MAX_LINES = 20;

string* readFile(unsigned short int &count, const string & fileName, const unsigned short int maxLines);
string readLineFile(const string & fileName);
