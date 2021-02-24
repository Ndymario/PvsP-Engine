// Include any headers we need
#include "scene.h"
#include <raylib.h>

// Define a struct for our pvp scene

struct PvP_Menu : public Scene{
    // Useful scene functions
    void Initialize();
	void DrawBackground2D();
	void DrawForeground2D();
	void Draw3D();
	void Update();
	void Cleanup();
};