#include "assetManager.h"

int AssetManager::dummyCount;
map<string, Model> AssetManager::loadedModels;
map<string, ModelAnimation*> AssetManager::loadedAnimations;
map<string, Texture2D> AssetManager::loadedTextures;

void AssetManager::LoadModelAsset(const char* path, string name)
{
	if (!loadedModels.contains(name))
	{
		loadedModels[name] = LoadModel(path);
	}
}

void AssetManager::UnloadModelAsset(string name)
{
	if (loadedModels.contains(name)) {
		UnloadModel(loadedModels[name]);
		loadedModels.erase(name);
	}
}

Model& AssetManager::GetModel(string name)
{
	return loadedModels[name];
}

void AssetManager::LoadAnimationAsset(const char* path, string name)
{
	if (!loadedAnimations.contains(name))
	{
		loadedAnimations[name] = LoadModelAnimations(path, &dummyCount);
	}
}

void AssetManager::UnloadAnimationAsset(string name)
{
	if (loadedAnimations.contains(name)) {
		UnloadModelAnimation(*loadedAnimations[name]);
		loadedAnimations.erase(name);
	}
}

ModelAnimation& AssetManager::GetAnimation(string name)
{
	return *loadedAnimations[name];
}

void AssetManager::LoadTextureAsset(const char* path, string name)
{
	if (!loadedTextures.contains(name))
	{
		loadedTextures[name] = LoadTexture(path);
	}
}

void AssetManager::UnloadTextureAsset(string name)
{
	if (loadedTextures.contains(name)) {
		UnloadTexture(loadedTextures[name]);
		loadedTextures.erase(name);
	}
}

Texture& AssetManager::GetTexture(string name)
{
	return loadedTextures[name];
}