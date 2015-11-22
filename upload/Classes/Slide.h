#ifndef __SLIDE_H__
#define __SLIDE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "GameLayer.h"
#include "vector"

#define random(x) (rand()%x)

USING_NS_CC;
using namespace ui;

class GameLayer;
class Slide : public GameLayer
{
public:
	CREATE_FUNC(Slide)
		bool init();

private:
	int currentArrow;
	float speed;
	Sprite* arrows[6];
	Node *arrowGroups[3];

	int dirs[6];
	bool trues[2];
	Text *text;

	void update(float dt);
	void onTouchesEnded(const std::vector<Touch*>& touches, cocos2d::Event  *event);
	void slide(int index,int dir);

	void start();
	void setDir(int index);
};

#endif // __SLIDE_H__
