#pragma once
#include"DxLib.h"

#define CONTROL_X_RIGHT 25000
#define CONTROL_X_LEFT -25000
#define MAX_BUTTON 16

bool controllerKey;



class Controller
{
private:
	XINPUT_STATE input;
	XINPUT_STATE OldKey;
	XINPUT_STATE data;
public:
	XINPUT_STATE control();
};

