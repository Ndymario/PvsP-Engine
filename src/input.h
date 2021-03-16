#pragma once
#include <raylib.h>
#include <map>
#include <iostream>

using namespace std;

struct Input
{

	// Private members.
	private:
		static map<string, int[3]> controls[4];

	// Public members.
	public:
		static int gamePadIDs[4];
		static void AddControl(string name, int keyboard, int player);
		static void AddControl(string name, int keyboard, int gamepadButton, int player);
		static void AddControl(string name, int keyboard, int gamepadAxis, bool isPosAxisDir, int player);
		static void AddControl(string name, int keyboard, int gamepadButton, int gamepadAxis, bool isPosAxisDir, int player);
		static void ChangeControlKeyboard(string name, int keyboard, int player);
		static void ChangeControlGamepad(string name, int gamepadButton, int player);
		static void ChangeControlGamepadAxis(string name, int gamepadAxis, bool isPosAxisDir, int player);
		static void ChangeControlRemoveGamepadAxis(string name, int player);
		static void RemoveControl(string name, int player);
		static float ButtonDown(string name, int player);
		static bool ButtonUp(string name, int player);
		static float ButtonPressed(string name, int player);
		static bool ButtonReleased(string name, int player);

};

