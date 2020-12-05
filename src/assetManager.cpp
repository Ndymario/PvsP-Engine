#include "assetManager.h"

int AssetManager::dummyCount;
string AssetManager::AssetFolder = string(GetWorkingDirectory()) + "/assets/";
map<string, Model> AssetManager::loadedModels;
map<string, ModelAnimation*> AssetManager::loadedAnimations;
map<string, Texture2D> AssetManager::loadedTextures;
map<string, Sound> AssetManager::loadedSounds;

void AssetManager::LoadModelAsset(string path, string name)
{
	if (!loadedModels.contains(name))
	{
		loadedModels[name] = LoadModel((AssetFolder + path).c_str());
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

void AssetManager::LoadAnimationAsset(string path, string name)
{
	if (!loadedAnimations.contains(name))
	{
		loadedAnimations[name] = LoadModelAnimations((AssetFolder + path).c_str(), &dummyCount);
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

void AssetManager::LoadTextureAsset(string path, string name)
{
	if (!loadedTextures.contains(name))
	{
		loadedTextures[name] = LoadTexture((AssetFolder + path).c_str());
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

void AssetManager::LoadSoundAsset(string path, string name)
{
	if (!loadedSounds.contains(name))
	{
		loadedSounds[name] = LoadSound((AssetFolder + path).c_str());
	}
}

void AssetManager::UnloadSoundAsset(string name)
{
	if (loadedSounds.contains(name)) {
		UnloadSound(loadedSounds[name]);
		loadedSounds.erase(name);
	}
}

Sound& AssetManager::GetSound(string name)
{
	return loadedSounds[name];
}