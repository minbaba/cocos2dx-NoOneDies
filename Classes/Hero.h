//
//  Hero.h
//  NoOneDies
//
//  Created by dell on 15/8/20.
//
//

#ifndef __NoOneDies__Hero__
#define __NoOneDies__Hero__

#include <stdio.h>
#include <cocos2d.h>

class Hero: public cocos2d::Sprite{
public:
    virtual bool init();
    CREATE_FUNC(Hero);
};

#endif /* defined(__NoOneDies__Hero__) */
