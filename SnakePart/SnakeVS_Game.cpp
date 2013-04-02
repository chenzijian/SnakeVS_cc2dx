#include "Game_Option.h"
#include "../CC2dxPart/GameStartScene.h"
#include "../CC2dxPart/GameOverScene.h"
#include "SnakeVS_Game.h"
#include "cocos2d.h"
using namespace cocos2d;

#include <iostream>

SnakeVS_Game::SnakeVS_Game()
{
}

void SnakeVS_Game::SnakeVS_Game_Init()
{	
	//Basic Class
	WorldClass = new World();
	BlockClass = new Block();
	FoodClass = new Food();
	Snake_AutoClass = new Snake_Auto();
	Snake_HumanClass = new Snake_Human();

	WorldClass->World_AddObjectClass(Snake_AutoClass, Snake_HumanClass, FoodClass, BlockClass);
	WorldClass->World_ChangeMap();

	//Layer (Sprites) Class
	Layer_WorldAndBlockClass = new Layer_WorldAndBlock();
	Layer_FoodClass = new Layer_Food();
	Layer_SnakeAutoClass = new Layer_SnakeAuto();
	Layer_SnakeHumanClass = new Layer_SnakeHuman();
	
	//Class Get Layer:SnakeVS_Game
	Layer_WorldAndBlockClass->getMainGameLayer(this);
	Layer_FoodClass->getMainGameLayer(this);
	Layer_SnakeAutoClass->getMainGameLayer(this);
	Layer_SnakeHumanClass->getMainGameLayer(this);

	//Draw to Layer:SnakeVS_Game
	Layer_WorldAndBlockClass->readWorldGridAndDraw(WorldClass);
	Layer_FoodClass->readFoodPosAndDraw(FoodClass);
	Layer_SnakeAutoClass->readSnakeAutoAndDraw(Snake_AutoClass);
	Layer_SnakeHumanClass->readSnakeHumanAndDraw(Snake_HumanClass);

	//Schedule Snake and DeadDef
	schedule(schedule_selector(SnakeVS_Game::refreshSnakeHuman), 1.0f/SNAKE_HUMAN_TPS);
	schedule(schedule_selector(SnakeVS_Game::refreshSnakeAuto), 1.0f/SNAKE_AUTO_TPS);

	//Close Botton
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
    menu_selector(SnakeVS_Game::menuCloseCallback));

    pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));

    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);

    this->addChild(pMenu);
}

bool SnakeVS_Game::init()
{
    bool bRet = false;
    do 
    {
        CC_BREAK_IF(! CCLayer::init());

       	SnakeVS_Game_Init();

        bRet = true;
    } while (0);

    return bRet;
}

CCScene* SnakeVS_Game::SnakeVS_Game_Scene()
{
	 CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        SnakeVS_Game *layer = SnakeVS_Game::create();
        CC_BREAK_IF(! layer);
		layer->setTouchEnabled(true);
        scene->addChild(layer);

		CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
		CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

		CCSprite* bgicon = CCSprite::create(ICON_BGPLAY);
		bgicon->setPosition(ccp(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
		CCLayer* bglayer = CCLayer::create();
		bglayer->addChild(bgicon, -1);
		scene->addChild(bglayer, -1);

    } while (0);

    // return the scene
    return scene;
}
void SnakeVS_Game::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->replaceScene(GameStartScene::scene());;
}

void SnakeVS_Game::onEnter()
{
	CCLayer::onEnter();
}

bool SnakeVS_Game::SnakeHuman_DeadDef() 
{
	if (WorldClass->World_SnakeHuman_EatItself() || WorldClass->World_SnakeHuman_OnWall() || WorldClass->World_SHandSAencounter())
	{
		Snake_HumanClass->isDead = true;
		return true;
	}
	return false;
}
void SnakeVS_Game::refreshSnakeHuman(float dt)
{
	if (!SnakeHuman_DeadDef())
	{
		if (Snake_HumanClass->Snake_Eaten)
			Snake_HumanClass->Snake_EatAndMoveNextDirection();
		else Snake_HumanClass->Snake_MoveNextDirection();

		WorldClass->World_ChangeMap();
		Layer_SnakeHumanClass->readSnakeHumanAndDraw(Snake_HumanClass);
		Layer_FoodClass->readFoodPosAndDraw(FoodClass);
	//	WorldClass->World_PrintToCmd();
	}
	else {
		CCDirector::sharedDirector()->replaceScene(GameOverScene::scene());//-------------------------------
	}
}
void SnakeVS_Game::refreshSnakeAuto(float dt)
{
	Snake_AutoClass->Snake_Auto_FindNextDir(FoodClass->Food_PosX , FoodClass->Food_PosY);

	if (Snake_AutoClass->Snake_Eaten)
		Snake_AutoClass->Snake_EatAndMoveNextDirection();
	else Snake_AutoClass->Snake_MoveNextDirection();

	Layer_SnakeAutoClass->readSnakeAutoAndDraw(Snake_AutoClass);
	Layer_FoodClass->readFoodPosAndDraw(FoodClass);

	WorldClass->World_ChangeMap();
//	WorldClass->World_PrintToCmd();

}


void SnakeVS_Game::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
    CCSetIterator it = pTouches->begin();
    CCTouch* touch = (CCTouch*)(*it);
    
    CCPoint location = touch->getLocation();

    float TouchX = location.x - (ICON_SIZE*Snake_HumanClass->Snake_BodyX[0] + ICON_SIZE/2);
    float TouchY = location.y - (ICON_SIZE*Snake_HumanClass->Snake_BodyY[0] + ICON_SIZE/2);
	if (Snake_HumanClass->Snake_NowDirection == DIRECTION_UP || Snake_HumanClass->Snake_NowDirection == DIRECTION_DOWN)
	{
		if (TouchX < 0)
			Snake_HumanClass->Snake_ChangeNextDirection(DIRECTION_LEFT);
		if (TouchX > 0)
			Snake_HumanClass->Snake_ChangeNextDirection(DIRECTION_RIGHT);
	}
	if (Snake_HumanClass->Snake_NowDirection == DIRECTION_LEFT || Snake_HumanClass->Snake_NowDirection == DIRECTION_RIGHT)
	{
		if (TouchY < 0)
			Snake_HumanClass->Snake_ChangeNextDirection(DIRECTION_UP);
		if (TouchY > 0)
			Snake_HumanClass->Snake_ChangeNextDirection(DIRECTION_DOWN);
	}
}