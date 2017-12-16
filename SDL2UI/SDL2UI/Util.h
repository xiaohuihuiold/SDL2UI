//
// Created by xhh on 17-9-17.
//
#pragma once
#ifndef GAME_TEST_UTIL_H
#define GAME_TEST_UTIL_H

#include <time.h>
#include <sstream>
#include <string>
#include <stdio.h>

using namespace std;

const int ORIGIN_LOAD_TOP_LEFT = 1;
const int ORIGIN_LOAD_TOP_CENTER = 2;
const int ORIGIN_LOAD_TOP_RIGHT = 3;
const int ORIGIN_LOAD_CENTER_LEFT = 4;
const int ORIGIN_LOAD_CENTER = 5;
const int ORIGIN_LOAD_CENTER_RIGHT = 6;
const int ORIGIN_LOAD_BOTTOM_LEFT = 7;
const int ORIGIN_LOAD_BOTTOM_CENTER = 8;
const int ORIGIN_LOAD_BOTTOM_RIGHT = 9;

class Util {
public:
	static string addStr(string text, int num);

	long getCurrentTime();

	static int *getSEXY(int sx, int sy, int ex, int ey, long atime, long time);

	static double getLong(int sx, int sy, int ex, int ey);
};

#endif //GAME_TEST_UTIL_H
