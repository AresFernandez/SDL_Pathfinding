#pragma once
#include "Node.h"

Node::Node() : x(-1), y(-1) {}

Node::Node(Vector2D pos) : x(pos.x), y(pos.y) {}

Node::Node(int _x, int _y) : x(_x), y(_y) {}

Node::~Node() {}

std::ostream& operator<<(std::ostream& output, const Node& node)
{
	output << node.x << " - " << node.y;
	return output;
}

Vector2D NodeUtils::GetNodeCoords(float nodeID) {
	int x = nodeID;
	float y = nodeID - x;
	
	int numberOfDecimals = 0;

	while (y != 0)
	{
		y = y * 10;
		y = y - (int)y;
		numberOfDecimals++;
	}
	y = nodeID - x;
	for (int i = 0; i < numberOfDecimals; i++)
		y *= 10;
	return Vector2D(x, y);
}

float NodeUtils::GetNodeID(Vector2D nodeCoords)
{
	float auxY = nodeCoords.y;

	while (auxY >= 1)
		auxY /= 10;

	return nodeCoords.x + auxY;
}