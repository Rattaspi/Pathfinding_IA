#pragma once
#include "Vector2D.h"

class Node
{
private:
	Vector2D coordenates;
	float cost;
	bool obstacle;
public:
	Vector2D GetCoords();
	void SetObstacle(bool);
	void SetCoords(Vector2D coords);
	float GetCost();
	bool IsObstacle();
};
