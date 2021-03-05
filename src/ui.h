#pragma once
#include "assetManager.h"

struct Shape
{
    // Store raylib shape definition
    Rectangle shapeRectangle;
    Texture2D shapeTexture;

    // Define a shape
    string name; // Give the shape a name
    int width; // The width of the shape
    int height; // The height of the shape
    bool isCircular; // Is the shape circular or does it have cylindrical features?
    int radius; // The radius of the shape (if it's a circle)
    bool isInteractable; // Should this shape be able to be interacted with?

    // Define coordinates
    int xPos; // The x coordinate of the shape
    int yPos; // The y coordinate of the shape
    bool is3D; // Does this shape use the z-axis?
    int zPos; // The z coordinatte of the shape, if it exists

    // Define texture related things
    string textureName; // More specifically, the file path to the texture
    int texture_xPos; // xPos of the texture in the texture file (for sprite sheets)
    int texture_yPos; // yPos of the texture in the texture file (for sprite sheets)
    Rectangle textureRectangle;
    bool hasHighligthedTexture; // If there is a texture for when the shape is being highlighted over
    int highlightedTexture_xPos; // xPos of the "highlight" texture in the texture file
    int highlightedTexxture_yPos; // yPos of the "highlight" texture in the texture file
    // it's safe to assume there won't be a zPos for a 2D texture :p

    // Define our functions
    static Shape createShape(string name, string textureName, bool isInteractable = true, bool hasHighlightedTexture = false, int highlightedTexture_xPos = 0, int highlightedTexture_yPos = 0, int texture_xPos = 0, int texture_yPos = 0, int width = 0, int height = 0, bool isCircular = false, int radius = NULL, int xPos = 0, int yPos = 0, bool is3D = false, int zPos = NULL);
};
