#pragma once
#ifndef GAME_TEST_VIEWGROUP_H
#define GAME_TEST_VIEWGROUP_H

#include <vector>
#include "View.h"

class ViewGroup : public View
{
public:
	ViewGroup() :View() {
	
	}
	ViewGroup(int width, int height) :View(width, height) {

	}
	ViewGroup(int x, int y, int width, int height) :View(x, y, width, height) {

	}
	ViewGroup(string name, int x, int y, int width, int height) :View(name, x, y, width, height) {

	}

	~ViewGroup();

	virtual void onDraw(Draw *canvas);
	virtual bool onTouchEvent(int action, int button, int x, int y);

	virtual int addView(View *view);
	virtual int getViewsSize();
	virtual int getChildDeep();
private:
	vector<View*> views;

	ViewParent *vp;
};

#endif