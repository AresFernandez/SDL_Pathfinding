#pragma once
#include "Node.h"

class Connection {
public:
	Connection();
	Connection(float cost, Node* nodeFrom, Node* nodeTo);
	~Connection();
private:
	float cost;
	Node* nodeFrom;
	Node* nodeTo;
};