//
//  TestOtherScene_by_sceneStack.cpp
//  megamistrike
//
//  Created by ALICE on 2015/02/17.
//
//

#include "TestOtherScene_by_sceneStack.h"


TestLayer::TestLayer()
{
	log("constractor");
}



bool TestLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
	log(" this is a test layer !!!!!!!!!!!!!!!");
	Director::getInstance()->popScene();
	return true;
};


bool TestLayer::init()
{
	LayerColor::init();
	
	
	return true;
}