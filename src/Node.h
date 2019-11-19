#pragma once
#include <iostream>
#include "Vector2D.h"

class Node {
public:
	Node();
	Node(Vector2D);
	Node(int, int);
	~Node();

	int x;
	int y;

	bool operator<(const Node& otherNode)const {
		return (x == otherNode.x && y == otherNode.y);
	}

	 bool operator==(const Node& otherNode) const {
		 return (x == otherNode.x && y == otherNode.y);
	}
};

std::ostream& operator<<(std::ostream& output, const Node& node);

namespace NodeUtils 
{
	Vector2D GetNodeCoords(float nodeID);
	float GetNodeID(Vector2D nodeCoords);
}