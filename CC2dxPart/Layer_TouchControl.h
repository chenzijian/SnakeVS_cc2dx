#ifndef __LAYER_TOUCHCONTROL_H__
#define __LAYER_TOUCHCONTROL_H__

#include "Icon_Header.h"
#include "../SnakePart/Snake_Human.h"
#include "cocos2d.h"
using namespace cocos2d;

class Layer_TouchControl : public cocos2d::CCLayer
{
public:
	Snake_Human *Snake_HumanClass;
	CCLabelTTF* pLabel;
	
	Layer_TouchControl();
	void readSnakeHumanClass(Snake_Human* SH);

	virtual bool init();
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
	CREATE_FUNC(Layer_TouchControl);
};

#endif