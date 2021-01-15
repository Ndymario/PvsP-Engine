#pragma once
#include <raylib.h>

struct Screen
{

	// Private members:
private:
	static float screenScale;
	static int lastWidth;

	// Public members.
public:
	// Constants.
	const static int GAME_WIDTH = 2880;
	const static int GAME_HEIGHT = 1800;
	const static int DEFAULT_WIDTH = 1435;
	const static int DEFAULT_HEIGHT = 900;

	// Helper functions.
	static void Init();
	static float GetScreenScale();
	static void ResizeWindow(float scale);
	static void ResizeWindow(int width);
	static void DoToggleFullscreen();
	static Vector2 ScaleVector2(Vector2 *vector);
	static Rectangle ScaleRectangle(Rectangle *rect);
};
