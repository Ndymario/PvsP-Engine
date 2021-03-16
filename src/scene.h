#pragma once

#include <map>
#include <string>
#include <raylib.h>

using namespace std;

struct Scene
{

	// Private data.
private:
	static Scene* currentScene;
	static map<string, Scene*> loadedScenes;

	// Public members.
public:
	static Vector2 BGPos;
	Camera3D camera;

	// To be implemented.
	virtual void Initialize() {}
	virtual void DrawBackground2D() {}
	virtual void DrawForeground2D() {}
	virtual void Draw3D() {}
	virtual void DrawImGui() {}
	virtual void Update() {}
	virtual void Cleanup() {}

	// To execute.
	static void ChangeScene(string name);
	static void DoDrawBackground2D();
	static void DoDrawForeground2D();
	static void DoDraw3D();
	static void DoDrawImGui();
	static void DoUpdate();
	static void LoadScene(string name, Scene *scene);
	static Scene* CurrentScene();
	static Camera &GetCamera();
};
