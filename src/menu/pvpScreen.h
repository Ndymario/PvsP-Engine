// Include any headers we need.
#include "scene.h"
#include "ui.h"

// Define a struct for our pvp scene.
struct PvsPScreen : public Scene {

    // Define any UI elements.
	Shape BG;
	Shape Logo;
	Shape localButton;
	Shape onlineButton;
	Shape trainingButton;
	Shape backButton;
	
	// Useful scene functions.
    void Initialize();
	void DrawBackground2D();
	void DrawForeground2D();
	void Draw3D();
	void Update();
	void Cleanup();

};

// Button functions.
void ClickLocalButton();
void ClickOnlineButton();
void ClickTrainingButton();