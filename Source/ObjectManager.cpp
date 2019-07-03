//-----------------------------------------------------------------------+
// オブジェクトマネージャークラス                                    
//                                              Last Update : 2019/07/01
//-----------------------------------------------------------------------+
#include "ObjectManager.h"
#include "ObjectField.h"

// コンストラクタ
ObjectManager::ObjectManager()
	:m_fieldSourceHandle(-1)
{
	// NULLを入れておく
	for (int i = 0; i < OBJECT_NUM_H; i++)
	{
		for (int j = 0; j < OBJECT_NUM_W; j++)
		{
			m_object[i][j] = NULL;
		}
	}
}

// デストラクタ
ObjectManager::~ObjectManager()
{
}

// 各種初期化
void ObjectManager::Initialize()
{
	// フィールドモデルのロード
	m_fieldSourceHandle = MV1LoadModel("Data/Model/Field/vstage/IT_バレンタインステージ風舞台.mv1");

	// フィールドを生成
	m_fieldObj = new ObjectField(m_fieldSourceHandle);

	m_fieldObj->Initialize();

	//// フィールドを生成
	//for (int i = 0; i < OBJECT_NUM_H; i++)
	//{
	//	for (int j = 0; j < OBJECT_NUM_W; j++)
	//	{
	//		object[i][j] = new ObjectField(m_fieldSourceHandle);
	//	}
	//}
}

// 各種解放処理
void ObjectManager::Delete()
{

	MV1DeleteModel(m_fieldSourceHandle);
	delete (m_fieldObj);

	for (int i = 0; i < OBJECT_NUM_H; i++)
	{
		for (int j = 0; j < OBJECT_NUM_W; j++)
		{
			delete (m_object[i][j]);
			m_object[i][j] = NULL;
		}
	}
}

// 更新処理
void ObjectManager::Update()
{

}

// 描画処理
void ObjectManager::Draw()
{
	m_fieldObj->Draw();
}
