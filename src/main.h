#pragma once

#include <iostream>
#include <stdio.h>
#include <raylib.h>
#include <algorithm>
#include <assetManager.h>
#include <scene.h>
#include <titleScreen.h>

// Some constants.
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;
const Vector2 ZERO = { 0, 0 };

// We need these.
static Camera3D MainCamera;

// Scenes.
static TitleScreen TitleScreenScene;