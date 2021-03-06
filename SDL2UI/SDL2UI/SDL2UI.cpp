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

	viewgroup = new ViewGroup("root", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	viewgroup->setBackground(255, 255, 255, 255);
	ViewParent *viewParent = new ViewParent();
	viewParent->left = 0;
	viewParent->top = 0;
	viewParent->right = viewgroup->getWidth();
	viewParent->bottom = viewgroup->getHeight();
	viewParent->width = viewgroup->getWidth();
	viewParent->htight = viewgroup->getHeight();
	viewgroup->setViewParent(viewParent);

	for (int i = 0; i < SCREEN_HEIGHT;i+=60) {
		for (int j = 0; j < SCREEN_WIDTH; j += 60) {
			View *view = new View( 50, 50);
			view->setBackground(125, 125, 255, 255);
			viewgroup->addView(view);
		}
	}

	draw->showLOG(true);
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