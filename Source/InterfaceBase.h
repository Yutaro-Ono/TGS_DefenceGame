//-----------------------------------------------------------------+
// インターフェース基底クラス
//      : 各ゲームシーンにおけるインターフェースの基底クラス
//                                                2019 Yutaro Ono.
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