#pragma once
#include <raylib.h>
#include <raymath.h>
#include <string>
#include <iostream>

#include <queue>

using namespace std;

struct Mdl
{

	// Private members.
private:
	Model currModel;
	ModelAnimation currAnimation;
	Texture2D currTexture;
	bool queueMode = false;
	queue<string> animationQueue;
	string currAnimationName;

	//Public members.
public:
	// Timer stuff.
	int frameTimer = 0;
	bool timerFrozen = false;

	// Set aspect.
	void SetModel(string name);
	void SetAnimation(string name);
	void QueueAnimation(string name);
	void ExecuteQueue();
	void SetTexture(string name, int materialId, int mapType);
	string CurrentAnimation();

    // Testing for state stuff
    bool AnimationIsFinished();

    // Freeze the animation
    void Freeze();

	// Transformational things.
	void Rotate(Vector3 rotateVec);

	Model &GetModel();
	void Update();
};
