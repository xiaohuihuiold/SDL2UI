#pragma once
#ifndef GAME_TEST_VIEWPARENT_H
#define  GAME_TEST_VIEWPARENT_H

class ViewParent
{
public:
	ViewParent();
	~ViewParent();

public:
	int left;
	int top;
	int right;
	int bottom;
	int width;
	int htight;

};

#endif