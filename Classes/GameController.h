//
//  GameComtroller.h
//  NoOneDies
//
//  Created by dell on 15/8/21.
//
//

#ifndef __NoOneDies__GameComtroller__
#define __NoOneDies__GameComtroller__

#include <stdio.h>
#include <cocos2d.h>
//前向声明
class Edge;
class Hero;

class GameController:public cocos2d::Ref {
private:
    //宿主层
    cocos2d::Layer *_layer;
    //y坐标
    float _positionY;
    cocos2d::Size visibleSize;
    //当前执行帧数
    int cureentFrameIndex;
    //到下一次生成block需要的帧数
    int nextFramCount;
    //边界
    Edge *edge;
    //小人
    Hero *hero;
    
public:
    /**初始化方法*/
    virtual bool init(cocos2d::Layer *layer, float positionY);
    /**创造方法*/
    static GameController * create(cocos2d::Layer *layer, float positionY);
    /**更新帧数*/
    virtual void onUpdate();
    /**判断是否包含某个点*/
    bool hitTestPoint(cocos2d::Vec2 point);
    /**被触摸时执行*/
    void onTouch();
private:
    /**重置帧数*/
    void resetFrames();
    /**添加方块*/
    void addBlock();
};


#endif /* defined(__NoOneDies__GameComtroller__) */
