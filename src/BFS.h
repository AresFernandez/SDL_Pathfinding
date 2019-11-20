#pragma once
#include <queue>
#include <map>
#include "Pathfinding.h"


class BFS : public Pathfinding {
public:
	BFS();
	~BFS();

	Path calculatePath(int _initialNodeID, int _finalNodeID, Graph* graph) override;
};
