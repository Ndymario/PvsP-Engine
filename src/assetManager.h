#include <map>
#include <raylib.h>

using namespace std;

#pragma once
struct AssetManager
{

	// Place to store loaded data.
	private:
		static int dummyCount;
		static map<const char*, Model> loadedModels;
		static map<const char*, ModelAnimation*> loadedAnimations;
		static map<const char*, Texture2D> loadedTextures;

	// Public info.
	public:

		// Models.
		static void LoadModelAsset(const char* path, const char* name);
		static void UnloadModelAsset(const char* name);
		static Model& GetModel(const char* name);

		// Animations.
		static void LoadAnimationAsset(const char* path, const char* name);
		static void UnloadAnimationAsset(const char* name);
		static ModelAnimation& GetAnimation(const char* name);

		// Textures.
		static void LoadTextureAsset(const char* path, const char* name);
		static void UnloadTextureAsset(const char* name);
		static Texture2D& GetTexture(const char* name);

};