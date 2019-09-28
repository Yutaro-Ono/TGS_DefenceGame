//-----------------------------------------------------------------------+
// フィールドオブジェクトクラス                                 
//                                              Last Update : 2019/07/02
//-----------------------------------------------------------------------+
#include "ObjectField.h"

const VECTOR ObjectField::SCALE_SIZE = { 20.0f, 5.0f, 18.0f };      // モデルの拡大率

// コンストラクタ
ObjectField::ObjectField(int sourceModelHandle)
	:ObjectBase(sourceModelHandle)
{
	m_position = VGet(0.0f, -10.0f, 0.0f);
	m_direction = VGet(0.0f, 0.0f, 0.0f);
	m_radius = 0.0f;
}

// デストラクタ
ObjectField::~ObjectField()
{
	// 処理なし
}

// 初期化処理
void ObjectField::Initialize()
{
	MV1SetScale(m_modelHandle, SCALE_SIZE);
	MV1SetPosition(m_modelHandle, m_position);
}

// 更新処理
void ObjectField::Update(float deltaTime)
{
	// 処理なし
}
