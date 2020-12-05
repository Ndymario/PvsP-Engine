#include "mdl.h"
#include "assetManager.h"

void Mdl::SetModel(string name)
{
	currModel = AssetManager::GetModel(name);
	frameTimer = 0;
}

void Mdl::SetAnimation(string name)
{
	currAnimation = AssetManager::GetAnimation(name);
	frameTimer = 0;
}

void Mdl::SetTexture(string name, int materialId, int mapType)
{
	currTexture = AssetManager::GetTexture(name);
	SetMaterialTexture(&currModel.materials[materialId], mapType, currTexture);
}

Model& Mdl::GetModel()
{
	return currModel;
}

void Mdl::Update()
{
	if (timerFrozen) return;
	frameTimer++;
	UpdateModelAnimation(currModel, currAnimation, frameTimer);
	if (frameTimer >= currAnimation.frameCount) { frameTimer = 0; }
}