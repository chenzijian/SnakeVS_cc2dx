#include "GameOverScene.h"
#include "GameStartScene.h"
#include "Icon_Header.h"
#include "../SnakePart/SnakeVS_Game.h"
USING_NS_CC;


CCScene* GameOverScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameOverScene *layer = GameOverScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameOverScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pBackItem = CCMenuItemImage::create(
                                        ICON_BACK,
                                        ICON_BACK,
                                        this,
                                        menu_selector(GameOverScene::menuCloseCallback));
    
	pBackItem->setPosition(ccp(origin.x + pBackItem->getContentSize().width/3*7 ,
                                origin.y + pBackItem->getContentSize().height));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pBackItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);


	CCMenuItemImage *pRetryItem = CCMenuItemImage::create(
                                        ICON_NEWGAME,
                                        ICON_NEWGAME,
                                        this,
                                        menu_selector(GameOverScene::menuCloseCallback2));
    
	pRetryItem->setPosition(ccp(origin.x + pRetryItem->getContentSize().width/3*2 ,
                                origin.y + pRetryItem->getContentSize().height));

    // create menu, it's an autorelease object
    CCMenu* pMenu2 = CCMenu::create(pRetryItem, NULL);
    pMenu2->setPosition(CCPointZero);
    this->addChild(pMenu2, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("Game Over", "Arial", 50);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height/2 +(pLabel->getContentSize().height)/2));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create(ICON_BGMENU);

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    return true;
}


void GameOverScene::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(GameStartScene::scene());
}

void GameOverScene::menuCloseCallback2(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(SnakeVS_Game::SnakeVS_Game_Scene());
}
