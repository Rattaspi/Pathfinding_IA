#pragma once
#include "Vector2D.h"

class Node
{
private:
	bool obstacle;
public:
	Vector2D coordenates;
	float cost;
	float acumulatedCost;
	Vector2D GetCoords();
	void SetObstacle(bool);
	void SetCoords(Vector2D coords);
	float GetCost();
	bool IsObstacle();
};
