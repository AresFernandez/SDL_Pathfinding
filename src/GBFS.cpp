#include "GBFS.h"

GBFS::GBFS()
{
}

GBFS::~GBFS()
{
}

Path GBFS::calculatePath(int _initialNodeID, int _finalNodeID, Graph * graph, Grid* grid)
{
	std::cout << "GBFS: " << std::endl;
	int nodesExplored = 0;

	Path tempPath;

	std::vector<std::pair<int, float>> frontier; // Creem la frontera
	frontier.push_back(std::pair<int, float>(_initialNodeID, 0)); // Li afegim el node inicial

	std::map<int, int> cameFrom;		// Ens creem un map per guardar de quin node venim
	cameFrom[_initialNodeID] = NULL;

	bool earlyExit = false;


	while (frontier.size() > 0 && !earlyExit)			// Recorrem la frontera dins que es buidi
	{
		nodesExplored++;

		std::sort(frontier.begin(), frontier.end(), [](auto &left, auto &right) { // Ordenem la frontera per cost
			return left.second < right.second;
		});

		std::pair<int, float> current = frontier.front();			// Agafem el primer node de la frontera

		if (current.first == _finalNodeID) // Si trobem el node al que volem arribar fem early exit
		{
			earlyExit = true;
			break;
		}

		for each (Connection con in graph->map[current.first])	// Recorrem les seves connexions
		{
			auto it = cameFrom.find(con.nodeToID);				// Busquem si hem explorat el node abans

			if (it == cameFrom.end())							// Si no hem explorat aquell node abans
			{
				frontier.push_back(std::pair<int, float>(con.nodeToID, calculateHeuristic(con.nodeToID, _finalNodeID, graph->w)));	// Posem el node a la frontera
				cameFrom[con.nodeToID] = current.first;	// Assignem de quin node prové el nou node
			}
		}
		frontier.erase(frontier.begin()); // Treiem el node que acabem de explorar
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

float GBFS::calculateHeuristic(int _currentNodeID, int _finalNodeID, int w)
{
	return Vector2D::Distance(GetNodeCoords(_currentNodeID, w), GetNodeCoords(_finalNodeID, w));
}
