//
//  GameComtroller.cpp
//  NoOneDies
//
//  Created by dell on 15/8/21.
//
//

#include "GameController.h"
#include "Edge.h"
#include "Hero.h"
#include "Block.h"

USING_NS_CC;
//初始化方法
bool GameController::init(cocos2d::Layer *layer, float positionY) {
    _positionY = positionY;
    _layer = layer;
    
    //获取屏幕大小
    visibleSize = Director::getInstance()->getVisibleSize();
    
    //创建边界
    edge = Edge::create();
    edge->setPosition(visibleSize.width/2, edge->getContentSize().height/2 +positionY);
    _layer->addChild(edge);
    
    //添加一个地板
    auto ground = Sprite::create();
    ground->setColor(Color3B(0, 0, 0));
    ground->setTextureRect(Rect(0, 0, visibleSize.width, 3));
    ground->setPosition(visibleSize.width /2, 1.5 + positionY);
    _layer->addChild(ground);
    
    //添加一个小人
    hero = Hero::create();
    hero->setPosition(Point(50, hero->getContentSize().height /2 + _positionY));
    _layer->addChild(hero);
    
    //重置时间器
    resetFrames();
    
    return true;
}
//更新镇率
void GameController::onUpdate() {
    cureentFrameIndex ++;
    if (cureentFrameIndex == nextFramCount) {
        
        //添加方块
        addBlock();
        
        //重置时间器
        resetFrames();
    }
}
//添加方块
void GameController::addBlock() {
    auto block = Block::create();
    block->setPositionY(block->getContentSize().height /2 + _positionY);
    _layer->addChild(block);
}
//重置帧数
void GameController::resetFrames() {
    cureentFrameIndex = 0;
    
    //随机获取下一次生成方块所需的帧数
    nextFramCount = arc4random() %220 +200;
}
//创造方法
GameController * GameController::create(Layer *layer, float positionY) {
    auto _ins = new GameController();
    _ins->init(layer, positionY);
    _ins->autorelease();
    return _ins;
}
//判断点是否在自己所属范围
bool GameController::hitTestPoint(cocos2d::Vec2 point) {
    return edge->getBoundingBox().containsPoint(point);
}
//当被触摸
void GameController::onTouch() {
    //判断当前小人状态是否是跳跃
    if (hero->getPositionY() <= _positionY +hero->getContentSize().height /2 +5) {
        //若不是，给一个向上的力
        hero->getPhysicsBody()->setVelocity(Vec2(0, 100));
    }
}