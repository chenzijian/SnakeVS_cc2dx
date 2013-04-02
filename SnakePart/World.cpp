#include "World.h"
#include <iostream>
using namespace std;

World::World()
{
	World_SizeX = WORLD_SIZE_X+2;
	World_SizeY = WORLD_SIZE_Y+2;
	World_InitMap();
}
World::World(int SizeX, int SizeY)
{
	World_SizeX = SizeX+2;
	World_SizeY = SizeY+2;
	World_InitMap();
}
void World::World_AddObjectClass(Snake_Human* SH, Food* FD, Block* BK)
{
	Snake_HumanClass = SH;
	FoodClass = FD;
	BlockClass = BK;
}

void World::World_AddObjectClass(Snake_Auto* SA, Snake_Human* SH, Food* FD, Block* BK)
{
	Snake_AutoClass = SA;
	Snake_HumanClass = SH;
	FoodClass = FD;
	BlockClass = BK;
}
	
void World::World_InitMap()
{
	WorldGrid = new char*[World_SizeY];
	int i,j;
	
	for (i=0; i<World_SizeY; i++)
		WorldGrid[i] = new char[World_SizeX];
	
	for (i=1; i<World_SizeX-1; i++)
    {
        for (j=1; j<World_SizeY-1; j++)
        {
        	WorldGrid[j][i] = BLANK_CELL;
        }
    }
	
	for (i=0; i<World_SizeX; i++)
	{
		WorldGrid[0][i] = WALL_CELL;
		WorldGrid[World_SizeY-1][i] = WALL_CELL;
	}
	for (j=0; j<World_SizeY; j++)
	{
		WorldGrid[j][0] = WALL_CELL;
		WorldGrid[j][World_SizeX-1] = WALL_CELL;
	}
	//for CMD char* output , '\0'
	for (i=0; i<World_SizeY; i++)
		WorldGrid[i][World_SizeX] = 0;
}

void World::World_ChangeMap()
{
	//origin field clean
	int i,j;
	for (i=1; i<World_SizeX-1; i++)
    {
        for (j=1; j<World_SizeY-1; j++)
        {
        	WorldGrid[j][i] = BLANK_CELL;
        }
    }
		
	//block
	for (i=0; i<BlockClass->Block_Count; i++)
		WorldGrid[BlockClass->Block_PosY[i]][BlockClass->Block_PosX[i]] = WALL_CELL;
	
	//snake-human
	WorldGrid[Snake_HumanClass->Snake_BodyY[0]][Snake_HumanClass->Snake_BodyX[0]] = SNAKE_HEAD_H;
	for (i=1; i<Snake_HumanClass->Snake_Length; i++)
		WorldGrid[Snake_HumanClass->Snake_BodyY[i]][Snake_HumanClass->Snake_BodyX[i]] = SNAKE_BODY_H;

	//snake-auto
	WorldGrid[Snake_AutoClass->Snake_BodyY[0]][Snake_AutoClass->Snake_BodyX[0]] = SNAKE_HEAD_A;
	for (i=1; i<Snake_AutoClass->Snake_Length; i++)
		WorldGrid[Snake_AutoClass->Snake_BodyY[i]][Snake_AutoClass->Snake_BodyX[i]] = SNAKE_BODY_A;
	
	//food    
	if ( (!World_SnakeAuto_EatFood() && FoodClass->Food_IsOnWorld) && (!World_SnakeHuman_EatFood() && FoodClass->Food_IsOnWorld))
		WorldGrid[FoodClass->Food_PosY][FoodClass->Food_PosX] = SNAKE_FOOD;
	else {
		FoodClass->Food_PutOnWorld();
		FoodClass->Food_SetPos_Random(World_SizeX, World_SizeY);
		while (!(WorldGrid[FoodClass->Food_PosY][FoodClass->Food_PosX] == BLANK_CELL))
			FoodClass->Food_SetPos_Random(World_SizeX, World_SizeY);
		WorldGrid[FoodClass->Food_PosY][FoodClass->Food_PosX] = SNAKE_FOOD;
	}
}

//Print To Cmd Method -- for proto test
void World::World_PrintToCmd()
{
	for (int i=0; i<World_SizeY; i++)
		cout << WorldGrid[i] << endl;
}
	
bool World::World_SnakeHuman_OnWall()
{
	if (Snake_HumanClass->Snake_BodyX[0] == World_SizeX-1 || 
		Snake_HumanClass->Snake_BodyY[0] == World_SizeY-1 ||
		Snake_HumanClass->Snake_BodyX[0] == 0 || 
		Snake_HumanClass->Snake_BodyY[0] == 0)
		return true;
	else return false;
}
bool World::World_SnakeHuman_EatFood()
{
	if (Snake_HumanClass->Snake_BodyX[0] == FoodClass->Food_PosX && 
		Snake_HumanClass->Snake_BodyY[0] == FoodClass->Food_PosY)
	{
		FoodClass->Food_Eaten();
		Snake_HumanClass->Snake_Eaten = true;
		return true;
	}
	else return false;
}
bool World::World_SnakeHuman_EatItself()
{
	for (int i=1; i<Snake_HumanClass->Snake_Length; i++) {
		if (Snake_HumanClass->Snake_BodyX[i] == Snake_HumanClass->Snake_BodyX[0] &&
			Snake_HumanClass->Snake_BodyY[i] == Snake_HumanClass->Snake_BodyY[0])
			return true;
	}
	return false;
}

bool World::World_SHandSAencounter()
{
	for (int i=0; i<Snake_AutoClass->Snake_Length; i++) {
		if (Snake_HumanClass->Snake_BodyX[0] == Snake_AutoClass->Snake_BodyX[i] &&
			Snake_HumanClass->Snake_BodyY[0] == Snake_AutoClass->Snake_BodyY[i])
			return true;
	}
	for (int j=0; j<Snake_AutoClass->Snake_Length; j++) {
		if (Snake_HumanClass->Snake_BodyX[j] == Snake_AutoClass->Snake_BodyX[0] &&
			Snake_HumanClass->Snake_BodyY[j] == Snake_AutoClass->Snake_BodyY[0])
			return true;
	}
	return false;
}

bool World::World_SnakeAuto_EatFood()
{
	if (Snake_AutoClass->Snake_BodyX[0] == FoodClass->Food_PosX && 
		Snake_AutoClass->Snake_BodyY[0] == FoodClass->Food_PosY)
	{
		FoodClass->Food_Eaten();
		Snake_AutoClass->Snake_Eaten = true;
		return true;
	}
	else return false;
}
