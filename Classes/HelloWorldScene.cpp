#include "HelloWorldScene.h"
#include "GameOverScene.h"


USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setGravity(Vec2(0, -120));
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B(255, 255, 255, 255)) )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    //创建游戏控制器
    for (int i = 0 ; i <4; i++) {
        gameControllers.pushBack(GameController::create(this, 30 + (visibleSize.height /5 +10)* i));
    }
    //gameControllers.insert(0, GameController::create(this, 200));
    
    //添加碰撞检测监听器
    auto listener = EventListenerPhysicsContact::create();
    listener->onContactBegin = [this](PhysicsContact & contact) {
        this->unscheduleUpdate();
        
        //结束游戏
        auto scene = GameOver::createScene();
        Director::getInstance()->replaceScene(TransitionMoveInT::create(1, scene));
        return true;
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    //创建触摸监听器
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [this](Touch *touch, Event *event) {
        for (auto it = gameControllers.begin(); it != gameControllers.end(); it++) {
            if ((*it)->hitTestPoint(touch->getLocation())) {
                (*it)->onTouch();
                break;
            }
        }
        return false;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    //启动计时器
    scheduleUpdate();
    
    return true;
}

//周期调用的更新方法
void HelloWorld::update(float dt) {
    for (auto it = gameControllers.begin(); it != gameControllers.end(); it ++) {
        (*it)->onUpdate();
    }
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
