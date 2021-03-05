#include "ui.h"

Shape Shape::createShape(string name, string textureName, bool isInteractable = true, bool hasHighlightedTexture = false,\
int highlightedTexture_xPos = 0, int highlightedTexture_yPos = 0,int texture_xPos = 0, int texture_yPos = 0,\
int width = 0, int height = 0, bool isCircular = false, int radius = NULL, int xPos = 0, int yPos = 0, bool is3D = false, int zPos = NULL)
{
    // Create a new shape, and store what was passed to the function into the new shape
    // (variables commented in "ui.h")
    Shape newShape;
    newShape.name = name;
    newShape.isInteractable = isInteractable;
    newShape.hasHighligthedTexture = hasHighlightedTexture;
    newShape.highlightedTexture_xPos = highlightedTexture_xPos;
    newShape.highlightedTexxture_yPos = highlightedTexture_yPos;
    newShape.texture_xPos = texture_xPos;
    newShape.texture_yPos = texture_yPos;
    newShape.width = width;
    newShape.height = height;
    newShape.isCircular = isCircular;
    newShape.radius = radius;
    newShape.xPos = xPos;
    newShape.yPos = yPos;
    newShape.is3D = is3D;
    newShape.zPos = zPos;

    // Create a raylib recatangle using the passed dimentions
    newShape.shapeRectangle.x = xPos;
    newShape.shapeRectangle.y = yPos;
    newShape.shapeRectangle.width = width;
    newShape.shapeRectangle.height = height;

    // Store the texture of the shape
    newShape.shapeTexture = AssetManager::GetTexture(textureName);
    newShape.shapeRectangle = {texture_xPos, texture_yPos, width, height};

    // Return the new shape
    return newShape;
};