#pragma once
#include "ViewGroup.h"
class LinearLayout :
	public ViewGroup
{
public:
	LinearLayout() :ViewGroup() {

	}
	LinearLayout(int width, int height) :ViewGroup(width, height) {

	}
	LinearLayout(int x, int y, int width, int height) :ViewGroup(x, y, width, height) {

	}
	LinearLayout(string name, int x, int y, int width, int height) :ViewGroup(name, x, y, width, height) {

	}
	~LinearLayout();
};

