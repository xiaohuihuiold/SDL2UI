//
// Created by xhh on 17-9-17.
//
#pragma once
#ifndef GAME_TEST_DRAW_H
#define GAME_TEST_DRAW_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

#include "Util.h"

using namespace std;

static int fps;
static int fpsTemp;
static int timee;

class Draw {
public:
	void Init(string title, int width, int height, int fps);

	static Uint32 ReFps(Uint32 interval, void *param);

	virtual void onDraw(SDL_Window *window, SDL_Renderer *renderer);

	virtual void onKeyDown(int key);

	virtual void onMouseMove(int x, int y);

	virtual void onMouseDown(int x, int y, int button);

	virtual void onMouseUP(int x, int y, int button);

	void drawText(string text, int x, int y, int size, bool back, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	void drawText(string text, int x, int y, int size, bool back, int align, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	void drawImage(SDL_Texture *texture, int x, int y);

	void drawImage(SDL_Surface *surface, SDL_Texture *texture, int x, int y, double w, double h, int alpha,
		double angle, int origin);

	void drawPoint(int x, int y, int r, int g, int b, int a);

	void drawLine(int sx, int sy, int ex, int ey, int r, int g, int b, int a);

	void drawRect(int left, int top, int right, int bottom, bool fill, int r, int g, int b, int a);

	void drawCircle(int x, int y, int ra, bool fill, int r, int g, int b, int a);

	void drawLOG(int size);

	void setRect(int x, int y, int w, int h);

	void renderSurface(int x, int y, SDL_Texture *texture);

	void
		renderSurface(int x, int y, double w, double h, double angle, int alpha, int origin, SDL_Surface *surface,
			SDL_Texture *texture);

	SDL_Texture *loadImage(string path);

	SDL_Surface *loadImageSurface(string path);

	SDL_Renderer *getRenderer();

	int getFPS();

	int getTime();

	int getDTime();

	long getCurrTime();

	void showLOG(bool show);

private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;
	Util *util;

	int screenWidth;
	int screenHeight;
	long stimee;
	long etimee;
	long currSTime;
	long currTime;
	int dtimee;
	int mouseX;
	int mouseY;

	bool quit;
	bool isShowLOG;

	TTF_Font *font = nullptr;

	string ft = "Roboto-Bold.ttf";
};

#endif //GAME_TEST_DRAW_H
