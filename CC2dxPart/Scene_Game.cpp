#include "cocos2d.h"
#include "Scene_Game.h"
using namespace cocos2d;

Scene_Game::Scene_Game() 
{ 
    CCScene::init(); 
    
} 
 
void Scene_Game::daySceneCallback(CCObject *pSender) 
{ 
    CCScene* scene =new MyScene(); 
    CCLayer* pLayer = new LayerDay(); 
    scene->addChild(pLayer, 0); 
    CCDirector::sharedDirector()->pushScene(scene); 
    scene->release(); 
    pLayer->release(); 
} 
 
void Scene_Game::nightSceneCallback(CCObject* pSender) 
{ 
    CCScene* scene =new MyScene(); 
    CCLayer* pLayer = new LayerNight(); 
    scene->addChild(pLayer, 0); 
    CCDirector::sharedDirector()->pushScene(scene); 
    scene->release(); 
    pLayer->release(); 
} 
 
void Scene_Game::onEnter() 
{ 
    CCScene::onEnter(); 
} 
 
void Scene_Game::runThisTest() 
{ 
    CCLayer* pLayer = new LayerNight(); 
 
    addChild(pLayer); 
    pLayer->release(); 
 
    CCDirector::sharedDirector()->replaceScene(this); 
} 