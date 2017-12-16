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
	int cx = x + initx;
	int cy = y + inity;

	canvas->setRect(
		(x < 0 ? initx : cx),
		(y < 0 ? inity : cy),
		(cx + width > ex ? ex - cx : width),
		(cy + height > ey ? ey - cy : height));

	if (background != nullptr) {
		canvas->drawRect(cx, cy, width, height, true, background[0], background[1], background[2], background[3]);
	}
	if (name != "") {
		canvas->drawText(name, cx + width / 2, cy + height / 2, 16, true, 1, 255, 255, 255, 255);
	}
}

void View::setID(int id) {
	this->id = id;
}

void View::setName(string name) {
	this->name = name;
}

void View::setX(int x) {
	this->x = x;
}

void View::setY(int y) {
	this->y = y;
}

void View::setEX(int ex) {
	this->ex = ex;
}

void View::setEY(int ey) {
	this->ey = ey;
}

void View::setInitX(int initx) {
	this->initx = initx;
}

void View::setInitY(int inity) {
	this->inity = inity;
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

void View::setViewParent(View *viewParent) {
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

int View::getInitX() {
	return this->initx;
}

int View::getInitY() {
	return this->inity;
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

View *View::getViewParent() {
	return this->viewParent;
}

View *View::getView() {
	return this;
}

bool View::onTouchEvent(int action, int button, int x, int y) {
	return false;
}