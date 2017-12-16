#include "stdafx.h"
#include "Draw.h"

unsigned int power_two_floor(unsigned int val) {
	unsigned int power = 2, nextVal = power * 2;

	while ((nextVal *= 2) <= val)
		power *= 2;

	return power * 2;
}

void Draw::Init(string title, int width, int height, int fps) {
	screenWidth = width;
	screenHeight = height;
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	SDL_TimerID timer = SDL_AddTimer(1000, Draw::ReFps, NULL);
	title = Util::addStr(title + " (", width);
	title = Util::addStr(title + "x", height) + ")";
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
		SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	currSTime = util->getCurrentTime();

	while (!quit) {
		dtimee = 1000 / fps;
		stimee = util->getCurrentTime();
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
			if (event.type == SDL_KEYDOWN) {
				onKeyDown(event.key.keysym.sym);
			}
			if (event.type == SDL_MOUSEMOTION) {
				mouseX = event.motion.x;
				mouseY = event.motion.y;
				onMouseMove(event.motion.x, event.motion.y);
			}
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				onMouseDown(event.motion.x, event.motion.y, event.button.button);
			}
			if (event.type == SDL_MOUSEBUTTONUP) {
				onMouseUP(event.motion.x, event.motion.y, event.button.button);
			}
		}
		SDL_RenderClear(renderer);
		onDraw(window, renderer);

		if (isShowLOG) {
			setRect(0, 0, width, height);
			drawLOG(16);
		}
		SDL_RenderPresent(renderer);
		SDL_GL_SwapWindow(window);
		fpsTemp++;
		etimee = util->getCurrentTime();
		while (1000 / ((etimee - stimee) + dtimee) < fps) {
			dtimee--;
			if (dtimee <= 0) {
				dtimee = 1;
				break;
			}
		}
		SDL_Delay(dtimee);
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Draw::drawText(string text, int x, int y, int size, bool back, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
	SDL_Color color = { r, g, b, a };
	if (font == nullptr)font = TTF_OpenFont(ft.c_str(), size);
	SDL_Surface *surface = TTF_RenderText_Blended(font, text.c_str(), color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

	int w = surface->w;
	int h = surface->h;

	if (back) {
		drawRect(x, y, w, h, true, 0, 0, 0, 125);
	}
	renderSurface(x, y, texture);

	//TTF_CloseFont(font);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void Draw::drawText(string text, int x, int y, int size, bool back, int align, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
	SDL_Color color = { r, g, b, a };
	if (font == nullptr)font = TTF_OpenFont(ft.c_str(), size);
	SDL_Surface *surface = TTF_RenderText_Blended(font, text.c_str(), color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

	int w = surface->w;
	int h = surface->h;

	switch (align) {
	case 1:
		x = x - w / 2;
		y = y - h / 2;
		break;
	}

	if (back) {
		drawRect(x, y, w, h, true, 0, 0, 0, 125);
	}
	renderSurface(x, y, texture);

	//TTF_CloseFont(font);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void Draw::drawImage(SDL_Texture *texture, int x, int y) {
	renderSurface(x, y, texture);
}

void
Draw::drawImage(SDL_Surface *surface, SDL_Texture *texture, int x, int y, double w, double h, int alpha, double angle,
	int origin) {
	renderSurface(x, y, w, h, angle, alpha, origin, surface, texture);
}

void Draw::drawPoint(int x, int y, int r, int g, int b, int a) {
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderDrawPoint(renderer, x, y);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}

void Draw::drawLine(int sx, int sy, int ex, int ey, int r, int g, int b, int a) {
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderDrawLine(renderer, sx, sy, ex, ey);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}

void Draw::drawRect(int left, int top, int right, int bottom, bool fill, int r, int g, int b, int a) {
	SDL_Rect rect = { left, top, right, bottom };

	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	if (fill) {
		SDL_RenderFillRect(renderer, &rect);
	}
	else {
		SDL_RenderDrawRect(renderer, &rect);
	}
}

void Draw::drawCircle(int x, int y, int ra, bool fill, int r, int g, int b, int a) {
	if (fill) {
		/*double longs;
		for (int i = x; i <= x + 2 * ra; i++) {
		for (int j = y; j <= y + 2 * ra; j++) {
		longs = util->getLong(x + ra, y + ra, i, j);
		if (longs <= ra - 3) {
		drawPoint(i - ra, j - ra, r, g, b, a);
		}
		}
		}*/
		double longs;
		for (int j = y; j <= y + 2 * ra; j++) {
			int xy[4];
			bool s = false;
			bool c = false;
			for (int i = x; i <= x + 2 * ra; i++) {
				longs = util->getLong(x + ra, y + ra, i, j);
				if (longs <= ra) {
					if (!s) {
						xy[0] = i - ra;
						xy[1] = j - ra;
						s = true;
					}
					else {
						xy[2] = i - ra;
						xy[3] = j - ra;
						c = true;
					}
				}
			}
			if (s&&c)drawLine(xy[0], xy[1], xy[2], xy[3], r, g, b, a);
		}
	}
	else {
		int dx, dy;
		int dxa, dya;
		for (int i = -1; i <= 360; i++) {
			dx = sin(3.1415926 / 180.0 * i) * ra + x + ra;
			dy = cos(3.1415926 / 180.0 * i) * ra + y + ra;
			if (i != -1)drawLine(dx, dy, dxa, dya, r, g, b, a);
			dxa = dx;
			dya = dy;
		}
	}
}

void Draw::drawLOG(int size) {
	drawText(Util::addStr("FPS:", getFPS()), 0, 0, size, true, 125, 255, 125, 0);
	drawText(Util::addStr("TIME:", getCurrTime()), 0, size, size, true, 125, 255, 125, 0);
	drawText(Util::addStr("X:", mouseX), 0, size * 2, size, true, 125, 255, 125, 0);
	drawText(Util::addStr("Y:", mouseY), 0, size * 3, size, true, 125, 255, 125, 0);

}

void Draw::setRect(int x, int y, int w, int h) {
	SDL_Rect rec;
	rec.x = x;
	rec.y = y;
	rec.w = w;
	rec.h = h;
	SDL_RenderSetClipRect(renderer, &rec);
}

void Draw::renderSurface(int x, int y, SDL_Texture *texture) {
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;

	SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(renderer, texture, NULL, &pos);
}

void Draw::renderSurface(int x, int y, double w, double h, double angle, int alpha, int origin, SDL_Surface *surface,
	SDL_Texture *texture) {
	int xa = (int)((surface->w / 2) * w);
	int ya = (int)((surface->h / 2) * h);

	int wa = (int)(surface->w * w);
	int ha = (int)(surface->h * h);

	switch (origin) {
	case ORIGIN_LOAD_TOP_LEFT:
		xa = 0;
		ya = 0;
		break;
	case ORIGIN_LOAD_TOP_CENTER:
		ya = 0;
		break;
	case ORIGIN_LOAD_TOP_RIGHT:
		xa = xa * 2;
		ya = 0;
		break;
	case ORIGIN_LOAD_CENTER_LEFT:
		xa = 0;
		break;
	case ORIGIN_LOAD_CENTER:
		break;
	case ORIGIN_LOAD_CENTER_RIGHT:
		xa = xa * 2;
		break;
	case ORIGIN_LOAD_BOTTOM_LEFT:
		xa = 0;
		ya = ya * 2;
		break;
	case ORIGIN_LOAD_BOTTOM_CENTER:
		ya = ya * 2;
		break;
	case ORIGIN_LOAD_BOTTOM_RIGHT:
		xa = xa * 2;
		ya = ya * 2;
		break;
	}

	SDL_Rect pos = { x - xa, y - ya, wa, ha };
	SDL_Point point = { xa, ya };

	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(texture, alpha);

	SDL_RenderCopyEx(renderer, texture, NULL, &pos, angle, &point, SDL_FLIP_NONE);
}

SDL_Texture *Draw::loadImage(string path) {
	SDL_Texture *texture = nullptr;
	texture = IMG_LoadTexture(renderer, path.c_str());
	return texture;
}

SDL_Surface *Draw::loadImageSurface(string path) {
	SDL_Surface *surface = nullptr;
	surface = IMG_Load(path.c_str());
	return surface;
}

Uint32 Draw::ReFps(Uint32 interval, void *param) {
	fps = fpsTemp;
	fpsTemp = 0;
	timee++;
	return interval;
}

SDL_Renderer *Draw::getRenderer() {
	return renderer;
}

int Draw::getFPS() {
	return fps;
}

int Draw::getTime() {
	return timee;
}

int Draw::getDTime() {
	return dtimee;
}

long Draw::getCurrTime() {
	currTime = util->getCurrentTime() - currSTime;
	return currTime;
}

void Draw::showLOG(bool show) {
	isShowLOG = show;
};

