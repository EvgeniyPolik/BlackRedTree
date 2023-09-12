#include "Trees.h"

Node* Trees::getRoot() {
    return root;
}

Node* Trees::turnLeft(Node* node) { // левый поворот
	Node* leftChild = node->leftChild;
	Node* changedChild = leftChild->rightChild;
	leftChild->rightChild = node;
	node->leftChild = changedChild;
	node->checkRed() ? leftChild->setRed() : leftChild->setBlack();
	node->setRed();
	return leftChild;
}

Node* Trees::turnRigth(Node* node) { // правый поворот
	Node* rightChild = node->rightChild;
	Node* changedChild = rightChild->leftChild;
	rightChild->leftChild = node;
	node->rightChild = changedChild;
	node->checkRed() ? rightChild->setRed() : rightChild->setBlack();
	node->setRed();
	return rightChild;
}

void Trees::colorChange(Node* node) // смена цвета
{
	node->rightChild->setBlack();
	node->leftChild->setBlack();
	node->setRed();
}

Node* Trees::balacing(Node* node) // балансировка
{
	Node* result = node;
	bool doBalacing = true;
	while (doBalacing) {
		doBalacing = false;
		if (result->rightChild && result->rightChild->checkRed() && (!result->leftChild || !result->leftChild->checkRed())) {
			doBalacing = true;
			result = turnRigth(result);
		}
		if (result->leftChild && result->leftChild->checkRed() && result->leftChild->leftChild &&
			result->leftChild->leftChild->checkRed()) {
			doBalacing = true;
			result = turnLeft(result);
		}
		if (result->leftChild && result->leftChild->checkRed() && result->rightChild &&
			result->rightChild->checkRed()) {
			doBalacing = true;
			colorChange(result);
		}
	}
	return result;
}

bool Trees::addNewNode(Node* node, int value) // создание и добавление новой ноды
{
	if (node->getValue() == value)
		return false;
	if (node->getValue() > value) {
		if (node->leftChild) {
			bool result = addNewNode(node->leftChild, value);
			node->leftChild = balacing(node->leftChild);
			return result;
		}
		node->leftChild = new Node(value);
		return true;
	}
	if (node->rightChild) {
		bool result = addNewNode(node->rightChild, value);
		node->rightChild = balacing(node->rightChild);
		return result;
	}
	node->rightChild = new Node(value);
	return true;
}

bool Trees::add(int value) 
{
	if (root != nullptr) { // если корень не пустой пытаемся добавить новую ноду
		bool result = addNewNode(root, value);
		root = balacing(root);
		root->setBlack();
		return result;
	}
	root = new Node(value, false);	
	return true;
}
