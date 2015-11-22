#include "MainScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SelectLayer.h"

using namespace cocostudio::timeline;
using namespace std;

Color3B colors[9] = {
	ccc3(178, 34, 34),//ºì
	ccc3(255, 127, 0),//³È»Æ
	ccc3(0, 255, 255),//ÁÁÀ¶
	ccc3(0, 255, 127),//´äÂÌ
	ccc3(255, 215, 0),//½ð»Æ
	ccc3(176, 48, 96),//×Ïºì
	ccc3(255, 20, 147),//Éî·Û
	ccc3(186, 85, 211),//Ç³×Ï
	ccc3(34, 139, 34),//ÉîÂÌ
};

static MainScene *scene = NULL;
MainScene* MainScene::Instance(){
	if (scene == NULL)
		scene = create();
	return scene;
}
bool MainScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	LayerColor *layer = LayerColor::create(ccc4(210, 210, 210, 255));
	this->addChild(layer);

	rootNode = CSLoader::createNode("Welcome.csb");
	rootNode->setAnchorPoint(ANCHOR_CENTER);
	rootNode->setPosition(Director::getInstance()->getWinSize() / 2);
	this->addChild(rootNode);

	Button *startButton = static_cast<Button*>(rootNode->getChildByName("startButton"));
	startButton->addClickEventListener(CC_CALLBACK_1(MainScene::clickButton, this));

	selectLayer = SelectLayer::create();
	this->addChild(selectLayer);
	selectLayer->setVisible(false);

	return true;
}
void MainScene::clickButton(Ref *ref){
	string name = (static_cast<Node*> (ref))->getName();
	if (name == "startButton"){
		this->rootNode->setVisible(false);
		selectLayer->setVisible(true);
	}
}