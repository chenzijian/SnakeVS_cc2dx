#include "Layer_Food.h"
#include "cocos2d.h"
using namespace cocos2d;


Layer_Food::Layer_Food()
{
    isCreate = false;
}
void Layer_Food::readFoodPosAndDraw(Food* FoodClass)
{
	if (!isCreate)
	{
		FoodSprite = CCSprite::create(ICON_FOOD);
		FoodSprite->setPosition( ccp(ICON_SIZE*FoodClass->Food_PosX + ICON_SIZE/2
								, ICON_SIZE*FoodClass->Food_PosY + ICON_SIZE/2) );
		mainLayer->addChild(FoodSprite, 1);
		isCreate = true;
	}
	else FoodSprite->setPosition( ccp(ICON_SIZE*FoodClass->Food_PosX + ICON_SIZE/2
								, ICON_SIZE*FoodClass->Food_PosY + ICON_SIZE/2) );
}
void Layer_Food::getMainGameLayer(CCLayer* pLayer)
{
	mainLayer = pLayer;
}
