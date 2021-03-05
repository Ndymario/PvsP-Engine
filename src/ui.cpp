#include "ui.h"

Shape Shape::createShape(string name, string textureName, bool isInteractable, bool hasHighlightedTexture,\
int highlightedTexture_xPos, int highlightedTexture_yPos, int texture_xPos, int texture_yPos,\
int width, int height, bool isCircular, int radius, int xPos, int yPos, bool is3D, int zPos)
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
    newShape.shapeRectangle = {float(texture_xPos), float(texture_yPos), float(width), float(height)};

    // Return the new shape
    return newShape;
};