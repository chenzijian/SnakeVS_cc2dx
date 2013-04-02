#include "Layer_SnakeHuman.h"
#include "cocos2d.h"
using namespace cocos2d;

Layer_SnakeHuman::Layer_SnakeHuman()
{
	int i;
	for (i=0; i<MAX_LENGTH; i++)
	{
		isCreate[i] = false;
	}
	SnakeHumanSprite = new CCSprite*[MAX_LENGTH];
}
void Layer_SnakeHuman::readSnakeHumanAndDraw(Snake_Human* Snake_HumanClass)
{
	int i;
	for (i=0; i<Snake_HumanClass->Snake_Length; i++)
	{
		if (!isCreate[i])
		{
			if (i == 0)
			{
				SnakeHumanSprite[i] = CCSprite::create(ICON_SNAKEHEAD_H);
				SnakeHumanSprite[i]->setPosition( ccp((Snake_HumanClass->Snake_BodyX[i])*ICON_SIZE + ICON_SIZE/2
													, (Snake_HumanClass->Snake_BodyY[i])*ICON_SIZE + ICON_SIZE/2) );
				mainLayer->addChild(SnakeHumanSprite[i], 1);
				isCreate[i] = true;
			}
			else {
				SnakeHumanSprite[i] = CCSprite::create(ICON_SNAKEBODY_H);
				SnakeHumanSprite[i]->setPosition( ccp((Snake_HumanClass->Snake_BodyX[i])*ICON_SIZE + ICON_SIZE/2
													, (Snake_HumanClass->Snake_BodyY[i])*ICON_SIZE + ICON_SIZE/2) );
				mainLayer->addChild(SnakeHumanSprite[i], 1);
				isCreate[i] = true;
			}
		}
		else SnakeHumanSprite[i]->setPosition( ccp((Snake_HumanClass->Snake_BodyX[i])*ICON_SIZE + ICON_SIZE/2
												, (Snake_HumanClass->Snake_BodyY[i])*ICON_SIZE + ICON_SIZE/2) );

	}
}
void Layer_SnakeHuman::getMainGameLayer(CCLayer* pLayer)
{
	mainLayer = pLayer;
}