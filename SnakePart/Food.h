#ifndef __FOOD_H__
#define __FOOD_H__

class Food {

public:
	int Food_PosX , Food_PosY;
	bool Food_IsOnWorld;
	
	Food();
	void Food_SetPos(int PosX, int PosY);
	void Food_SetPos_Random(int MaxX, int MaxY);
	void Food_PutOnWorld();
	void Food_Eaten();
};

#endif