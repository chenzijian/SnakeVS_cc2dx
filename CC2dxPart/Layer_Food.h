#ifndef __LAYER_FOOD_H__
#define __LAYER_FOOD_H__

#include "Icon_Header.h"
#include "../SnakePart/Food.h"
#include "cocos2d.h"
using namespace cocos2d;

class Layer_Food
{
public:
	CCLayer* mainLayer;
	CCSprite* FoodSprite;
	bool isCreate;

	Layer_Food();
	void readFoodPosAndDraw(Food* FoodClass);
	void getMainGameLayer(CCLayer* pLayer);
};

#endif