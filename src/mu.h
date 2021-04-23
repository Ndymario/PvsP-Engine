#pragma once

// Measurement unit, where 0xABCD represents A in tiles (&8 is sign), B in pixels, C in subpixels, and D in subsubpixels. There are 16 subpixels in a pixel, 16 pixels in a block, etc. 0xFFFF is NA.
typedef unsigned short MU;

// Extended measurement unit, where 0xABCDEFGH represents ABCDE in tiles (&8 is sign), F in pixels, G in subpixels, and H in subsubpixels. There are 16 subpixels in a pixel, 16 pixels in a block, etc. 0xFFFFFFFF is NA.
typedef unsigned int EMU;