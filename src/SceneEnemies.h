#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include "Scene.h"
#include "Agent.h"
#include "Seek.h"
#include "PathFollowing.h"
#include "AStar.h"
#include "Grid.h"

class SceneEnemies :
	public Scene
{
public:
	SceneEnemies();
	~SceneEnemies();
	void update(float dtime, SDL_Event *event);
	void draw();
	const char* getTitle();
private:
	std::vector<Agent*> agents;
	std::vector<int> enemiesPositionsID;
	Vector2D coinPosition;

	Grid *maze;
	bool draw_grid;

	void drawMaze();
	void drawCoin();
	SDL_Texture *background_texture;
	SDL_Texture *coin_texture;
	bool loadTextures(char* filename_bg, char* filename_coin);

};