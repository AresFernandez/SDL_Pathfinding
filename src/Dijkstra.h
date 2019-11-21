#pragma once
#include <vector>
#include <algorithm>
#include <map>
#include "Pathfinding.h"


class Dijkstra : public Pathfinding {
public:
	Dijkstra();
	~Dijkstra();

	Path calculatePath(int _initialNodeID, int _finalNodeID, Graph* graph, Grid* grid) override;
};