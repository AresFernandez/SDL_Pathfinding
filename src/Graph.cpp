#pragma once
#include <iostream>
#include "Graph.h"

Graph::Graph() {

}

Graph::Graph(Grid* grid) {
	for (int i = 0; i < grid->getNumCellY(); i++)
	{
		for (int j = 0; j < grid->getNumCellX(); j++)
		{

			if (grid->isValidCell(Vector2D(j, i))) //Si la meva posició és vàlida
			{
				map.insert(std::pair<Node*,std::vector<Connection>>(new Node(j, i), std::vector<Connection>())); //Insertem el node al map amb les connexions buides

				//Comprovem les seves conexions circundants
				if (grid->isValidCell(Vector2D(j-1, i-1)))
				{

				}
			}



			//std::cout << grid->isValidCell(Vector2D(j, i));
		}
		//std::cout << std::endl;
	}
}

Graph::~Graph() {

}