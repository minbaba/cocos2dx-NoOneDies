//
//  GameOverScene.h
//  NoOneDies
//
//  Created by dell on 15/8/21.
//
//

#ifndef __NoOneDies__GameOverScene__
#define __NoOneDies__GameOverScene__

#include <cocos2d.h>

class GameOver:cocos2d::Layer {
    public:
    virtual bool init();
    CREATE_FUNC(GameOver);
    static cocos2d::Scene * createScene();
};

#endif /* defined(__NoOneDies__GameOverScene__) */
