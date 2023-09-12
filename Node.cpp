#include "Node.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, Node& node) // ��� ������ �� �������
{
	os << node.getValue() << " Color: " << (node.checkRed() ? "Red" : "Black") << std::endl;
	return os;
}

int Node::getValue()
{
	return value;
}

bool Node::checkRed()
{
	return redNode;
}

void Node::setRed() // ������� �������
{
	redNode = true;
}

void Node::setBlack() // ������� ������
{
	redNode = false;
}
