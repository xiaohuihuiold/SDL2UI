#include "stdafx.h"
#include "ViewGroup.h"

ViewGroup::~ViewGroup()
{
}

void ViewGroup::onDraw(Draw *canvas) {
	View::onDraw(canvas); 
	if (vp == nullptr) {
		vp = new ViewParent();
	}
	vp->left = getViewParent()->left + this->getX();
	vp->top = getViewParent()->top + this->getY();
	vp->right = vp->left + this->getWidth();
	vp->bottom = vp->top + this->getHeight();
	vp->width = this->getWidth();
	vp->htight = this->getHeight();
	for (int i = 0; i < getViewsSize(); i++) {

		views[i]->setDeep(this->getChildDeep());
		views[i]->setViewParent(vp);
		views[i]->onDraw(canvas);
	}

}

int ViewGroup::addView(View *view) {
	
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
	if (this->isOverlap(tx, ty)) {
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
			if(this->getDeep()!=0)this->setBackground(125, 125, 125, 255);
		}
		return true;
	}
	return false;
}