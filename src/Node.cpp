#pragma once
#include "Node.h"

Vector2D GetNodeCoords(float nodeID) {
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

float GetNodeID(Vector2D nodeCoords)
{
	float auxY = nodeCoords.y;

	while (auxY >= 1)
		auxY /= 10;

	return nodeCoords.x + auxY;
}