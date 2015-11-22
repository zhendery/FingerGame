#include "Slide.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include <math.h>
#include "MainScene.h"

using namespace cocostudio::timeline;


bool Slide::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto listen = EventListenerTouchAllAtOnce::create();
	listen->onTouchesEnded = CC_CALLBACK_2(Slide::onTouchesEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listen, this);

	Node* rootNode = CSLoader::createNode("Slide.csb");
	rootNode->setAnchorPoint(ANCHOR_CENTER);
	rootNode->setPosition(Director::getInstance()->getWinSize() / 2);
	this->addChild(rootNode);

	text = static_cast<Text*>(rootNode->getChildByName("text"));
	titleThings = rootNode->getChildByName("gameThings")->getChildByName("titleThings");
	currentArrow = 0;
	for (int i = 0; i < 3; ++i){
		char nodeName[10];
		sprintf(nodeName, "arrow%d", i);
		arrowGroups[i] = rootNode->getChildByName(nodeName);
		arrows[i << 1] = static_cast<Sprite*>(arrowGroups[i]->getChildByName("arrowLeft"));
		arrows[(i << 1) + 1] = static_cast<Sprite*>(arrowGroups[i]->getChildByName("arrowRight"));
	}
	currentArrow = 0;
	start();
	return true;
}
void  Slide::start(){
	isRunning = true;
	this->trues[0] = this->trues[1] = false;
	setDir(0);
	speed = 1;
	this->initTitle();
	this->initButtons();
	scheduleUpdate();
}
void Slide::update(float dt){
	if (isRunning){
		for (int i = 0; i < 3; ++i){
			Node *arrow = this->arrowGroups[i];
			bool upper = arrow->getPositionY() > 960;
			arrow->setPositionY(arrow->getPositionY() - speed);
			if (upper && arrow->getPositionY() <= 960)
				setDir(i);
			if (arrow->getPositionY() <= 300){
				loseGame();//arrow->setPositionY();
			}
		}
		speed += 0.0005f;
	}
}
void Slide::onTouchesEnded(const std::vector<Touch*>& touches, cocos2d::Event  *event){
	Vec2 go = touches[0]->getLocation() - touches[0]->getStartLocation();
	int index = (touches[0]->getStartLocation().x<320) ? 0 : 1;
	if (abs(go.x) > abs(go.y)){
		//×óÓÒ
		if (go.x > 0)
			slide(index, 2);//ÓÒ
		else
			slide(index, 0);//×ó
	}
	else{
		if (go.y > 0)
			slide(index, 1);//ÉÏ
		else
			slide(index, 3);//ÏÂ
	}

}
void Slide::slide(int index, int dir){
	int id = (currentArrow << 1) + index;
	if (dir == dirs[id]){//³É¹¦Æ¥Åä
		trues[index] = true;
	}
	else{
		log("falsesss1");//´íÎó
	}
	if (trues[0] && trues[1]){
		setScore(1);
		arrowGroups[currentArrow]->setPositionY(arrowGroups[(currentArrow + 2) % 3]->getPositionY() + 300);
		this->trues[0] = this->trues[1] = false;
		if (++currentArrow > 2)
			currentArrow = 0;
	}
}

void Slide::setDir(int index){

	for (int i = index << 1; i < (index << 1) + 2; ++i){
		int dir = random(4);

		Color3B color = colors[(int) random(9)];
		this->arrows[i]->setColor(color);
		this->arrows[i]->setRotation(90 * (dir - 1));
		this->dirs[i] = dir;
	}
}