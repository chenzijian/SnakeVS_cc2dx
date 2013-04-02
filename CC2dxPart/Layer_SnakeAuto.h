#ifndef __LAYER_SNAKEAUTO_H__
#define __LAYER_SNAKEAUTO_H__

#include "Icon_Header.h"
#include "../SnakePart/Snake_Auto.h"
#include "cocos2d.h"
using namespace cocos2d;

class Layer_SnakeAuto
{
public:
	CCLayer* mainLayer;
	CCSprite** SnakeAutoSprite;
	bool isCreate[MAX_LENGTH];

	Layer_SnakeAuto();
	void readSnakeAutoAndDraw(Snake_Auto* Snake_AutoClass);
	void getMainGameLayer(CCLayer* pLayer);
};

#endif