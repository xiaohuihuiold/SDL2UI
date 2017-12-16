#include "stdafx.h"
#include "Util.h"

string operator+(string text, int num) {
	stringstream str;
	str << text << num;
	return str.str();
}

string Util::addStr(string text, int num) {
	stringstream str;
	str << text << num;
	return str.str();
}

long Util::getCurrentTime() {
	return clock();
}


int *Util::getSEXY(int sx, int sy, int ex, int ey, long atime, long stime) {
	int *xy;
	xy = new int[2];

	xy[0] = ex;
	xy[1] = ey;

	double process = (double)stime / (double)atime;

	if (process < 1) {

		if (sx > ex) {
			xy[0] = sx - process * (sx - ex);
		}
		else if (sx < ex) {
			xy[0] = sx + process * (ex - sx);
		}

		if (sy > ey) {
			xy[1] = sy - process * (sy - ey);
		}
		else if (sy < ey) {
			xy[1] = sy + process * (ey - sy);
		}

	}
	return xy;
}

double Util::getLong(int sx, int sy, int ex, int ey) {
	return sqrt(pow(abs(sx - ex), 2) + pow(abs(sy - ey), 2));
}

