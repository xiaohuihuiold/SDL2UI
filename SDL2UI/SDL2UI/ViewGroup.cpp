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

		views[i]->setInitX(this->getX() + this->getInitX());
		views[i]->setInitY(this->getY() + this->getInitY());

		views[i]->setEX(this->getInitX() + this->getX() + this->getWidth());
		views[i]->setEY(this->getInitY() + this->getY() + this->getHeight());

		views[i]->onDraw(canvas);
	}

}

int ViewGroup::addView(View *view) {
	view->setDeep(this->getDeep() + 1);
	view->setViewParent(this->getView());
	views.push_back(view);
	return views.size() - 1;
}

int ViewGroup::getViewsSize() {
	return views.size();
}

bool ViewGroup::onTouchEvent(int action, int button, int x, int y) {
	for (int i = 0; i < views.size(); i++) {
		views[i]->onTouchEvent(action, button, x, y);
	}
	return false;
}