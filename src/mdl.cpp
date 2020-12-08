#include "mdl.h"
#include "assetManager.h"

void Mdl::SetModel(string name)
{
	currModel = AssetManager::GetModel(name);
	frameTimer = 0;
}

void Mdl::SetAnimation(string name)
{
    timerFrozen = false;
	currAnimation = AssetManager::GetAnimation(name);
	currAnimationName = name;
	frameTimer = 0;
}

void Mdl::QueueAnimation(string name)
{
	animationQueue.push(name);
}

void Mdl::ExecuteQueue()
{
	queueMode = true;
	frameTimer = 0;
	currAnimationName = animationQueue.front();
	currAnimation = AssetManager::GetAnimation(currAnimationName);
	animationQueue.pop();
	if (animationQueue.size() == 0) { queueMode = false; }

}

void Mdl::SetTexture(string name, int materialId, int mapType)
{
	currTexture = AssetManager::GetTexture(name);
	SetMaterialTexture(&currModel.materials[materialId], mapType, currTexture);
}

string Mdl::CurrentAnimation()
{
	return currAnimationName;
}

bool Mdl::AnimationIsFinished()
{
    return (frameTimer == currAnimation.frameCount - 1);
}

void Mdl::Freeze()
{
    timerFrozen = true;
}

void Mdl::Rotate(Vector3 rotateVec)
{
	currModel.transform = MatrixRotateXYZ({DEG2RAD * rotateVec.x, DEG2RAD * rotateVec.y, DEG2RAD * rotateVec.z});
}

Model &Mdl::GetModel()
{
	return currModel;
}

void Mdl::Update()
{
	if (timerFrozen)
		return;
	frameTimer++;
	UpdateModelAnimation(currModel, currAnimation, frameTimer);
	if (frameTimer >= currAnimation.frameCount)
	{
		frameTimer = 0;
		if (queueMode)
		{
			currAnimationName = animationQueue.front();
			animationQueue.pop();
			currAnimation = AssetManager::GetAnimation(currAnimationName);
			if (animationQueue.size() == 0) { queueMode = false; }
		}
	}
}