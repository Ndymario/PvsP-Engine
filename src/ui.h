#pragma once
#include "assetManager.h"

struct Shape
{
    // Store raylib shape definition
    Rectangle shapeRectangle;
    Texture2D shapeTexture;

    // Define a shape
    string name; // Give the shape a name
    int oldWidth; // Original width.
    int oldHeight; // Original height.
    int width; // The width of the shape
    int height; // The height of the shape
    bool isCircular; // Is the shape circular or does it have cylindrical features?
    float radius; // The radius of the shape (if it's a circle)
    bool isInteractable; // Should this shape be able to be interacted with?

    // Define coordinates
    float xPos; // The x coordinate of the shape
    float yPos; // The y coordinate of the shape
    bool is3D; // Does this shape use the z-axis?
    float zPos; // The z coordinatte of the shape, if it exists

    // Define texture related things
    string textureName; // More specifically, the file path to the texture
    int texture_xPos; // xPos of the texture in the texture file (for sprite sheets)
    int texture_yPos; // yPos of the texture in the texture file (for sprite sheets)
    Rectangle textureRectangle;
    bool hasHighligthedTexture; // If there is a texture for when the shape is being highlighted over
    int highlightedTexture_xPos; // xPos of the "highlight" texture in the texture file
    int highlightedTexture_yPos; // yPos of the "highlight" texture in the texture file
    // it's safe to assume there won't be a zPos for a 2D texture :p

    void(*onClick)() = NULL; // Handle click.

    // Define our functions.
    static Shape createShape(string name, string textureName, bool isInteractable = true, bool hasHighlightedTexture = false, int highlightedTexture_xPos = 0, int highlightedTexture_yPos = 0, int texture_xPos = 0, int texture_yPos = 0, int width = 0, int height = 0, bool isCircular = false, float radius = 0, float xPos = 0, float yPos = 0, bool is3D = false, float zPos = 0);
    
    // Scale functions.
    void scale(float scale);
    void scaleX(float scale);
    void scaleY(float scale);

    // Draw functions.
    void draw(float xOff = 0, float yOff = 0);
    void drawRepeated(int width, int height);

    // Update function.
    void update();

};
