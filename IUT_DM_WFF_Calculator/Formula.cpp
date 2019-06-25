#include "Formula.h"

const char Formula::PLUS = '+';
const char Formula::MINUS = '-';
const char Formula::MULTIPLY ='*';
const char Formula::DIVIDE = '/';
const char Formula::POWER = '^';

Tree * Formula::parse(string str)
{
	const size_t len = str.length();
	if (str[0] == OPEN_PAR)
	{
		//operator has two operands
		Tree * rightOperand = nullptr;
		Tree * leftOperand = nullptr;

		size_t leftOperandLen;
		size_t rightOperandLen;


		if (str[1] == OPEN_PAR)
		{
			//first operand is compound
			unsigned short int openCount = 0;
			unsigned short int closeCount = 0;
			for (unsigned int i = 1; i < len - 1; i++)
			{
				if (str[i] == OPEN_PAR)
				{
					openCount++;
				}
				else if (str[i] == CLOSE_PAR)
				{
					closeCount++;
					if (openCount == closeCount)
					{
						leftOperand = parse(str.substr(1, i));
						leftOperandLen = i;
						break;
					}
				}
			}
		}
		else
		{
			//left operand is Var
			leftOperand = parse(str.substr(1, 1));
			leftOperandLen = 1;
		}

		if (str[len - 2] == CLOSE_PAR)
		{
			//right operand is compound
			unsigned int openCount = 0;
			unsigned int closeCount = 0;

			for (size_t i = len - 2; i >= 1; --i)
			{
				if (str[i] == OPEN_PAR)
				{
					++openCount;
					if (closeCount == openCount)
					{
						rightOperand = parse(str.substr(i, len - i - 1));
						rightOperandLen = (len - i - 1);
						break;
					}
				}
				else if (str[i] == CLOSE_PAR)
				{
					++closeCount;
				}
			}
		}
		else
		{
			//right operand is Var
			rightOperand = parse(str.substr(len - 2, 1));
			rightOperandLen = 1;
		}

		char opt = str.substr(1 + leftOperandLen, len - rightOperandLen - leftOperandLen - 2)[0];
		
		return new Tree(TreeNodeType::OPERATION, opt, leftOperand, rightOperand);
	}
	else
	{
		// it is a value
		// create tree and return
		return new Tree(TreeNodeType::VALUE, (str[0]));
	}
}

Formula::Formula(const string & formula)
{
	this->str = formula;
	this->tree = parse(formula);
}

Formula::~Formula()
{
	delete tree;
}

string Formula::getString()
{
	return this->str;
}

string Formula::getPrefixString()
{
	return tree->prefixSequence();
}

string Formula::getPostfixString()
{
	return tree->postfixSequence();
}

int Formula::calcPrefixString(const string prefixString)
{
	stack<int> st;
	for (int i = prefixString.length() - 1; i >= 0; --i)
	{
		if (isdigit(prefixString[i]))
		{
			//push to stack
			st.push(prefixString[i] - '0');
		}
		else
		{
			//it is operation calculate
			int opr1 = st.top(); st.pop();
			int opr2 = st.top(); st.pop();
			switch (prefixString[i])
			{
			case PLUS:
				st.push(opr1 + opr2);
				break;
			case MINUS:
				st.push(opr1 - opr2);
				break;
			case MULTIPLY:
				st.push(opr1 * opr2);
				break;
			case DIVIDE:
				st.push(opr1 / opr2);
				break;
			case POWER:
				st.push(pow(opr1 , opr2));
				break;
			}
		}
	}
	return st.top();
}

int Formula::calcPostfixString(const string postfixSting)
{
	stack<int> st;
	for (int i = 0; i < postfixSting.length(); ++i)
	{
		if (isdigit(postfixSting[i]))
		{
			//push to stack
			st.push(postfixSting[i] - '0');
		}
		else
		{
			//it is operation calculate
			int opr2 = st.top(); st.pop();
			int opr1 = st.top(); st.pop();
			switch (postfixSting[i])
			{
			case PLUS:
				st.push(opr1 + opr2);
				break;
			case MINUS:
				st.push(opr1 - opr2);
				break;
			case MULTIPLY:
				st.push(opr1 * opr2);
				break;
			case DIVIDE:
				st.push(opr1 / opr2);
				break;
			case POWER:
				st.push(pow(opr1, opr2));
				break;
			}
		}
	}
	return st.top();
}
