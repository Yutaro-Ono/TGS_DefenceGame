//-----------------------------------------------------------+
// 様々なスケーリングを演出するクラス
//      : 画像のサイズの拡大縮小などを主に担当する
//                                  Last Update : 2019/08/04
//-----------------------------------------------------------+
#pragma once
#include "DirectorBase.h"

class DirectorScaler : public DirectorBase
{
public:

	DirectorScaler();                     // コンストラクタ
	~DirectorScaler();                    // デストラクタ

	void Initialize() override;           // 各種初期化処理
	void Delete() override;               // 各種解放処理

	// 画像の拡大縮小演出
	void Zoomer(const int in_graphSize, const int in_maxSize, const int in_miniSize, float deltaTime);

	// 画像サイズのゲッター
	const int& GetGraphScale() const { return m_graphScale; }

private:

	int m_graphScale;             // 画像サイズ

};