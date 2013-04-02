#include "Layer_TouchControl.h"
#include "cocos2d.h"
using namespace cocos2d;

bool Layer_TouchControl::init()
{
    bool bRet = false;
    do 
    {
		CC_BREAK_IF(! CCLayer::init());
		Snake_HumanClass = NULL;
		this->setTouchEnabled(true);
		bRet = true;
		
		pLabel = CCLabelTTF::create("Here", "Arial", 24);///test
		pLabel->setPosition(ccp(200 , 200));
		this->addChild(pLabel, 1 , 20);
	} while (0);

    return bRet;
}
void Layer_TouchControl::readSnakeHumanClass(Snake_Human* SH)
{
	Snake_HumanClass = SH;
}



