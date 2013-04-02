#ifndef __GAMESTARTSCENE_H__
#define __GAMESTARTSCENE_H__

#include "cocos2d.h"

class GameStartScene : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
	void menuCloseCallback2(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(GameStartScene);
};

#endif // __GAMESTARTSCENE_H__
