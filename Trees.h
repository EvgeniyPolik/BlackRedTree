#pragma once
#include "Node.h"
class Trees // дерево
{
	Node* root;

public:
	Node* getRoot(); // получить текущий корень дерева

	Trees() : root(nullptr) {}

	Trees(Node* node) {
		root = node;
	}

	~Trees() {
		delete root;
	}

	Node* turnLeft(Node* node);
	Node* turnRigth(Node* node);
	void colorChange(Node* node);
	Node* balacing(Node* node);

	bool addNewNode(Node* node, int value);
	bool add(int value);
};

