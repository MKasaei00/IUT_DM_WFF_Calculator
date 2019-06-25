#include "Tree.h"

Tree::Tree()
{
	right = nullptr;
	left = nullptr;
}

Tree::Tree(const TreeNodeType & type, const Value & value , Tree * left, Tree * right)
{
	this->type = type;
	this->value = value;
	this->left = left;
	this->right = right;
}


Tree::~Tree()
{
	delete right;
	delete left;
}

TreeNodeType Tree::getType() const
{
	return type;
}

Value Tree::getValue() const
{
	return value;
}

Tree * Tree::getRight() const
{
	return this->right;
}

Tree * Tree::getLeft() const
{
	return this->left;
}

string Tree::prefixSequence() const
{
	if (type == TreeNodeType::OPERATION)
		return string(1,value) + getLeft()->prefixSequence() + getRight()->prefixSequence();
	else
		return string(1,value);
}

string Tree::postfixSequence() const
{
	if (type == TreeNodeType::OPERATION)
		return getLeft()->postfixSequence() + getRight()->postfixSequence() + string(1,value);
	else
		return string(1,value);
}
