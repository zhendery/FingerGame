#include "SelectLayer.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "MainScene.h"

#include "Slide.h"
#include "ClickMe.h"
#include "Different.h"

using namespace cocostudio::timeline;
bool SelectLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Node* rootNode = CSLoader::createNode("SelectScene.csb");
	rootNode->setAnchorPoint(ANCHOR_CENTER);
	rootNode->setPosition(Director::getInstance()->getWinSize() / 2);
	this->addChild(rootNode);

	Node *selectContainer = rootNode->getChildByName("selectContainer"),
		*panel1 = selectContainer->getChildByName("Panel_1"),
		*panel2 = selectContainer->getChildByName("Panel_2");

	UserDefault::getInstance()->getIntegerForKey("lock", 1);

	Button *button = static_cast<Button*>(panel1->getChildByName("slide"));
	button->addClickEventListener(CC_CALLBACK_1(SelectLayer::clickButton, this));

	button = static_cast<Button*>(panel1->getChildByName("clickMe"));
	//button->setEnabled(false);
	button->addClickEventListener(CC_CALLBACK_1(SelectLayer::clickButton, this));

	button = static_cast<Button*>(panel1->getChildByName("different"));
//	button->setEnabled(false);
	button->addClickEventListener(CC_CALLBACK_1(SelectLayer::clickButton, this));

	button = static_cast<Button*>(panel1->getChildByName("comming"));
	button->setEnabled(false);
	button->addClickEventListener(CC_CALLBACK_1(SelectLayer::clickButton, this));

	return true;
}
void SelectLayer::clickButton(Ref *ref){
	std::string name = (static_cast<Node*> (ref))->getName();
	if (name == "slide")
		MainScene::Instance()->gameLayer = Slide::create();
	else{
		if (name == "clickMe")
			MainScene::Instance()->gameLayer = ClickMe::create();
		else{
			if (name == "different")
				MainScene::Instance()->gameLayer = Different::create();
		}

	}
	MainScene::Instance()->addChild(MainScene::Instance()->gameLayer);
	this->setVisible(false);
}