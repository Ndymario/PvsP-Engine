#pragma once
#include <raylib.h>
#include <string>

using namespace std;

struct Mdl
{

	// Private members.
	private:
		Model currModel;
		ModelAnimation currAnimation;
		Texture2D currTexture;

	//Public members.
	public:

		// Timer stuff.
		int frameTimer = 0;
		bool timerFrozen = false;

		// Set aspect.
		void SetModel(string name);
		void SetAnimation(string name);
		void SetTexture(string name, int materialId, int mapType);
		Model& GetModel();
		void Update();

};
