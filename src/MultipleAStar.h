#pragma once
#include <vector>
#include <algorithm>
#include <map>
#include "Pathfinding.h"


class MultipleAStar : public Pathfinding {
public:
	MultipleAStar();
	~MultipleAStar();

	Path calculatePath(int _initialNodeID, int _finalNodeID, Graph* graph, Grid* grid) override;
	Path calculateMultiplePath(int _initialNodeID, int _finalNodeID, std::vector<int> _vID, Graph* graph, Grid* grid) override;
	float calculateHeuristic(int _currentNodeID, int _finalNodeID, int w);
};
