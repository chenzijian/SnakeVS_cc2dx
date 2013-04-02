#ifndef __LAYER_WORLDANDBLOCK_H__
#define __LAYER_WORLDANDBLOCK_H__

#include "Icon_Header.h"
#include "../SnakePart/World.h"
#include "cocos2d.h"
using namespace cocos2d;

class Layer_WorldAndBlock
{
public:
	CCLayer* mainLayer;
	CCSprite*** WorldGridSprites;

	Layer_WorldAndBlock();
	void readWorldGridAndDraw(World* WorldClass);
	void getMainGameLayer(CCLayer* pLayer);
};

#endif