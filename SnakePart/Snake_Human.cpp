#include "Snake_human.h"

Snake_Human::Snake_Human()
{
	isDead = false;
	Snake_PosInit();
}	

void Snake_Human::Snake_Human_GetInputDir(int Dir)
{
	Snake_ChangeNextDirection(Dir);
}

