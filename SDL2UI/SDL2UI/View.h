#pragma once
#ifndef GAME_TEST_VIEW_H
#define GAME_TEST_VIEW_H
#include "Draw.h"
#include "ViewParent.h"
#include<iostream>

class View
{
public:
	View();
	View(int x, int y, int width, int height);
	View(string name, int x, int y, int width, int height);
	~View();

	void setID(int id);
	void setName(string name);
	void setInitX(int initx);
	void setInitY(int inity);
	void setWidth(int width);
	void setHeight(int height);
	void setDeep(int deep);
	void setBackground(int r, int g, int b, int a);
	void setViewParent(ViewParent *viewParent);

	int getID();
	string getName();
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	int getDeep();
	int *getBackground();
	ViewParent *getViewParent();
	View *getView();

	bool isOverlap(int tx,int ty);

	virtual void onDraw(Draw *canvas);
	virtual bool onTouchEvent(int action, int button, int x, int y);


private:
	int id;
	string name;
	int x;
	int y;
	int width;
	int height;
	int deep;
	int *background;

	ViewParent *viewParent;

public:
	const static int EVENT_ACTION_DOWN = 1;
	const static int EVENT_ACTION_UP = 2;
	const static int EVENT_ACTION_MOVE = 3;

};

#endif