#pragma once
#ifndef GAME_TEST_VIEW_H
#define GAME_TEST_VIEW_H
#include "Draw.h"

class View
{
public:
	View();
	View(int x,int y,int width,int height);
	View(string name, int x, int y, int width, int height);
	~View();

	void setID(int id);
	void setName(string name);
	void setX(int x);
	void setY(int y);
	void setEX(int ex);
	void setEY(int ey);
	void setInitX(int initx);
	void setInitY(int inity);
	void setWidth(int width);
	void setHeight(int height);
	void setDeep(int deep);
	void setBackground(int r, int g, int b, int a);
	void setViewParent(View *viewParent);


	int getID();
	string getName();
	int getX();
	int getY();
	int getInitX();
	int getInitY();
	int getWidth();
	int getHeight();
	int getDeep();
	int *getBackground();
	View *getViewParent();
	View *getView();

	virtual void onDraw(Draw *canvas);
	virtual bool onTouchEvent(int action,int button,int x,int y);


private:
	int id;
	string name;
	int x;
	int y;
	int ex;
	int ey;
	int initx;
	int inity;
	int width;
	int height;
	int deep;
	int *background;

	View *viewParent;

public:
	const static int EVENT_ACTION_DOWN = 1;
	const static int EVENT_ACTION_UP = 2;
	const static int EVENT_ACTION_MOVE = 3;

};

#endif