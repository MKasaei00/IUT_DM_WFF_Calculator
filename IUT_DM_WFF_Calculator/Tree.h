#pragma once
#include <string>

using std::string;
using std::to_string;

typedef char Value;

enum class TreeNodeType { OPERATION , VALUE };

class Tree
{
private:
	TreeNodeType type;
	Value value;	//operation type or digit
	Tree* right;
	Tree* left;

public:
	Tree();
	Tree(const TreeNodeType &type, const Value &val, Tree * left = nullptr, Tree * right = nullptr);

	~Tree();

	TreeNodeType getType() const;
	Value getValue() const;
	Tree * getRight() const;
	Tree * getLeft() const;

	string prefixSequence() const;
	string postfixSequence() const;
};

