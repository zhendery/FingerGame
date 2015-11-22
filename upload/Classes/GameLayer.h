#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

#define random(x) (rand()%x)

USING_NS_CC;
using namespace ui;

class GameLayer : public Layer
{
public:
	bool isRunning;
	bool initTitle();
	bool initButtons();
	//virtual void keyBackClicked()

protected:
	Text *scoreTxt, *timeTxt;
	Node *titleThings;
	Node *loseThings,*pauseLayer;

	//游戏数值
	int   score = 0;
	int  timeAll = 30;//暂定30秒
	float time = 0,timeP = 0.01f,timeS = -5;//每错一个减5秒

	virtual void reset(){};
	void running(float dt); 
	void setTime(float timePlus);
	void setScore(int scorePlus);
	void loseGame();
	void clickButton(Ref *ref);
};

#endif // __GAME_LAYER_H__
