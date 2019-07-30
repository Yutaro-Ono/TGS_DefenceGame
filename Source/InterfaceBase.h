//-----------------------------------------------------------------+
// インターフェース基底クラス
//      : 各ゲームシーンにおけるインターフェースの基底クラス
//                                        Last Update : 2019/07/10
//-----------------------------------------------------------------+
#pragma once

class InterfaceBase
{
public:

	InterfaceBase();
	~InterfaceBase();

	virtual void Initialize() = 0;

	virtual void Update() = 0;
};