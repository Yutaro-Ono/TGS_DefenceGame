//-----------------------------------------------------------------------+
// 回収ポッドクラス                 
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+
#include "ObjectPod.h"

const VECTOR ObjectPod::INITIAL_POSITION = VGet(0.0f, 0.0f, 0.0f);         // 開始時の初期位置
const float ObjectPod::HIT_RADIUS = 8.5f;                                  // 当たり判定用半径
const VECTOR ObjectPod::SCALE_SIZE = VGet(5.0f, 5.0f, 5.0f);               // 拡大率のサイズ

// コンストラクタ
ObjectPod::ObjectPod(int sourceModelHandle)
	:ObjectBase(sourceModelHandle)
{
	// 処理なし
}

// デストラクタ
ObjectPod::~ObjectPod()
{
	// 処理なし
}

// 各種初期化処理
void ObjectPod::Initialize()
{
	m_position = INITIAL_POSITION;
	m_radius = HIT_RADIUS;
	m_effect = new PlayEffect("Data/Effects/ItemPod_PodEffect.efk");
	m_effect->Initialize();
}

// 解放処理
void ObjectPod::Delete()
{
	m_effect->Delete();

	delete (m_effect);
}

// 更新処理
void ObjectPod::Update(float deltaTime)
{
	// モデルの拡大率セット
	MV1SetScale(m_modelHandle, SCALE_SIZE);
	// モデルの座標セット
	MV1SetPosition(m_modelHandle, m_position);

	// ポッドエフェクトの再生
	if (m_effect->GetNowPlaying() == -1)
	{
		m_effect->PlayEffekseer(GetPosition());
		m_effect->SetEffectScale(12.0f, 12.0f, 12.0f);
	}

}
