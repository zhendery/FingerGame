#ifndef __DIFFERENT__
#define __DIFFERENT__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "GameLayer.h"
#include "vector"

#define random(x) (rand()%x)

USING_NS_CC;
using namespace ui;

//class Block :public Sprite {
//
//private:
//	static Vector<Block*> * blocks;
//	int lineIndex;
//	bool dif = false;
//
//public:
//	void setDif(bool dif);
//	bool getDif();
//	static Vector<Block*> * getBlocks();
//	static void removeAllBlocks();
//
//
//	static Block* createWithArgs(Color3B color, Size size, std::string label, float fontSize, Color4B textColor);
//	virtual bool initWithArgs(Color3B color, Size size, std::string label, float fontSize, Color4B textColor);
//
//
//	static Block* createWithArgs(int angle, Size size, std::string label, float fontSize, Color4B textColor);
//	virtual bool initWithArgs(int angle, Size size, std::string label, float fontSize, Color4B textColor);
//
//	void removeBlock();
//
//	int getLineIndex();
//	void setLineIndex(int lineIndex);
//
//	void moveDown();
//};

class GameLayer;
class Different : public GameLayer
{
public:
//	CREATE_FUNC(Different)
//		bool init();
//
//	// a selector callback
//	void menuCloseCallback(cocos2d::Ref* pSender);
//	void addStartLine();
//	void addNormalLine(int lineIndex);
//	void moveDown();
//
//	void startGame();
//
//	virtual void update(float dt);
//
//private:
//	Size visibleSize;
//	int linesCount;
//	bool showEnd;
//	Label *timerLabel;
//	Node *gameLayer;
//	bool timerRunning;
//	long startTime;
//	static const int dirs_pre[36][3];
//
};

#endif // __DIFFERENT__
