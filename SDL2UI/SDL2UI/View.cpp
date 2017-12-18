#include "stdafx.h"
#include "View.h"

View::View()
{
}

View::View(int x, int y, int width, int height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

View::View(string name, int x, int y, int width, int height) {
	this->name = name;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

View::~View()
{
}

void View::onDraw(Draw *canvas) {
	int cx = x + viewParent->left;
	int cy = y + viewParent->top;
	canvas->setRect(
		(x < 0 ? viewParent->left : cx),
		(y < 0 ? viewParent->top : cy),
		(cx + width > viewParent->right ? viewParent->right - cx : width),
		(cy + height > viewParent->bottom ? viewParent->bottom - cy : height));

	if (background != nullptr) {
		canvas->drawRect(cx, cy, width, height, true, background[0], background[1], background[2], background[3]);
	}
	canvas->drawText(Util::addStr("Deep:", deep), cx + width / 2, cy + height / 2, 16, true, 1, 255, 255, 255, 255);
}

void View::setID(int id) {
	this->id = id;
}

void View::setName(string name) {
	this->name = name;
}

void View::setWidth(int width) {
	this->width = width;
}

void View::setHeight(int height) {
	this->height = height;
}

void View::setDeep(int deep) {
	this->deep = deep;
}

void View::setBackground(int r, int g, int b, int a) {
	background = new int[4];
	background[0] = r;
	background[1] = g;
	background[2] = b;
	background[3] = a;
}

void View::setViewParent(ViewParent *viewParent) {
	this->viewParent = viewParent;
}

int View::getID() {
	return this->id;
}

string View::getName() {
	return this->name;
}

int View::getX() {
	return this->x;
}

int View::getY() {
	return this->y;
}

int View::getWidth() {
	return this->width;
}

int View::getHeight() {
	return this->height;
}

int View::getDeep() {
	return this->deep;
}

int *View::getBackground() {
	return this->background;
}

ViewParent *View::getViewParent() {
	return this->viewParent;
}

View *View::getView() {
	return this;
}

bool View::isOverlap(int tx, int ty) {
	bool isOver = (tx > viewParent->left + this->getX() &&
		tx<viewParent->left + this->getX() + this->getWidth() &&
		ty>viewParent->top + this->getY() &&
		ty < viewParent->top + this->getY() + this->getHeight());
	return isOver;
}

bool View::onTouchEvent(int action, int button, int tx, int ty) {
	if (isOverlap(tx, ty)) {
		if (action == View::EVENT_ACTION_DOWN) {
			this->setBackground(125, 125, 125, 255);
		}
		return true;
	}
	return false;
}