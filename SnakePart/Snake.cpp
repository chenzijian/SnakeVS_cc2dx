#include "Snake.h"
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
Snake::Snake() {
	Snake_Length = 3;
	Snake_Eaten = false;
	Snake_NowDirection = DIRECTION_RIGHT;
	Snake_NextDirection = DIRECTION_RIGHT;
	Snake_BodyX = new int[100];
	Snake_BodyY = new int[100];
}
void Snake::Snake_PosInit()
{
	//pos init
	for (int i=0; i<3; i++)
	{
		Snake_BodyX[i] = 3-i;
		Snake_BodyY[i] = 1;
	}
}
void Snake::Snake_PosInit(int posX[3], int posY[3])
{
	//pos init
	for (int i=0; i<3; i++)
	{
		Snake_BodyX[i] = posX[i];
		Snake_BodyY[i] = posY[i];
	}
}

void Snake::Snake_MoveOnly(int headX, int headY) 
{
	for (int i=Snake_Length-1; i>0; i--)
	{
		Snake_BodyX[i] = Snake_BodyX[i-1];
		Snake_BodyY[i] = Snake_BodyY[i-1];
	}		
	Snake_BodyX[0] = headX;
	Snake_BodyY[0] = headY;
}

void Snake::Snake_EatAndMove(int headX, int headY) 
{
	if (Snake_Length < MAX_LENGTH)
		Snake_Length++;
	for (int i=Snake_Length; i>0; i--)
	{
		Snake_BodyX[i] = Snake_BodyX[i-1];
		Snake_BodyY[i] = Snake_BodyY[i-1];
	}		
	Snake_BodyX[0] = headX;
	Snake_BodyY[0] = headY;
	Snake_Eaten = false;
}

void Snake::Snake_ChangeNextDirection(int Dir)
{
	Snake_NextDirection = Dir;
}

void Snake::Snake_ChangeNextToNow()
{
	if (Snake_NowDirection == DIRECTION_UP && Snake_NextDirection == DIRECTION_DOWN)
		return;
	if (Snake_NowDirection == DIRECTION_DOWN && Snake_NextDirection == DIRECTION_UP)
		return;
	if (Snake_NowDirection == DIRECTION_LEFT && Snake_NextDirection == DIRECTION_RIGHT)
		return;
	if (Snake_NowDirection == DIRECTION_RIGHT && Snake_NextDirection == DIRECTION_LEFT)
		return;
	Snake_NowDirection = Snake_NextDirection;
}

void Snake::Snake_MoveNextDirection()
{
	Snake_ChangeNextToNow();
	switch (Snake_NowDirection) {
	case DIRECTION_UP:
		Snake_MoveOnly(Snake_BodyX[0], Snake_BodyY[0]-1);
		break;
	case DIRECTION_DOWN:
		Snake_MoveOnly(Snake_BodyX[0], Snake_BodyY[0]+1);
		break;
	case DIRECTION_LEFT:
		Snake_MoveOnly(Snake_BodyX[0]-1, Snake_BodyY[0]);
		break;
	case DIRECTION_RIGHT:
		Snake_MoveOnly(Snake_BodyX[0]+1, Snake_BodyY[0]);
		break;
	default:
		break;
	}
}

void Snake::Snake_EatAndMoveNextDirection()
{
	Snake_ChangeNextToNow();
	switch (Snake_NowDirection) {
	case DIRECTION_UP:
		Snake_EatAndMove(Snake_BodyX[0], Snake_BodyY[0]-1);
		break;
	case DIRECTION_DOWN:
		Snake_EatAndMove(Snake_BodyX[0], Snake_BodyY[0]+1);
		break;
	case DIRECTION_LEFT:
		Snake_EatAndMove(Snake_BodyX[0]-1, Snake_BodyY[0]);
		break;
	case DIRECTION_RIGHT:
		Snake_EatAndMove(Snake_BodyX[0]+1, Snake_BodyY[0]);
		break;
		
	default:
		break;
	}
}
/*
void Snake::Snake_MoveUp()
{
	Snake_MoveBodyAll(Snake_BodyX[0], Snake_BodyY[0]+1);
}
void Snake::Snake_MoveDown()
{
	Snake_MoveBodyAll(Snake_BodyX[0], Snake_BodyY[0]-1);
}
void Snake::Snake_MoveLeft()
{
	Snake_MoveBodyAll(Snake_BodyX[0]+1, Snake_BodyY[0]);
}
void Snake::Snake_MoveRight()
{
	Snake_MoveBodyAll(Snake_BodyX[0]-1, Snake_BodyY[0]);
}
*/

