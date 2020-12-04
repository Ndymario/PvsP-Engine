#include "assetManager.h"

int AssetManager::dummyCount;
map<const char*, Model> AssetManager::loadedModels;
map<const char*, ModelAnimation*> AssetManager::loadedAnimations;
map<const char*, Texture2D> AssetManager::loadedTextures;

void AssetManager::LoadModelAsset(const char* path, const char* name)
{
	if (!loadedModels.contains(name))
	{
		loadedModels[name] = LoadModel(path);
	}
}

void AssetManager::UnloadModelAsset(const char* name)
{
	if (loadedModels.contains(name)) {
		UnloadModel(loadedModels[name]);
		loadedModels.erase(name);
	}
}

Model& AssetManager::GetModel(const char* name)
{
	return loadedModels[name];
}

void AssetManager::LoadAnimationAsset(const char* path, const char* name)
{
	if (!loadedAnimations.contains(name))
	{
		loadedAnimations[name] = LoadModelAnimations(path, &dummyCount);
	}
}

void AssetManager::UnloadAnimationAsset(const char* name)
{
	if (loadedAnimations.contains(name)) {
		UnloadModelAnimation(*loadedAnimations[name]);
		loadedAnimations.erase(name);
	}
}

ModelAnimation& AssetManager::GetAnimation(const char* name)
{
	return *loadedAnimations[name];
}

void AssetManager::LoadTextureAsset(const char* path, const char* name)
{
	if (!loadedTextures.contains(name))
	{
		loadedTextures[name] = LoadTexture(path);
	}
}

void AssetManager::UnloadTextureAsset(const char* name)
{
	if (loadedTextures.contains(name)) {
		UnloadTexture(loadedTextures[name]);
		loadedTextures.erase(name);
	}
}

Texture& AssetManager::GetTexture(const char* name)
{
	return loadedTextures[name];
}