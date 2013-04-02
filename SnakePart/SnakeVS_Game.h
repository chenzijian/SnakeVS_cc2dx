#ifndef __SNAKEVS_GAME_H__
#define __SNAKEVS_GAME_H__

#include "World.h"

#include "../CC2dxPart/Layer_WorldAndBlock.h"
#include "../CC2dxPart/Layer_Food.h"
#include "../CC2dxPart/Layer_SnakeAuto.h"
#include "../CC2dxPart/Layer_SnakeHuman.h"
#include "../CC2dxPart/Layer_TouchControl.h"

#include <conio.h>

#include "cocos2d.h"
using namespace cocos2d;

class SnakeVS_Game : public CCLayer
{
public:
	//basic class
	World *WorldClass;
	Snake_Auto *Snake_AutoClass;
	Snake_Human *Snake_HumanClass;
	Food *FoodClass;
	Block *BlockClass;

	//Draw Sprites Class
	Layer_WorldAndBlock *Layer_WorldAndBlockClass;
	Layer_Food *Layer_FoodClass;
	Layer_SnakeAuto *Layer_SnakeAutoClass;
	Layer_SnakeHuman *Layer_SnakeHumanClass;
	Layer_TouchControl *Layer_TouchControlClass;

	SnakeVS_Game();
	void SnakeVS_Game_Init();
	static CCScene* SnakeVS_Game_Scene();

	//Layer used Create
	virtual bool init();
	virtual void onEnter();
	void menuCloseCallback(CCObject* pSender);
	CREATE_FUNC(SnakeVS_Game);

	//CC2dx Schedule : refresh movement
	bool SnakeHuman_DeadDef();
	void refreshSnakeHuman(float dt);
	void refreshSnakeAuto(float dt);

	//CC2dx touch enable
	void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
};

#endif