#ifndef __SNAKE_HUMAN_H__
#define __SNAKE_HUMAN_H__

#include "Snake.h"

class Snake_Human : public Snake{
public:
	bool isDead;

	Snake_Human();	
	void Snake_Human_GetInputDir(int Dir);
};

#endif