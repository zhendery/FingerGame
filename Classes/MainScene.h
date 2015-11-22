#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

extern Color3B colors[9];
const Vec2 ANCHOR_CENTER = ccp(0.5f, 0.5f);

class MainScene : public Scene
{
public:
	static MainScene *Instance();

	Layer *selectLayer, *gameLayer;
	Node* rootNode;

	CREATE_FUNC(MainScene)
		bool init();

private:
	void clickButton(Ref *ref);
};

#endif // __MAIN_SCENE_H__
