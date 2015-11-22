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

	//��Ϸ��ֵ
	int	last = -1;//��һ������Ϊ-1��ʾ��Ϸδ��ʼ

	void setDir(int);
	void getData(Node* rootNode);
	void clickButton(Ref *, Widget::TouchEventType);
	void resetButton(Ref *, Widget::TouchEventType);

	int dirs[16];
	static const int dirs_plus[8];
	static const int dirs_pre[16][8];
	/*static char* comments [] [] = {
			{
			"��������ģ�û�¶���",
			"�����������ˣ�",
			"��ȥ�����������ɣ�",
			"��bi��bi�����ľ�����",
			"����ʵ������ô���ŵ�",
			"һ������̫�ȣ���Ż���ô��",
			"��ü����������",
			"�Բ��𣬵����Ǹ�����"
			},
			{
			"����������ţ�Կ��",
			"������Ļ���ٽ�����",
			"��ɫ���磬����ϴϴ����",
			"��Ļû��������ô���ҵ�"
			},
			{
			"��Ҫ���������࿴�ˣ�",
			"�ٵ�㣬�Ϳ��Խ�����",
			"��Ӧ������ҿ�����Ŷ",
			"ǰ�����ܣ��ܵ��������"
			},
			{
			"���Ѿ������ˣ���ȥ��ҫ",
			"��ɱ�񣬷�ɱ��",
			"������~�㶮��^_^",
			"���ģ��Ҿ�Ȼ��������",
			"����Ǵ�˵�����������ɱ��İ"
			}
			};*/

};

#endif // __CLICK_ME_H__
