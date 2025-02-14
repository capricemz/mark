#pragma execution_character_set("utf-8")

#ifndef __UI_MAIN_BATTLE_LAYER_BATTLE_H__
#define __UI_MAIN_BATTLE_LAYER_BATTLE_H__

#include "cocos2d.h"
#include "common/basic/Observer.h"
#include "game/ui/ILayerAppearDisappear.h"
#include "HandleUIEntity.h"
#include "HandleBg.h"
#include "HandleGrid.h"
#include "HandleHead.h"
#include "LayerGridSelect.h"
/*#include "gridShow/LayerGridShow.h"*/

USING_NS_CC;
using namespace std;

class LayerBattle : public Layer, public Observer, public ILayerAppearDisappear
{
public:
	CREATE_FUNC(LayerBattle);

public:
	LayerBattle();
	~LayerBattle();

	virtual bool init();

	virtual void updateBySubject(va_list values);
	
	virtual Layer *getThis();
	virtual void afterRunAppear();
	virtual void afterRunDisAppear();
	virtual void dealRemoveFromParent();
	/*显示怪物选中格子出现动画*/
	void showAppearGridSelectedMst();
	/*显示女仆选择格子出现动画*/
	void showAppearGridSelectMaid();
	/*type 0女仆，1怪物
	index 第几个*/
	Vec2 getPostionHeadIcon(const int &type, const int &index);

private:
	void createData();
	void createSkin();
	void resetSkin();
	
private:
	Layer *_skin;
	HandleUIEntity *_handleEntity;
	HandleBg *_handleBg;
	HandleHead *_handleHead;
	HandleGrid *_handleGrid;

	LayerGridSelect *_layerGridSelect;
	/*LayerGridShow *_layerGridShow;*/
	
};

#endif