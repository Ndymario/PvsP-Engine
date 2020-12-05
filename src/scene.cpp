#include "scene.h"

Scene* Scene::currentScene;

void Scene::ChangeScene(Scene* newScene)
{
	if (currentScene != nullptr)
	{
		currentScene->Cleanup();
	}
	currentScene = newScene;
	currentScene->Initialize();
}

void Scene::DoDrawBackground2D()
{
	if (currentScene == nullptr) return;
	currentScene->DrawBackground2D();
}

void Scene::DoDrawForeground2D()
{
	if (currentScene == nullptr) return;
	currentScene->DrawForeground2D();
}

void Scene::DoDraw3D()
{
	if (currentScene == nullptr) return;
	currentScene->Draw3D();
}

void Scene::DoUpdate()
{
	if (currentScene == nullptr) return;
	currentScene->Update();
}