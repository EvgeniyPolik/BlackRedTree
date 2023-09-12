#pragma once
#include <iostream>
class Node //Класс узла дерева
{
	int value;
	bool redNode;

public:
	int getValue();
	bool checkRed();
	void setRed();
	void setBlack();
	Node* leftChild;
	Node* rightChild;

	Node() : value(0), redNode(true), leftChild(nullptr), rightChild(nullptr) { }

	explicit Node(int value) : value(value), redNode(true), leftChild(nullptr), rightChild(nullptr) {}

	Node(int value, bool redNode) : value(value), redNode(redNode), leftChild(nullptr), rightChild(nullptr) { }

	Node(Node & node) : value(node.value), redNode(node.redNode), leftChild(node.leftChild), rightChild(node.rightChild) { 
	}

	Node(Node && node) : value(node.value), redNode(node.redNode), leftChild(node.leftChild), rightChild(node.rightChild) {
		node.value = 0;
		node.redNode = true;
		node.leftChild = nullptr;
		node.rightChild = nullptr;
	}

	~Node() {
		delete leftChild;
		delete rightChild;
	}

	friend std::ostream& operator<<(std::ostream& os, Node& node); // вывод ноды
};

