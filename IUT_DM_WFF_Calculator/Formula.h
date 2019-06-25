#pragma once
#include "Tree.h"
#include <string>
#include <map>
#include <set>
#include <stack>

using std::string;
using std::set;
using std::map;
using std::stack;

class Formula
{

private:
	static const char OPEN_PAR = '(';
	static const char CLOSE_PAR = ')';

	static const char PLUS;
	static const char MINUS;
	static const char MULTIPLY;
	static const char DIVIDE;
	static const char POWER;

	Tree* tree;
	string str;

	static Tree* parse(string);


public:
	Formula(const string &formula);
	~Formula();

	string getString();
	string getPrefixString();
	string getPostfixString();

	static int calcPrefixString(const string prefixString);
	static int calcPostfixString(const string postfixString);

};