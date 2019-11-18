#pragma once
#include <iostream>
#include "Graph.h"

Graph::Graph() {

}

Graph::Graph(Grid* grid) {
	map.clear();
	for (int i = 0; i < grid->getNumCellY(); i++)
	{
		for (int j = 0; j < grid->getNumCellX(); j++)
		{
			if (grid->isValidCell(Vector2D(j, i))) //Si la meva posició és vàlida
			{
				float cellKey = GetNodeID(Vector2D(j, i));
				map.insert(std::pair<float,std::vector<Connection>>(cellKey, std::vector<Connection>())); //Insertem el node al map amb les connexions buides

				int conn = 0;
				////Comprovem les seves conexions circundants
				////Cantonada superior esquerra
				if (grid->isValidCell(Vector2D(j - 1, i - 1)))
				{
					conn++;
					Connection aux = Connection(1, cellKey, GetNodeID(Vector2D(j - 1, i - 1)));
					map.at(cellKey).push_back(aux);
				}
				////Cantonada superior dreta
				//if (grid->isValidCell(Vector2D(j + 1, i - 1)))
				//{
				//	map[cellKey].push_back(Connection(std::sqrt(2), cellKey, GetNodeID(Vector2D(j + 1, i - 1))));
				//}
				////Cantonada inferior esquerra
				//if (grid->isValidCell(Vector2D(j - 1, i + 1)))
				//{
				//	map[cellKey].push_back(Connection(std::sqrt(2), cellKey, GetNodeID(Vector2D(j - 1, i + 1))));
				//}
				////Cantonada inferior dreta
				//if (grid->isValidCell(Vector2D(j + 1, i + 1)))
				//{
				//	map[cellKey].push_back(Connection(std::sqrt(2), cellKey, GetNodeID(Vector2D(j + 1, i + 1))));
				//}
				////Adjacent superior
				//if (grid->isValidCell(Vector2D(j, i - 1)))
				//{
				//	map[cellKey].push_back(Connection(1, cellKey, GetNodeID(Vector2D(j, i - 1))));
				//}
				////Adjacent inferior
				//if (grid->isValidCell(Vector2D(j, i + 1)))
				//{
				//	map[cellKey].push_back(Connection(1, cellKey, GetNodeID(Vector2D(j, i + 1))));
				//}
				////Adjacent esquerra
				//if (grid->isValidCell(Vector2D(j - 1, i)))
				//{
				//	map[cellKey].push_back(Connection(1, cellKey, GetNodeID(Vector2D(j - 1, i))));
				//}
				////Adjacent dreta
				//if (grid->isValidCell(Vector2D(j + 1, i)))
				//{
				//	map[cellKey].push_back(Connection(1, cellKey, GetNodeID(Vector2D(j + 1, i))));
				//}

				std::cout << cellKey << " -> " << conn << std::endl;
			}
		}
	}


	//for (auto it = map.begin(); it != map.end(); it++)
	//{
	//	std::cout << it->first << ": ";
	//	for each (Connection con in it->second)
	//	{
	//		std::cout << con.nodeFromID << " - " << con.nodeToID << " | ";
	//	}
	//	std::cout << std::endl;
	//}

	for (int i = 0; i < grid->getNumCellY(); i++)
	{
		for (int j = 0; j < grid->getNumCellX(); j++)
		{
			if (grid->isValidCell(Vector2D(j, i))) //Si la meva posició és vàlida
			{
				auto it = map.find(GetNodeID(Vector2D(j, i)));
				if (it != map.end()) {
					std::cout << j << "-" << i << " -> " << it->second.size() << std::endl;
				}
			}
		}
	}
}

Graph::~Graph() {

}