//
//  TestOtherScene_by_sceneStack.h
//  megamistrike
//
//  Created by ALICE on 2015/02/17.
//
//

#ifndef __megamistrike__TestOtherScene_by_sceneStack__
#define __megamistrike__TestOtherScene_by_sceneStack__

#include "boot_cocos.h"


/*
 プッシュシーン　と、　ポップシーン　のテスト用に作成。順調。
 
 しかして、プッシュすると、前のシーンの画面が消えてしまう！！！！！！！
 仕方ない。
 */


	class TestLayer : public LayerColor
	{
	public:
		TestLayer();
		virtual ~TestLayer(){};
	public:
		
		CREATE_FUNC(TestLayer);
		
		virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
		
		virtual bool init();
		
		virtual void onEnter() override
		{
			LayerColor::onEnter();
			
			auto dispatcher = Director::getInstance()->getEventDispatcher();
			EventListenerTouchOneByOne *m_eventListener = EventListenerTouchOneByOne::create();
			
			m_eventListener->onTouchBegan	= CC_CALLBACK_2(TestLayer::onTouchBegan, this);
			
			dispatcher->addEventListenerWithSceneGraphPriority(m_eventListener, this);
			
		};
		
		virtual void onExit() override
		{
			LayerColor::onExit();
			auto dispatcher = Director::getInstance()->getEventDispatcher();
			dispatcher->removeEventListener(m_eventListener);
		};
		
	public:
		EventListenerTouchOneByOne *m_eventListener;
	};

class TestOtherScene : public Scene
{
public:


	static Scene *createScene()
	{
		auto scene = TestOtherScene::create();
		auto layer = TestLayer::create();
		auto txt = Label::createWithSystemFont("pushシーン。　popしてください！", "", 40);
		txt->setAnchorPoint(Vec2(0,0));
		txt->setPosition(Vec2(0, 568));
		layer->addChild(txt);
		
		scene->addChild(layer);
		
		return scene;
	};
	
};

#endif /* defined(__megamistrike__TestOtherScene_by_sceneStack__) */
