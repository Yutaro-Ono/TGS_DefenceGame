
#include "ObjectPod.h"

const VECTOR ObjectPod::INITIAL_POSITION = VGet(0.0f, 0.0f, 0.0f);         // 開始時の初期位置
const float ObjectPod::HIT_RADIUS = 8.5f;                                  // 当たり判定用半径
const VECTOR ObjectPod::SCALE_SIZE = VGet(5.0f, 5.0f, 5.0f);               // 拡大率のサイズ

// コンストラクタ
ObjectPod::ObjectPod(int sourceModelHandle)
	:ObjectBase(sourceModelHandle)
{

}

// デストラクタ
ObjectPod::~ObjectPod()
{
}

// 各種初期化処理
void ObjectPod::Initialize()
{
	m_position = INITIAL_POSITION;
	m_radius = HIT_RADIUS;

}

// 解放処理
void ObjectPod::Delete()
{
}

// 更新処理
void ObjectPod::Update()
{
	// モデルの拡大率セット
	MV1SetScale(m_modelHandle, SCALE_SIZE);
	// モデルの座標セット
	MV1SetPosition(m_modelHandle, m_position);
}
