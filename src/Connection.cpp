#pragma once
#include "Connection.h"

Connection::Connection() {

}

Connection::Connection(float _cost, Node* _nodeFrom, Node* _nodeTo) {
	cost = _cost;
	nodeFrom = _nodeFrom;
	nodeTo = _nodeTo;
}

Connection::~Connection() {

}