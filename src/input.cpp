#include "input.h"
#include <imgui.h>

map<string, int[3]> Input::controls[4]; // 0 - Keyboard key, 1 - Gamepad button, 2 - 0xPQAADDUU P: Was previously down. Q: Was previously up. A: Axis, D: Direction, U: Use gamepad axis.
int Input::gamePadIDs[4] = { -1, -1, -1, -1 };
bool Input::enabled = true;

void Input::AddControl(string name, int keyboard, int player)
{
	controls[player][name][0] = keyboard;
	controls[player][name][1] = -1;
	controls[player][name][2] = 0;
}

void Input::AddControl(string name, int keyboard, int gamepadButton, int player)
{
	controls[player][name][0] = keyboard;
	controls[player][name][1] = gamepadButton;
	controls[player][name][2] = 0;
}

void Input::AddControl(string name, int keyboard, int gamepadAxis, bool isPosAxisDir, int player)
{
	controls[player][name][0] = keyboard;
	controls[player][name][1] = -1;
	controls[player][name][2] = ((gamepadAxis & 0xFF) << 16) | (isPosAxisDir << 8) | 1;
}

void Input::AddControl(string name, int keyboard, int gamepadButton, int gamepadAxis, bool isPosAxisDir, int player)
{
	controls[player][name][0] = keyboard;
	controls[player][name][1] = gamepadButton;
	controls[player][name][2] = ((gamepadAxis & 0xFF) << 16) | (isPosAxisDir << 8) | 1;
}

void Input::ChangeControlKeyboard(string name, int keyboard, int player)
{
	controls[player][name][0] = keyboard;
}

void Input::ChangeControlGamepad(string name, int gamepadButton, int player)
{
	controls[player][name][1] = gamepadButton;
}

void Input::ChangeControlGamepadAxis(string name, int gamepadAxis, bool isPosAxisDir, int player)
{
	controls[player][name][2] = ((gamepadAxis & 0xFF) << 16) | (isPosAxisDir << 8) | 1;
}

void Input::ChangeControlRemoveGamepadAxis(string name, int player)
{
	controls[player][name][2] = 0;
}

void Input::RemoveControl(string name, int player)
{
	controls[player].erase(name);
}

float Input::ButtonDown(string name, int player)
{
	if (!enabled)
	{
		return false;
	}
	int key = controls[player][name][0];
	int gamepad = controls[player][name][1];
	int gamepadId = gamePadIDs[player];
	controls[player][name][2] &= 0xF0FFFFFF;
	int rawGamepadAxisVal = controls[player][name][2];
	float ret = 0;
	if (key != -1 && IsKeyDown(key))
	{
		ret = 1;
	}
	if (gamepadId != -1 && gamepad != -1 && IsGamepadButtonDown(gamepadId, gamepad))
	{
		ret = 1;
	}
	if (ret < 1 && gamepadId != -1 && rawGamepadAxisVal)
	{
		bool forward = rawGamepadAxisVal & 0xFF00;
		float mov = GetGamepadAxisMovement(gamepadId, (rawGamepadAxisVal & 0xFF0000) >> 16);
		if (mov > 0 && forward)
		{ret = abs(mov);
			ret = mov;
		}
		else if (mov < 0 && !forward)
		{
			ret = mov * -1;
		}
	}
	return ret;
}

bool Input::ButtonUp(string name, int player)
{
	if (!enabled)
	{
		return true;
	}
	int key = controls[player][name][0];
	int gamepad = controls[player][name][1];
	int gamepadId = gamePadIDs[player];
	controls[player][name][2] &= 0x0FFFFFFF;
	int rawGamepadAxisVal = controls[player][name][2];
	bool ret = true;
	if (key != -1)
	{
		ret &= IsKeyUp(key);
	}
	if (gamepadId != -1 && gamepad != -1)
	{
		ret &= IsGamepadButtonUp(gamepadId, gamepad);
	}
	if (ret && rawGamepadAxisVal && gamepadId != -1)
	{
		bool forward = rawGamepadAxisVal & 0xFF00;
		float mov = GetGamepadAxisMovement(gamepadId, (rawGamepadAxisVal & 0xFF0000) >> 16);
		if (mov > 0 && forward)
		{
			ret = false;
		}
		else if (mov < 0 && !forward)
		{
			ret = false;
		}
	}
	return ret;
}

float Input::ButtonPressed(string name, int player)
{
	if (!enabled)
	{
		return false;
	}
	int key = controls[player][name][0];
	int gamepad = controls[player][name][1];
	int gamepadId = gamePadIDs[player];
	int rawGamepadAxisVal = controls[player][name][2];
	float ret = 0;
	if (key != -1 && IsKeyPressed(key))
	{
		ret = 1;
	}
	if (gamepadId != -1 && gamepad != -1 && IsGamepadButtonPressed(gamepadId, gamepad))
	{
		ret = 1;
	}
	if (ret < 1 && !(rawGamepadAxisVal & 0xF0000000) && gamepadId != -1 && rawGamepadAxisVal)
	{
		bool forward = rawGamepadAxisVal & 0xFF00;
		float mov = GetGamepadAxisMovement(gamepadId, (rawGamepadAxisVal & 0xFF0000) >> 16);
		if (mov > 0 && forward)
		{
			ret = abs(mov);
			ret = mov;
			controls[player][name][2] |= 0xF0000000;
		}
		else if (mov < 0 && !forward)
		{
			ret = mov * -1;
			controls[player][name][2] |= 0xF0000000;
		}
	}
	return ret;
}

bool Input::ButtonReleased(string name, int player)
{
	if (!enabled)
	{
		return false;
	}
	int key = controls[player][name][0];
	int gamepad = controls[player][name][1];
	int gamepadId = gamePadIDs[player];
	int rawGamepadAxisVal = controls[player][name][2];
	bool ret = true;
	if (key != -1)
	{
		ret &= IsKeyReleased(key);
	}
	if (gamepadId != -1 && gamepad != -1)
	{
		ret &= IsGamepadButtonReleased(gamepadId, gamepad);
	}
	if (ret && rawGamepadAxisVal && !(rawGamepadAxisVal & 0x0F000000) && gamepadId != -1)
	{
		bool forward = rawGamepadAxisVal & 0xFF00;
		float mov = GetGamepadAxisMovement(gamepadId, (rawGamepadAxisVal & 0xFF0000) >> 16);
		if (mov > 0 && forward)
		{
			ret = false;
			controls[player][name][2] |= 0x0F000000;
		}
		else if (mov < 0 && !forward)
		{
			ret = false;
			controls[player][name][2] |= 0x0F000000;
		}
	}
	return ret;
}