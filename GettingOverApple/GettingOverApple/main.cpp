#include "DxLib.h"
#include"SceneManager.h"
#include"Controller.h"
#include"Title.h"
#include"Apple.h"
#include"UI.h"
#include"CFps.h"

/*************************************************************************
*	プログラムの開始
**************************************************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpcmdLine, int nCmdShow) {
	SetMainWindowText("GettingOverApple");

	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)return -1;

	SetDrawScreen(DX_SCREEN_BACK);

	//コントローラの動的確保
	CController controller;
	Fps fps;

	//管理システムを動的確保
	CSceneManager* manager;
	manager = new CSceneManager(new CTitle(&controller));


	//ゲームループ
	while (ProcessMessage() == 0 
		&& manager->Update() != nullptr&& controller.GetControl().Buttons[5] != TRUE) {
		
		ClearDrawScreen();		//画面の初期化

		fps.Update();		//フレームのアップデート

		controller.control(controller.GetControlFlg());

		manager->Render();
		//fps.Draw();		FPSでバック用

		ScreenFlip();				//裏画面の内容を表画面に反映
		fps.Wait();			// 60h/1s 超えたら少し止める
	}

	//managerの解放
	delete manager;


	DxLib_End();					//DXライブラリ使用の終了処理
	return 0;				//ソフト終了
}
