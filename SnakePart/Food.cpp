#include "Food.h"
#include <ctime>
#include <stdlib.h>

Food::Food()
{
	srand((unsigned)time(0));
	Food_IsOnWorld = false;
}
void Food::Food_SetPos(int PosX, int PosY)
{
	Food_PosX = PosX;
	Food_PosY = PosY;
}
void Food::Food_SetPos_Random(int MaxX, int MaxY)
{
	Food_PosX = rand() % MaxX;
	Food_PosY = rand() % MaxY;
}
void Food::Food_PutOnWorld()
{
	Food_IsOnWorld = true;
}
void Food::Food_Eaten()
{
	Food_IsOnWorld = false;
}
