#include "Layer_SnakeAuto.h"
#include "cocos2d.h"
using namespace cocos2d;

Layer_SnakeAuto::Layer_SnakeAuto()
{
   int i;
	for (i=0; i<MAX_LENGTH; i++)
	{
		isCreate[i] = false;
	}
	SnakeAutoSprite = new CCSprite*[MAX_LENGTH];
}
void Layer_SnakeAuto::readSnakeAutoAndDraw(Snake_Auto* Snake_AutoClass)
{
	int i;
	for (i=0; i<Snake_AutoClass->Snake_Length; i++)
	{
		if (!isCreate[i])
		{
			if (i == 0)
			{
				SnakeAutoSprite[i] = CCSprite::create(ICON_SNAKEHEAD_A);
				SnakeAutoSprite[i]->setPosition( ccp((Snake_AutoClass->Snake_BodyX[i])*ICON_SIZE + ICON_SIZE/2
												, (Snake_AutoClass->Snake_BodyY[i])*ICON_SIZE + ICON_SIZE/2) );
				mainLayer->addChild(SnakeAutoSprite[i], 1);
				isCreate[i] = true;
			}
			else {
				SnakeAutoSprite[i] = CCSprite::create(ICON_SNAKEBODY_A);
				SnakeAutoSprite[i]->setPosition( ccp((Snake_AutoClass->Snake_BodyX[i])*ICON_SIZE + ICON_SIZE/2
												, (Snake_AutoClass->Snake_BodyY[i])*ICON_SIZE + ICON_SIZE/2) );
				mainLayer->addChild(SnakeAutoSprite[i], 1);
				isCreate[i] = true;
			}
		}
		else SnakeAutoSprite[i]->setPosition( ccp((Snake_AutoClass->Snake_BodyX[i])*ICON_SIZE + ICON_SIZE/2
												, (Snake_AutoClass->Snake_BodyY[i])*ICON_SIZE + ICON_SIZE/2) );

	}
}

void Layer_SnakeAuto::getMainGameLayer(CCLayer* pLayer)
{
	mainLayer = pLayer;
}
