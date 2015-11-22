#include "ClickMe.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include <math.h>
#include "MainScene.h"

using namespace cocostudio::timeline;
const int ClickMe::dirs_plus[8] = { 4, 5, 1, -3, -4, -5, -1, 3 };
const int ClickMe::dirs_pre[16][8] = {
		{ 0, 1, 2, 0, 1, 2, 0, 1 },//����0
		{ 6, 7, 0, 1, 2, 6, 7, 0 },//��1
		{ 6, 7, 0, 1, 2, 1, 2, 6 },//��2
		{ 6, 7, 0, 6, 7, 0, 6, 7 },//����3

		{ 0, 1, 2, 3, 4, 0, 1, 2 },//��4
		{ 0, 1, 2, 3, 4, 5, 6, 7 },//��5
		{ 0, 1, 2, 3, 4, 5, 6, 7 },//��6
		{ 4, 5, 6, 7, 0, 4, 5, 6 },//��7

		{ 0, 1, 2, 3, 4, 3, 4, 0 },//��8
		{ 0, 1, 2, 3, 4, 5, 6, 7 },//��9
		{ 0, 1, 2, 3, 4, 5, 6, 7 },//��10
		{ 4, 5, 6, 7, 0, 4, 5, 6 },//��11

		{ 2, 3, 4, 2, 3, 4, 2, 3 },//����12
		{ 2, 3, 4, 5, 6, 2, 3, 4 },//��13
		{ 2, 3, 4, 5, 6, 5, 6, 2 },//��14
		{ 4, 5, 6, 4, 5, 6, 4, 5 },//����15
};

bool ClickMe::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Node* rootNode = CSLoader::createNode("ClickMe.csb");
	rootNode->setAnchorPoint(ANCHOR_CENTER);
	rootNode->setPosition(Director::getInstance()->getWinSize() / 2);
	this->addChild(rootNode);

	getData(rootNode);
	reset();

	return true;
}
void ClickMe::getData(Node* root){
	Node  *gameThings = root->getChildByName("gameThings"),
		*background = gameThings->getChildByName("background");
	titleThings = gameThings->getChildByName("titleThings");
	//*loseThings = root->getChildByName("loseThings");

	for (int row = 0; row < 4; ++row){
		for (int col = 0; col < 4; ++col){
			int index = row * 4 + col;
			char name[20];
			sprintf(name, "button_%d_%d", row, col);
			this->buttons[index] = static_cast<Button*>(background->getChildByName(name));
			this->buttons[index]->addTouchEventListener(this, toucheventselector(ClickMe::clickButton));
			this->buttons[index]->setTag(index);
			this->arrows[index] = static_cast<Sprite *>(buttons[index]->getChildByName("arrow"));
		}
	}

	this->initTitle();
	this->initButtons();

	/*
		this->lose = static_cast<Sprite*>(loseThings);
		this->scoreLose = static_cast<Text *>(lose->getChildByName("score"));
		this->comment = static_cast<Text *>(lose->getChildByName("comment"));
		this->againButton = static_cast<Button *>(lose->getChildByName("againButton"));
		this->againButton->addTouchEventListener(this, toucheventselector(ClickMe::resetButton));*/
}
void ClickMe::clickButton(Ref *ref, Widget::TouchEventType type){
	if (type == Widget::TouchEventType::BEGAN){
		int index = static_cast<Node*>(ref)->getTag();//����ð�ť�����¸ð�ť

		if (this->last == -1){//��Ϸδ��ʼ
			this->schedule(schedule_selector(ClickMe::running), 0.01);
			this->isRunning = true;
		}
		else{
			//��Ϸ�Ѿ���ʼ�����ж�last�뵱ǰ��ť�Ƿ���ϣ��������ʱ��,���������ʱ�䲢���ı䵱ǰ��ť
			if (this->last == index){//�����
				this->setTime(this->timeP);
				this->setScore(1);
				this->scoreTxt->setString("" + (++this->score));
			}
			else{//�����
				this->setTime(this->timeS);
				//this->blinkAction();
				return;
			}
		}

		//����ť��ָ�°�ť����last,���ı䰴ť����
		this->last = index + this->dirs_plus[this->dirs[index]];
		this->setDir(index);
	}
}
void ClickMe::resetButton(Ref *ref, Widget::TouchEventType type){
	if (type == Widget::TouchEventType::BEGAN)
		this->reset();
}
void ClickMe::setDir(int index){
	int ran = random(8);
	while (ran == this->dirs[index])
		ran = random(8);
	int dir = this->dirs_pre[index][ran];
	this->dirs[index] = dir;

	Color3B color = colors[(int) random(9)];
	this->arrows[index]->setColor(color);
	this->arrows[index]->setRotation(45 * dir);
}
void ClickMe::reset(){
	//��ԭ���м�ͷ������ɫ�������ʽ)
	for (int i = 0; i < 16; ++i)
		this->setDir(i);
	initTitle();

		//��ʧʧ�����
		//	this->lose->setVisible(false);
}