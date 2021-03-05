// Include any headers we need
#include "scene.h"
#include "ui.h"

// Define a struct for our pvp scene

struct PvsP_Menu : public Scene{
    // Define any UI elements
	Shape localButton;
	Shape onlineButton;
	Shape trainingButton;
	
	// Useful scene functions
    void Initialize();
	void DrawBackground2D();
	void DrawForeground2D();
	void Draw3D();
	void Update();
	void Cleanup();
};