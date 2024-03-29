//-----------------------------------------------------------------------+
// スカイドームクラス                                   
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+
#include "ObjectSky.h"

const VECTOR ObjectSky::SCALE_SIZE = { 12.0f, 12.0f, 12.0f };
const VECTOR ObjectSky::ROTATE_RAD = { 15.0f * DX_PI_F / 180.0f, 0.0f, 0.0f };

// コンストラクタ
ObjectSky::ObjectSky(int sourceModelHandle)
	:ObjectBase(sourceModelHandle)
{
	m_position = VGet(0.0f, -800.0f, -5000.0f);
	m_direction = VGet(0.0f, 0.0f, 0.0f);
	m_radius = 0.0f;
}

// デストラクタ
ObjectSky::~ObjectSky()
{
	// 処理なし
}

// 初期化処理
void ObjectSky::Initialize()
{
	MV1SetScale(m_modelHandle, SCALE_SIZE);                 // スケールの設定  ※元のモデルがあまりにも大きすぎるため縮小
	MV1SetRotationXYZ(m_modelHandle, ROTATE_RAD);           // 回転値の設定
	MV1SetPosition(m_modelHandle, m_position);
}

// 更新処理
void ObjectSky::Update(float deltaTime)
{
	// モデルを回転させる
	MV1SetRotationXYZ(m_modelHandle, VGet(m_direction.x, m_direction.y, m_direction.z));

	// 回転角度を更新
	m_direction.y -= 0.01f * deltaTime;
}
