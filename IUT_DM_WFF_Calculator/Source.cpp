#include "Cli.h"
#include "Formula.h"
#include "FileHelper.h"

#include <iostream>
using std::endl;


int main()
{
	CLI cli("cmd" , std::cin , std::cout , 
		[](CLI& cli, const ArgCount &count, const string*words, string &message) -> bool
	{
		//handler function
		if (count > 0)
		{
			if (words[0] == "read" && count == 2)
			{
				string seq = readLineFile(words[1]);
				if (seq.length())
				{
					Formula form(seq);
					string prefix = form.getPrefixString();
					string postfix = form.getPostfixString();
					int res = Formula::calcPrefixString(prefix);
					cli.outStream() << "Expression =>> " << seq << endl;
					cli.outStream() << "Prefix  sequence  =>> " << prefix << endl;
					cli.outStream() << "Postfix sequence  =>> " << postfix << endl;
					cli.outStream() << "result by prefix =>> " << Formula::calcPrefixString(prefix) << endl;
					cli.outStream() << "result by postfix =>> " << Formula::calcPostfixString(postfix) << endl;
					
				}
				else message = "File reading error";
			}
			else return false;
		}
		else return false;

		return true;
	}
		,
		[](CLI& cli)
	{
		//helper function
		cli.printHelpStatement("read", "[file name]");
	}
	);

	cli.maximizeWindow();
	cli.start(true);

	return 0;
}