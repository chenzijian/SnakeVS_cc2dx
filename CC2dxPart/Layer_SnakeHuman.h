#ifndef __LAYER_SNAKEHUMAN_H__
#define __LAYER_SNAKEHUMAN_H__

#include "Icon_Header.h"
#include "../SnakePart/Snake_Human.h"
#include "cocos2d.h"
using namespace cocos2d;

class Layer_SnakeHuman
{
public:
	CCLayer* mainLayer;
	CCSprite** SnakeHumanSprite;
	bool isCreate[MAX_LENGTH];

	Layer_SnakeHuman();
	void readSnakeHumanAndDraw(Snake_Human* Snake_HumanClass);
	void getMainGameLayer(CCLayer* pLayer);
};

#endif