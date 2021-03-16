#include "scene.h"

Scene *Scene::currentScene;
map<string, Scene *> Scene::loadedScenes;

// BG Position.
Vector2 Scene::BGPos = { 0, 0 };

void Scene::ChangeScene(string name)
{
	if (currentScene != nullptr)
	{
		currentScene->Cleanup();
	}
	currentScene = loadedScenes[name];
	currentScene->Initialize();
}

void Scene::DoDrawBackground2D()
{
	if (currentScene == nullptr)
		return;
	currentScene->DrawBackground2D();
}

void Scene::DoDrawForeground2D()
{
	if (currentScene == nullptr)
		return;
	currentScene->DrawForeground2D();
}

void Scene::DoDraw3D()
{
	if (currentScene == nullptr)
		return;
	currentScene->Draw3D();
}

void Scene::DoDrawImGui()
{
	if (currentScene == nullptr)
		return;
	currentScene->DrawImGui();
}

void Scene::DoUpdate()
{
	if (currentScene == nullptr)
		return;
	currentScene->Update();
}

void Scene::LoadScene(string name, Scene *scene)
{
	loadedScenes[name] = scene;
}

Scene* Scene::CurrentScene()
{
	return currentScene;
}

Camera& Scene::GetCamera()
{
	return currentScene->camera;
}