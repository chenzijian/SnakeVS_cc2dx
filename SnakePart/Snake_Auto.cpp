#include "Snake_Auto.h"
#include "Game_Option.h"

Snake_Auto::Snake_Auto(){
	int X[3] = {WORLD_SIZE_X-2,WORLD_SIZE_X-1,WORLD_SIZE_X};
	int Y[3] = {WORLD_SIZE_Y,WORLD_SIZE_Y,WORLD_SIZE_Y};
	Snake_NowDirection = DIRECTION_LEFT;
	Snake_PosInit(X,Y);
}

void Snake_Auto::Snake_Auto_FindNextDir(int FoodX, int FoodY)
{
	int Dir = Snake_NowDirection;
	int FoodDir = Snake_Auto_GetFoodDir(FoodX, FoodY);
	switch (Dir){
	case DIRECTION_UP:
		Dir = Snake_Auto_UpNext(FoodDir);
		break;
	case DIRECTION_DOWN:
		Dir = Snake_Auto_DownNext(FoodDir);
		break;
	case DIRECTION_LEFT:
		Dir = Snake_Auto_LeftNext(FoodDir);
		break;
	case DIRECTION_RIGHT:
		Dir = Snake_Auto_RightNext(FoodDir);
		break;
	default:
		break;
	}

	Snake_ChangeNextDirection(Dir);
}

int Snake_Auto::Snake_Auto_GetFoodDir(int FoodX, int FoodY)
{
	int px = FoodX - Snake_BodyX[0];
	int py = FoodY - Snake_BodyY[0];
	
	if (px < 0 && py < 0)
		return DIRECTION_UL;
	if (px == 0 && py < 0)
		return DIRECTION_UP;
	if (px > 0 && py < 0)
		return DIRECTION_UR;
	if (px < 0 && py == 0)
		return DIRECTION_LEFT;
//	if (px == 0 && py == 0)    Food Eaten
//		return ------;
	if (px > 0 && py == 0)
		return DIRECTION_RIGHT;
	if (px < 0 && py > 0)
		return DIRECTION_DL;
	if (px == 0 && py > 0)
		return DIRECTION_DOWN;
	if (px > 0 && py > 0)
		return DIRECTION_DR;

	return DIRECTION_UP;
}
int Snake_Auto::Snake_Auto_UpNext(int FoodDir)
{
	if (FoodDir == 1 || FoodDir == 5 || FoodDir == 6)
		return 1;
	if (FoodDir == 3 || FoodDir == 7)
		return 3;
	if (FoodDir == 4 || FoodDir == 8)
		return 4;
	if (FoodDir == 2)
		return 4;  //right

	return 1;
}
int Snake_Auto::Snake_Auto_DownNext(int FoodDir)
{
	if (FoodDir == 2 || FoodDir == 7 || FoodDir == 8)
		return 2;
	if (FoodDir == 3 || FoodDir == 5)
		return 3;
	if (FoodDir == 4 || FoodDir == 6)
		return 4;
	if (FoodDir == 1)
		return 3;  //right

	return 2;
}
int Snake_Auto::Snake_Auto_LeftNext(int FoodDir)
{
	if (FoodDir == 3 || FoodDir == 5 || FoodDir == 7)
		return 3;
	if (FoodDir == 2 || FoodDir == 8)
		return 2;
	if (FoodDir == 1 || FoodDir == 6)
		return 1;
	if (FoodDir == 4)
		return 1;  //right

	return 3;
}
int Snake_Auto::Snake_Auto_RightNext(int FoodDir)
{
	if (FoodDir == 4 || FoodDir == 6 || FoodDir == 8)
		return 4;
	if (FoodDir == 1 || FoodDir == 5)
		return 1;
	if (FoodDir == 2 || FoodDir == 7)
		return 2;
	if (FoodDir == 3)
		return 2;  //right

	return 4;
}
