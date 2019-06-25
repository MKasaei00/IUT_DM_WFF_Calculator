#include "FileHelper.h"

string * readFile(unsigned short int & count, const string & fileName, const unsigned short int maxLines)
{
	ifstream file(fileName);
	if (file.is_open())
	{
		string * res;
		count = (maxLines) ? (maxLines) : MAX_LINES;
		res = new string[count];

		for (unsigned short int i = 0; i < count; i++)
		{
			if (!std::getline(file, res[i]))	break;
		}
		file.close();
		return res;
	}
	else
	{
		count = 0;
		return nullptr;
	}
}

string readLineFile(const string & fileName)
{
	ifstream file(fileName);
	if (file.is_open())
	{
		string line;
		std::getline(file, line);
		file.close();
		return line;
	}
	else return string();
}