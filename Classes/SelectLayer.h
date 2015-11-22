#ifndef __SELECT_LAYER_H__
#define __SELECT_LAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

class SelectLayer : public Layer
{
public:
	CREATE_FUNC(SelectLayer)
		bool init();

private:
	void clickButton(Ref *ref);
};

#endif // __SELECT_LAYER_H__
