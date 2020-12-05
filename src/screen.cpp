#include "screen.h"
#include <raylib.h>
#include <stdio.h>

float Screen::screenScale;
int Screen::lastWidth;

void Screen::Init()
{
	screenScale = DEFAULT_WIDTH / (float)GAME_WIDTH;
	ResizeWindow(DEFAULT_WIDTH);
	SetWindowPosition(100, 100);
}

float Screen::GetScreenScale()
{
	return screenScale;
}

void Screen::ResizeWindow(float scale)
{
	screenScale = scale;
	int width = (int)(GAME_WIDTH * scale);
	int height = (int)(GAME_HEIGHT * scale);
	SetWindowSize(width, height);
}

void Screen::ResizeWindow(int width)
{
	screenScale = (float)width / GAME_WIDTH;
	int height = (int)(GAME_HEIGHT * screenScale);
	SetWindowSize(width, height);
}

void Screen::DoToggleFullscreen()
{
	if (IsWindowFullscreen())
	{
		ToggleFullscreen();
		ResizeWindow(lastWidth);
	}
	else
	{
		lastWidth = GetScreenWidth();
		ResizeWindow(GetMonitorWidth(0));
		ToggleFullscreen();
	}
}

Vector2 Screen::ScaleVector2(Vector2* vector)
{
	return { vector->x * screenScale, vector->y * screenScale };
}

Rectangle Screen::ScaleRectangle(Rectangle* rect)
{
	return { rect->x * screenScale, rect->y * screenScale, rect->width * screenScale, rect->height * screenScale };
}