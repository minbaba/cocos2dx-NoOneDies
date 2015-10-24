//
//  Hero.cpp
//  NoOneDies
//
//  Created by dell on 15/8/20.
//
//

#include "Hero.h"
#include "FlashTool.h"

USING_NS_CC;

bool Hero::init() {
    if (!Sprite::init()) {
        return false;
    }
    
    //设置大小
    auto s = Size(44, 52);
    //添加动画
    runAction(RepeatForever::create(FlashTool::readJsonSpriteSheet("Hero.json", 0.2f)));
    setPhysicsBody(PhysicsBody::createBox(s));
    setContentSize(s);
    
    //不旋转
    getPhysicsBody()->setRotationEnable(false);
    //设置碰撞器
    getPhysicsBody()->setContactTestBitmask(1);

    return true;
}