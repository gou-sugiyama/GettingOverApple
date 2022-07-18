#pragma once
class CObject
{
public:
	//画像
	int* image = 0;
	//座標
	float x = 0;
	float y = 0;

	//当たり判定
	int width = 0;
	int height = 0;
	float rangeX = 0; 
	float rangeY = 0;

public:
	CObject() {}
	virtual void HitAction() = 0;


};

bool CheckHit(CObject* pObj1, CObject* pObj2);