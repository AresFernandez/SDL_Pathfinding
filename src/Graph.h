#pragma once
#include <vector>
#include <map>
#include "Grid.h"
#include "Connection.h"

class Graph {
public:
	Graph();
	Graph(Grid* grid);
	~Graph();

	std::map<Node , std::vector<Connection>> map;
};
