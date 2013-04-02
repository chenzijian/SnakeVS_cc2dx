#ifndef __SNAKE_AUTO_H__
#define __SNAKE_AUTO_H__

#include "Snake.h"

class Snake_Auto : public Snake{
public:
	Snake_Auto();
	void Snake_Auto_FindNextDir(int FoodX, int FoodY);
	int Snake_Auto_GetFoodDir(int FoodX, int FoodY);

	int Snake_Auto_UpNext(int FoodDir);
	int Snake_Auto_DownNext(int FoodDir);
	int Snake_Auto_LeftNext(int FoodDir);
	int Snake_Auto_RightNext(int FoodDir);
};

#endif