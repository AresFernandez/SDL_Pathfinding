#pragma once
#include "Path.h"
#include "Graph.h"


class Pathfinding
{
public:
	Pathfinding() {};
	virtual ~Pathfinding() {};

	virtual Path calculatePath(int _initialNodeID, int _finalNodeID, Graph* graph) { return Path(); };

};