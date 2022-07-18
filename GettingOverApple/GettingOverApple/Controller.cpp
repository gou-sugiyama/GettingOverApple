#include "Controller.h"


XINPUT_STATE CController::control(bool isChattering)
{

	if (!isChattering) {


		OldKey = input;
		GetJoypadXInputState(DX_INPUT_PAD1, &input);
		for (int i = 0; i < MAX_BUTTON; i++) {
			data.Buttons[i] = input.Buttons[i] & ~OldKey.Buttons[i];
		}
		data.LeftTrigger = input.LeftTrigger & ~OldKey.LeftTrigger;
		data.RightTrigger = input.RightTrigger & ~OldKey.RightTrigger;
		data.ThumbLX = input.ThumbLX & ~OldKey.ThumbLX;
		data.ThumbLY = input.ThumbLY & ~OldKey.ThumbLY;
		data.ThumbRX = input.ThumbRX & ~OldKey.ThumbRX;
		data.ThumbRY = input.ThumbRY & ~OldKey.ThumbRY;

		return data;

	}
	else {

		OldKey = input;
		GetJoypadXInputState(DX_INPUT_PAD1, &input);
		data = input;
		for (int i = 0; i < MAX_BUTTON; i++) {
			data.Buttons[i] = input.Buttons[i] & ~OldKey.Buttons[i];
		}

		return data;

	}

}

XINPUT_STATE CController::GetControl() const
{
	return data;
}

bool CController::GetControlFlg() const
{
	return ControlFlg;
}

void CController::ToggleControlFlg()
{
	ControlFlg = !(ControlFlg);
}
