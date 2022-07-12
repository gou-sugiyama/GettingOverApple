#include"DxLib.h"
#include"SceneManager.h"
#include"Game.h"
#include"Title.h"
#include"player.h"
#include"AppleManager.h"
#include"RankMng.h"
#include"UI.h"
#include"Hit.h"

CGame::CGame(CController* pController):CScene(pController){ 
	//受け取ったコントローラの格納
	controller = pController;
	//コントローラーのフラグを変更
	controller->ToggleControlFlg();		//フラグをFALSEへ変更
	//プレイヤーを動的確保
	player = new CPlayer(controller);
	//アップルマネージャーを動的確保
	applemanager = new CAppleManager();
	//UIを動的確保
	UI = new CUI(controller);
	//Hit
	hit = new CHitBoxCheck;
}

CGame::~CGame() {
	//動的確保したものを解放する

	//コントローラーのフラグを変更
	controller->ToggleControlFlg();		//フラグをTRUEへ変更

	delete player;
	delete applemanager;
	delete UI;
	delete hit;
}

CScene* CGame::Update() {

	if (UI->Update()) {
		applemanager->Update();
		player->Update();
		if (hit->HitBox(player, applemanager->getpApple())
			&& applemanager->getpApple()->getisShow()) {
			applemanager->getpApple()->toggleisShow();

		}
	}
	else {
		static int WaitTime = 0;
		if (++WaitTime > 180) {
			WaitTime = 0;
			controller->SetScore(UI->GetScore());
			return new CRankMng(controller);
		}
		
	}

	return this;
}

void CGame::Render()const {
	//DrawFormatString(0, 0, GetColor(255, 255, 255),"ゲーム");
	applemanager->Render();
	player->Render();
	UI->Render();
}