#include "BFS.h"

BFS::BFS()
{
}

BFS::~BFS()
{
}

Path BFS::calculatePath(int _initialNodeID, int _finalNodeID, Graph * graph, Grid* grid)
{
	std::cout << "BFS: " << std::endl;
	int nodesExplored = 0;

	Path tempPath;

	std::queue<int> frontier;			// Creem la frontera
	frontier.push(_initialNodeID);		// Li afegim el node inicial

	std::map<int, int> cameFrom;		// Ens creem un map per guardar de quin node venim
	cameFrom[_initialNodeID] = NULL;

	bool earlyExit = false;


	while (frontier.size() > 0 && !earlyExit)			// Recorrem la frontera dins que es buidi
	{
		nodesExplored++;
		int current = frontier.front();			// Agafem el primer node de la frontera


		for each (Connection* con in graph->map[current])	// Recorrem les seves connexions
		{
			auto it = cameFrom.find(con->nodeToID);			// Si no hem explorat aquell node abans, el posem a la frontera
			if (it == cameFrom.end())						
			{
				frontier.push(con->nodeToID);
				cameFrom[con->nodeToID] = current;
			}

			if (con->nodeToID == _finalNodeID)
			{
				earlyExit = true;
				break;
			}
		}

		frontier.pop(); // Treiem el node que acabem de explorar
	}

	if (earlyExit) // Si hem trobat el node final
	{
		int current = _finalNodeID;

		while (current != NULL)
		{
			tempPath.points.insert(tempPath.points.begin(), grid->cell2pix(GetNodeCoords(current, graph->w)));
			current = cameFrom[current];
		}
	}
	else
		tempPath.points.push_back(grid->cell2pix(GetNodeCoords(_initialNodeID, graph->w)));

	std::cout << "Nodes explored: " << nodesExplored << std::endl;

	return tempPath;
}
