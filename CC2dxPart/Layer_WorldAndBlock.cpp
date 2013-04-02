#include "Layer_WorldAndBlock.h"
#include "cocos2d.h"
using namespace cocos2d;

Layer_WorldAndBlock::Layer_WorldAndBlock()
{
	
}
void Layer_WorldAndBlock::readWorldGridAndDraw(World* WorldClass)
{
	WorldGridSprites = new CCSprite**[WorldClass->World_SizeY];
	int i,j;
	for (i=0; i<WorldClass->World_SizeY; i++)
		WorldGridSprites[i] = new CCSprite*[WorldClass->World_SizeX];

	for (i=0; i<WorldClass->World_SizeY; i++)
	{
		for (j=0; j<WorldClass->World_SizeX; j++)
		{
			if (WorldClass->WorldGrid[i][j] == WALL_CELL)
			{
				WorldGridSprites[i][j] = CCSprite::create(ICON_BLOCK);
				CC_BREAK_IF(! WorldGridSprites[i][j]);
				WorldGridSprites[i][j]->setPosition( ccp(ICON_SIZE*j + ICON_SIZE/2 ,ICON_SIZE*i + ICON_SIZE/2) );//
				mainLayer->addChild(WorldGridSprites[i][j], 0);
			}
			if (WorldClass->WorldGrid[i][j] == BLANK_CELL)
			{
		//		WorldGridSprites[i][j] = CCSprite::create();
			}
		}
	}
}
void Layer_WorldAndBlock::getMainGameLayer(CCLayer* pLayer)
{
	mainLayer = pLayer;
}