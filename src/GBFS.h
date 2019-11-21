#pragma once
#include "Pathfinding.h"


class GBFS : public Pathfinding {
public:
	GBFS();
	~GBFS();

	Path calculatePath(int _initialNodeID, int _finalNodeID, Graph* graph, Grid* grid) override;
	float calculateHeuristic(int _currentNodeID, int _finalNodeID, int w);
};
