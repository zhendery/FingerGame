#include "GameLayer.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include <math.h>
#include "MainScene.h"

using namespace cocostudio::timeline;

bool GameLayer::initButtons(){
	Node* rootNode = CSLoader::createNode("buttons.csb");
	rootNode->setAnchorPoint(ANCHOR_CENTER);
	rootNode->setPosition(Director::getInstance()->getWinSize() / 2);
	this->addChild(rootNode);

	Button *button = static_cast<Button*>(rootNode->getChildByName("backButton"));
	button->addClickEventListener(CC_CALLBACK_1(GameLayer::clickButton, this));

	button = static_cast<Button*>(rootNode->getChildByName("pauseButton"));
	button->addClickEventListener(CC_CALLBACK_1(GameLayer::clickButton, this));

	loseThings = CSLoader::createNode("lose.csb");
	loseThings->setAnchorPoint(ANCHOR_CENTER);
	loseThings->setPosition(Director::getInstance()->getWinSize() / 2);
	this->addChild(loseThings);

	button = static_cast<Button*>(loseThings->getChildByName("homeButton"));
	button->addClickEventListener(CC_CALLBACK_1(GameLayer::clickButton, this));

	button = static_cast<Button*>(loseThings->getChildByName("resetButton"));
	button->addClickEventListener(CC_CALLBACK_1(GameLayer::clickButton, this));

	loseThings->setVisible(false);

	pauseLayer = CSLoader::createNode("pauseLayer.csb");
	pauseLayer->setAnchorPoint(ANCHOR_CENTER);
	pauseLayer->setPosition(Director::getInstance()->getWinSize() / 2);
	this->addChild(pauseLayer);

	button = static_cast<Button*>(pauseLayer->getChildByName("resumeButton"));
	button->addClickEventListener(CC_CALLBACK_1(GameLayer::clickButton, this));

	pauseLayer->setVisible(false);

	return true;
}
void GameLayer::clickButton(Ref *ref){
	std::string name = (static_cast<Node*> (ref))->getName();
	if (name == "backButton")
	{
		Director::getInstance()->end();
	}
	else{
		if (name == "pauseButton")
		{
			isRunning = false;
			pauseLayer->setVisible(true);
		}
		else{
			if (name == "homeButton")
			{
				this->getParent()->removeChild(this);
				//
			}
			else{
				if (name == "resetButton")
				{
					this->reset();
				}
				else{
					if (name == "resumeButton")
					{
						isRunning = true;
						pauseLayer->setVisible(false);
					}
				}
			}
		}
	}
}
bool GameLayer::initTitle(){
	scoreTxt = static_cast<Text*>(titleThings->getChildByName("score"));
	timeTxt = static_cast<Text*>(titleThings->getChildByName("time"));

	//还原时间及时间条
	this->time = this->timeAll;

	//还原游戏状态 分数等
	this->score = 0;

	this->schedule(schedule_selector(GameLayer::running), 0.01f);
	setScore(0);
	return true;
}

void GameLayer::running(float dt){
	if (isRunning){
		if (this->time <= 0){//输了
			loseGame();
		}
		else{
			this->setTime(-dt);//每dt执行一次，减少时间条
		}
	}
}
void GameLayer::setScore(int scorePlus){
	this->score += scorePlus;
	char scoreChar[20];
	sprintf(scoreChar, "%d", this->score);
	this->scoreTxt->setString(scoreChar);
}
void GameLayer::setTime(float timePlus){
	this->time += timePlus;
	int integer = time, xiaoshu = (time - integer) * 100;
	char timeChar[20];
	sprintf(timeChar, "%2d'%2d", integer,xiaoshu);
	this->timeTxt->setString(timeChar);
	this->timeTxt->setColor(colors[std::max(0, std::min(3, (int) this->time / this->timeAll * 4))]);
}
void GameLayer::loseGame(){
	log("lose GAme");
	this->isRunning = false;
	this->unschedule(schedule_selector(GameLayer::running));
}