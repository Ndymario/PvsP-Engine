#pragma once
struct Screen
{
	
	// Private members:
	private:
		static float screenScale;
		static int lastWidth;

	// Public members.
	public:

		// Constants.
		const static int GAME_WIDTH = 1920;
		const static int GAME_HEIGHT = 1080;
		const static int DEFAULT_WIDTH = 1024;
		const static int DEFAULT_HEIGHT = 576;

		// Helper functions.
		static void Init();
		static float GetScreenScale();
		static void ResizeWindow(float scale);
		static void ResizeWindow(int width);
		static void DoToggleFullscreen();

};

