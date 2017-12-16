#include "stdafx.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

#include "Draw.h"

#include "View.h"
#include "ViewGroup.h"

using namespace std;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 768;

Draw *draw = nullptr;

ViewGroup *viewgroup = nullptr;

int main(int argc, char * argv[]) {

	draw = new Draw();

	viewgroup = new ViewGroup(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	viewgroup->setBackground(255, 255, 255, 255);
	viewgroup->setEX(SCREEN_WIDTH);
	viewgroup->setEY(SCREEN_HEIGHT);

	//Top
	ViewGroup *toolbar = new ViewGroup("toolbar", 0, 0, SCREEN_WIDTH, 50);
	toolbar->setBackground(255, 125, 125, 255);

	View *nav = new View("nav",0,0,50,50);
	nav->setBackground(125,255,125,255);

	toolbar->addView(nav);

	ViewGroup *menu = new ViewGroup("menu", SCREEN_WIDTH - 100, 0, 100, 50);
	menu->setBackground(125, 255, 125, 255);

	View *menua = new View(0,0,50,50);
	menua->setBackground(255,255,255,255);

	menu->addView(menua);

	toolbar->addView(menu);

	viewgroup->addView(toolbar);
	//Content
	ViewGroup *content = new ViewGroup("Content", 0, 50, SCREEN_WIDTH, SCREEN_HEIGHT - 50);
	content->setBackground(125, 125, 255, 255);

	viewgroup->addView(content);

	draw->showLOG(false);
	draw->Init("Test", SCREEN_WIDTH, SCREEN_HEIGHT, 200);
	return 0;
}

void Draw::onDraw(SDL_Window *window, SDL_Renderer *renderer) {
	viewgroup->onDraw(draw);
}

void Draw::onKeyDown(int key) {

}

void Draw::onMouseMove(int x, int y) {
	viewgroup->onTouchEvent(View::EVENT_ACTION_MOVE, 0, x, y);
}

void Draw::onMouseDown(int x, int y, int button) {
	viewgroup->onTouchEvent(View::EVENT_ACTION_DOWN, 0, x, y);
}

void Draw::onMouseUP(int x, int y, int button) {
	viewgroup->onTouchEvent(View::EVENT_ACTION_UP, 0, x, y);
}