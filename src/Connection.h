#pragma once
#include "Node.h"

class Connection {
public:
	Connection();
	Connection(float cost, float nodeFrom, float nodeTo);
	~Connection();
	float cost;
	float nodeFromID;
	float nodeToID;
};