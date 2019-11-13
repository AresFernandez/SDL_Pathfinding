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

	std::map<float , std::vector<Connection>> map;



};
