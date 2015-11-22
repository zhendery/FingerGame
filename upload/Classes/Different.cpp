#include "Different.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include <math.h>
#include "MainScene.h"

using namespace cocostudio::timeline;
//
//const int Different::dirs_pre[36][3] = {
//		{ 6, 2, 2 }, { 2, 6, 2 }, { 2, 2, 6 },
//		{ 2, 6, 6 }, { 6, 2, 6 }, { 6, 6, 2 },
//		{ 4, 0, 0 }, { 0, 4, 0 }, { 0, 0, 4 },
//		{ 0, 4, 4 }, { 4, 0, 4 }, { 4, 4, 0 },
//		{ 3, 1, 1 }, { 1, 3, 1 }, { 1, 1, 3 },
//		{ 1, 3, 3 }, { 3, 1, 3 }, { 3, 3, 1 },
//		{ 5, 3, 3 }, { 3, 5, 3 }, { 3, 3, 5 },
//		{ 3, 5, 5 }, { 5, 3, 5 }, { 5, 5, 3 },
//		{ 7, 5, 5 }, { 5, 7, 5 }, { 5, 5, 7 },
//		{ 5, 7, 7 }, { 7, 5, 7 }, { 7, 7, 5 },
//		{ 7, 1, 1 }, { 1, 7, 1 }, { 1, 1, 7 },
//		{ 1, 7, 7 }, { 7, 1, 7 }, { 7, 7, 1 }
//};
//
//// on "init" you need to initialize your instance
//bool Different::init()
//{
//	//////////////////////////////
//	// 1. super init first
//	if (!Layer::init())
//	{
//		return false;
//	}
//	visibleSize = Director::getInstance()->getVisibleSize();
//
//	gameLayer = Node::create();
//	addChild(gameLayer);
//
//	timerLabel = Label::create();
//	timerLabel->setTextColor(Color4B::BLUE);
//	timerLabel->setSystemFontSize(48);
//	timerLabel->setPosition(visibleSize.width / 2, visibleSize.height - 100);
//	addChild(timerLabel);
//
//	auto listener = EventListenerTouchOneByOne::create();
//	listener->onTouchBegan = [this](Touch* t, Event* e){
//
//		auto bs = Block::getBlocks();
//		Block *b;
//
//		for (auto it = bs->begin(); it != bs->end(); it++) {
//
//			b = *it;
//
//			if (b->getLineIndex() == 1 &&
//				b->getBoundingBox().containsPoint(t->getLocation())) {
//
//				if (b->getDif() == true) {
//					if (!timerRunning) {
//						startGame();
//					}
//
//					b->setColor(Color3B::GRAY);
//					this->moveDown();
//				}
//				else if (b->getColor() == Color3B::GREEN){
//					this->moveDown();
//				}
//				else{
//					MessageBox("你点错了", "点错了");
//					b->setColor(Color3B::RED);
//				}
//
//				break;
//			}
//		}
//
//		return false;
//	};
//	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
//
//	return true;
//}
//
//void Different::startGame(){
//	//init
//	linesCount = 0;
//	showEnd = false;
//	timerRunning = false;
//	timerLabel->setString("0.000000");
//
//	//try to clear
//	Block::removeAllBlocks();
//
//	addStartLine();
//	addNormalLine(1);
//	addNormalLine(2);
//	addNormalLine(3);
//	addNormalLine(4);
//}
//
//
//void Different::addStartLine(){
//	auto b = Block::createWithArgs(Color3B::YELLOW, Size(visibleSize.width, visibleSize.height / 5), "", 20, Color4B::BLACK);
//	gameLayer->addChild(b);
//	b->setLineIndex(0);
//}
//
//void Different::addNormalLine(int lineIndex){
//
//	Block *b;
//	int blackIndex = rand() % 36;
//	int difCnt = blackIndex % 3;
//
//	int line[3];
//	for (int i = 0; i < 3;++i)
//		line[i] =this->dirs_pre[blackIndex][i];
//
//	for (int i = 0; i < 3; i++) {
//
//		b = Block::createWithArgs(line[i] * 90, Size(visibleSize.width / 3 - 1, visibleSize.height / 5 - 1), "", 20, Color4B::BLACK);
//		gameLayer->addChild(b);
//
//		b->setPosition(i*visibleSize.width / 3, lineIndex*visibleSize.height / 5);
//		b->setLineIndex(lineIndex);
//
//		if (i == difCnt){
//			b->setDif(true);
//		}
//	}
//
//	linesCount++;
//}
//
//
//void Different::moveDown(){
//
//	if (linesCount < 30) {
//		addNormalLine(5);
//	}
//	else if (!showEnd){
//		//lose
//		showEnd = true;
//	}
//
//
//	auto bs = Block::getBlocks();
//
//	for (auto it = bs->begin(); it != bs->end(); it++) {
//		(*it)->moveDown();
//	}
//
//}
//
//
//void Different::update(float dt){
//
//	long offset = clock() - startTime;
//
//	timerLabel->setString(StringUtils::format("%g", ((double) offset) / 1000000));
//}
//void Different::menuCloseCallback(Ref* pSender)
//{
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
//	MessageBox("You pressed the close button. It do not implement a close button.", "Alert");
//	return;
//#endif
//
//	Director::getInstance()->end();
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//	exit(0);
//#endif
//}
//
//Vector<Block*> * Block::blocks = new Vector<Block*>();
//
//Vector<Block*> * Block::getBlocks(){
//	return Block::blocks;
//}
//
//void Block::removeAllBlocks(){
//
//	while (getBlocks()->size()) {
//		getBlocks()->back()->removeFromParent();
//		getBlocks()->popBack();
//	}
//}
//
//void Block::setDif(bool dif){
//	this->dif = dif;
//}
//
//bool Block::getDif(){
//	return this->dif;
//}
//
//Block* Block::createWithArgs(Color3B color, Size size, std::string label, float fontSize, Color4B textColor){
//
//	auto b = new Block();
//	b->initWithArgs(color, size, label, fontSize, textColor);
//	b->autorelease();
//
//	blocks->pushBack(b);
//
//	return b;
//}
//bool Block::initWithArgs(Color3B color, Size size, std::string label, float fontSize, Color4B textColor){
//
//	Sprite::init();
//
//	lineIndex = 0;
//
//	setContentSize(size);
//	setAnchorPoint(Point::ZERO);
//	setTextureRect(Rect(0, 0, size.width, size.height));
//	setColor(color);
//
//	auto l = Label::create();
//	l->setString(label);
//	l->setSystemFontSize(fontSize);
//	l->setTextColor(textColor);
//	addChild(l);
//	l->setPosition(size.width / 2, size.height / 2);
//
//	return true;
//}
//
//
//
//
//
//Block* Block::createWithArgs(int angle, Size size, std::string label, float fontSize, Color4B textColor){
//
//	auto b = new Block();
//	b->initWithArgs(angle, size, label, fontSize, textColor);
//	b->autorelease();
//
//	blocks->pushBack(b);
//
//	return b;
//}
//bool Block::initWithArgs(int angle, Size size, std::string label, float fontSize, Color4B textColor){
//
//	Sprite::init();
//
//	lineIndex = 0;
//
//	setContentSize(size);
//	setAnchorPoint(Point::ZERO);
//	setTextureRect(Rect(0, 0, size.width, size.height));
//	//设置角度
//	setRotation(angle);;
//
//	auto l = Label::create();
//	l->setString(label);
//	l->setSystemFontSize(fontSize);
//	l->setTextColor(textColor);
//	addChild(l);
//	l->setPosition(size.width / 2, size.height / 2);
//
//	return true;
//}
//
//
//
//
//void Block::removeBlock(){
//	//    auto c = getColor();
//	//    log("Remove block,color is (%d,%d,%d)",c.r,c.g,c.b);
//
//	removeFromParent();
//	blocks->eraseObject(this);
//}
//
//
//void Block::setLineIndex(int v){
//	this->lineIndex = v;
//}
//
//
//int Block::getLineIndex(){
//	return this->lineIndex;
//}
//
//void Block::moveDown(){
//
//	this->lineIndex--;
//
//	Size visibleSize = Director::getInstance()->getVisibleSize();
//
//	if (getNumberOfRunningActions() != 0) {
//		stopAllActions();
//	}
//
//	runAction(Sequence::create(MoveTo::create(0.1f, Point(getPositionX(), lineIndex*visibleSize.height / 5)),
//		CallFunc::create([this](){
//
//		if (lineIndex < 0) {
//			this->removeBlock();
//		}
//
//	}), NULL));
//
//}
