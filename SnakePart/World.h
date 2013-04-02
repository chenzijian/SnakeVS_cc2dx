#ifndef __WORLD_H__
#define __WORLD_H__

#define SNAKE_HEAD_H 'H'
#define SNAKE_BODY_H 'X'

#define SNAKE_HEAD_A 'A'
#define SNAKE_BODY_A 'Y'

#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

#include "Block.h"
#include "Food.h"
#include "Snake_Auto.h"
#include "Snake_Human.h"
#include "Game_Option.h"

class World {

public:
	char **WorldGrid;			//data : point[Y][X]  top-left = [0][0]
	int World_SizeX , World_SizeY;
	
	Snake_Auto *Snake_AutoClass;
	Snake_Human *Snake_HumanClass;
	Food *FoodClass;
	Block *BlockClass;
	
	World();
	World(int SizeX, int SizeY);
	void World_AddObjectClass(Snake_Human* SH, Food* FD, Block* BK);

	void World_AddObjectClass(Snake_Auto* SA, Snake_Human* SH, Food* FD, Block* BK);
	
	void World_InitMap();
	
	void World_ChangeMap();
	
	//Print To Cmd Method -- for proto test
	void World_PrintToCmd();
	
	bool World_SnakeHuman_OnWall();
	bool World_SnakeHuman_EatFood();
	bool World_SnakeHuman_EatItself();
	bool World_SHandSAencounter();
	bool World_SnakeAuto_EatFood();
};

#endif