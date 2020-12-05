#include <map>
#include <raylib.h>
#include <string>

using namespace std;

#pragma once
struct AssetManager
{

	// Place to store loaded data.
	private:
		static int dummyCount;
		static map<string, Model> loadedModels;
		static map<string, ModelAnimation*> loadedAnimations;
		static map<string, Texture2D> loadedTextures;
		static map<string, Sound> loadedSounds;

	// Public info.
	public:

		// Asset path.
		static string AssetFolder;

		// Models.
		static void LoadModelAsset(string path, string name);
		static void UnloadModelAsset(string name);
		static Model& GetModel(string name);

		// Animations.
		static void LoadAnimationAsset(string path, string name);
		static void UnloadAnimationAsset(string name);
		static ModelAnimation& GetAnimation(string name);

		// Textures.
		static void LoadTextureAsset(string path, string name);
		static void UnloadTextureAsset(string name);
		static Texture2D& GetTexture(string name);

		// Sounds.
		static void LoadSoundAsset(string path, string name);
		static void UnloadSoundAsset(string name);
		static Sound& GetSound(string name);

};