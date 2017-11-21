#pragma once
#include <vector>
#include <time.h>
#include "Scene.h"
#include "Agent.h"
#include "Path.h"
#include "Graph.h"
#include <queue>
#include <map>

class SceneMultipleTarget :
	public Scene
{
public:
	SceneMultipleTarget();
	~SceneMultipleTarget();
	void update(float dtime, SDL_Event *event);
	void draw();
	const char* getTitle();


private:
	enum algoritmo { BFS, DIJKSTRA, GREEDY, ASTAR };
	algoritmo algorithm;
	std::vector<Agent*> agents;
	Vector2D coinPosition;
	Vector2D currentTarget;
	int currentTargetIndex;
	Path path;
	int num_cell_x;
	int num_cell_y;
	bool draw_grid;
	std::vector<SDL_Rect> maze_rects;
	void drawMaze();
	void drawCoin();
	SDL_Texture *background_texture;
	SDL_Texture *coin_texture;
	void initMaze();
	bool loadTextures(char* filename_bg, char* filename_coin);
	bool foundPath;
	bool waitAFrame;
	bool waitAFrameA;
	bool waitAFrameB;
	std::vector< std::vector<int> > terrain;
	std::vector<Node> nodos;
	std::vector<Vector2D> coins;

	Vector2D cell2pix(Vector2D cell);
	Vector2D pix2cell(Vector2D pix);
	bool isValidCell(Vector2D cell);
	Graph graph;
	std::priority_queue<Node> priorityFrontier;
	std::queue<Vector2D> frontier;

	std::map<Vector2D, Vector2D> cameFrom;
	std::map<Vector2D, Node> mapeado;
	std::map<Vector2D, float> cost_so_far;
	void AStar();
	void BreadthFirstSearch();
	void GreedyBfs();
	void Dijkstra();
	void ResetVisited();
	float EulerHeuristic(Vector2D current, Vector2D target);
};