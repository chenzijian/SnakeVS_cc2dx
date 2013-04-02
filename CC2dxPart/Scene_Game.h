#include "cocos2d.h"
using namespace cocos2d;

class Scene_Game:public CCScene 
{ 
public: 
    Scene_Game(); 
public: 
    virtual void onEnter(); 
 
    virtual void runThisTest(); 
 
    void daySceneCallback(CCObject* pSender); 
 
    void nightSceneCallback(CCObject* pSender); 
}; 