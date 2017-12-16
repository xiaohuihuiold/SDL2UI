#include "stdafx.h"
#include "ViewGroup.h"


ViewGroup::ViewGroup()
{
}

ViewGroup::~ViewGroup()
{
}

void ViewGroup::onDraw(Draw *canvas) {
	View::onDraw(canvas);
	for (int i = 0; i < getViewsSize(); i++) {

		views[i]->setDeep(this->getChildDeep());
		views[i]->setInitX(this->getX() + this->getInitX());
		views[i]->setInitY(this->getY() + this->getInitY());

		views[i]->setEX(this->getInitX() + this->getX() + this->getWidth());
		views[i]->setEY(this->getInitY() + this->getY() + this->getHeight());

		views[i]->onDraw(canvas);
	}

}

int ViewGroup::addView(View *view) {
	view->setViewParent(this->getView());
	views.push_back(view);
	return views.size() - 1;
}

int ViewGroup::getViewsSize() {
	return views.size();
}

int ViewGroup::getChildDeep() {
	return this->getDeep() + 1;
}

bool ViewGroup::onTouchEvent(int action, int button, int tx, int ty) {
	bool isTouch = false;
	if (tx > this->getInitX() + this->getX() &&
		tx<this->getInitX() + this->getX() + this->getWidth() &&
		ty>this->getInitY() + this->getY() &&
		ty < this->getInitY() + this->getY() + this->getHeight()) {
		for (int i = views.size() - 1; i >= 0; i--) {
			isTouch = views[i]->onTouchEvent(action, button, tx, ty);
			if (isTouch) {
				break;
			}
		}
		if (isTouch) {
			return true;
		}
		if (action == View::EVENT_ACTION_DOWN) {
			std::cout << this->getName() << "xa:" << this->getInitX() + this->getX() << std::endl;
			std::cout << "ex:" << this->getInitX() + this->getX() + this->getWidth() << std::endl;
			this->setBackground(125, 125, 125, 255);
		}
		return true;
	}
	return false;
}