#ifndef __CLICK_ME_H__
#define __CLICK_ME_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "GameLayer.h"

#define random(x) (rand()%x)

USING_NS_CC;
using namespace ui;
class GameLayer;
class ClickMe : public GameLayer
{
public:
	CREATE_FUNC(ClickMe)
		bool init();
protected:
	void reset();
private:
	Button *buttons[16];
	Sprite *arrows[16];

	Sprite *lose;
	Text *scoreLose;
	Text *comment;
	Button *againButton;
	Button   *shareButton;

	//游戏数值
	int	last = -1;//上一个方向，为-1表示游戏未开始

	void setDir(int);
	void getData(Node* rootNode);
	void clickButton(Ref *, Widget::TouchEventType);
	void resetButton(Ref *, Widget::TouchEventType);

	int dirs[16];
	static const int dirs_plus[8];
	static const int dirs_pre[16][8];
	/*static char* comments [] [] = {
			{
			"生活好无聊，没事多点点",
			"你就这点能耐了？",
			"回去多练练再来吧！",
			"逗bi逗bi，逗的就是你",
			"你其实不该那么自信的",
			"一定是天太热，你才会那么慢",
			"你该检查检查视力了",
			"对不起，但你是个好人"
			},
			{
			"不错不错，比蜗牛稍快点",
			"擦擦屏幕，再接再厉",
			"天色还早，咱们洗洗再来",
			"屏幕没买保险吗？怎么不敢点"
			},
			{
			"我要对你另眼相看了！",
			"再点点，就可以晋级啦",
			"反应不错嘛，我看好你哦",
			"前方高能，能点才是王道"
			},
			{
			"你已经超神了，快去炫耀",
			"神挡杀神，佛挡杀佛",
			"这手速~你懂的^_^",
			"天哪，我居然被你打败了",
			"你就是传说中美爆六界的杀阡陌"
			}
			};*/

};

#endif // __CLICK_ME_H__
