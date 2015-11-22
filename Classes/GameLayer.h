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

	//��Ϸ��ֵ
	int   score = 0;
	int  timeAll = 30;//�ݶ�30��
	float time = 0,timeP = 0.01f,timeS = -5;//ÿ��һ����5��

	virtual void reset(){};
	void running(float dt); 
	void setTime(float timePlus);
	void setScore(int scorePlus);
	void loseGame();
	void clickButton(Ref *ref);
};

#endif // __GAME_LAYER_H__
