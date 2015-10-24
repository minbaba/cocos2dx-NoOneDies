//
//  GameOverScene.cpp
//  NoOneDies
//
//  Created by dell on 15/8/21.
//
//

#include "GameOverScene.h"
#include "HelloWorldScene.h"
USING_NS_CC;
//初始化方法
bool GameOver::init() {
    Layer::init();
    setColor(Color3B::WHITE);
    
    auto size = Director::getInstance()->getVisibleSize();
    //添加一个label 显示结束语
    auto lable = Label::create();
    lable->setString("Game Over!");
    lable->setSystemFontSize(80);
    lable->setTextColor(Color4B::WHITE);
    lable->setPosition(size/2);
    addChild(lable);
    
    //添加另一个label 作为重新开始按钮
    auto label_2 = Label::create();
    label_2->setString("不服，再来");
    label_2->setTextColor(Color4B::WHITE);
    label_2->setSystemFontSize(30);
    label_2->setPosition(size.width/2 , 100);
    addChild(label_2);
    
    //绑定触摸方法
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [label_2](Touch *touch, Event *event){
        if (label_2->getBoundingBox().containsPoint(touch->getLocation())) {
            auto game = HelloWorld::createScene();
            Director::getInstance()->replaceScene(game);
        }
        return false;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}
//创造场景
Scene *GameOver::createScene() {
    auto scene = Scene::create();
    auto layer = GameOver::create();
    scene->addChild(layer);

    return scene;
}
