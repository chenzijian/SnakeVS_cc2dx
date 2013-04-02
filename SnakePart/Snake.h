#ifndef __SNAKE_H__
#define __SNAKE_H__

#define DIRECTION_UP 1
#define DIRECTION_DOWN 2
#define DIRECTION_LEFT 3
#define DIRECTION_RIGHT 4

#define DIRECTION_UL 5
#define DIRECTION_UR 6
#define DIRECTION_DL 7
#define DIRECTION_DR 8
/*
Direction 
+-------------X
|  5  1  6
|   \ | /
|  3--A--4
|   / | \
|  7  2  8
Y
*/
#define MAX_LENGTH 100

class Snake {
public:
	int *Snake_BodyX , *Snake_BodyY;
	int Snake_Length , Snake_NextDirection , Snake_NowDirection; 
	bool Snake_Eaten;
	
	Snake();
	
	void Snake_PosInit();	
	void Snake_PosInit(int posX[5], int posY[5]);
	void Snake_MoveOnly(int headX, int headY);
	void Snake_EatAndMove(int headX, int headY);

	void Snake_ChangeNextDirection(int Dir);
	void Snake_ChangeNextToNow();
	
	void Snake_MoveNextDirection();
	void Snake_EatAndMoveNextDirection();
	/*
	void Snake_MoveUp();
	void Snake_MoveDown();
	void Snake_MoveLeft();
	void Snake_MoveRight();
	*/
};

#endif