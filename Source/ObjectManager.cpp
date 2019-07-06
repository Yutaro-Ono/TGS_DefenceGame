//-----------------------------------------------------------------------+
// オブジェクトマネージャークラス                                    
//                                              Last Update : 2019/07/02
//-----------------------------------------------------------------------+
#include "ObjectManager.h"
#include "ObjectField.h"
#include "ObjectSky.h"

// コンストラクタ
ObjectManager::ObjectManager()
	:m_fieldSourceHandle(-1)
	,m_skySourceHandle(-1)
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
	// スカイドームのロード
	m_skySourceHandle = MV1LoadModel("Data/Skydome/24-hours_SkyDome/24hours_skydome.pmx");

	// フィールドを生成
	m_fieldObj = new ObjectField(m_fieldSourceHandle);
	m_fieldObj->Initialize();
	// スカイドームを生成
	m_skyObj = new ObjectSky(m_skySourceHandle);
	m_skyObj->Initialize();

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
	MV1DeleteModel(m_skySourceHandle);
	delete (m_skyObj);

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
	// フィールドの描画
	m_fieldObj->Draw();
	// スカイドームの描画
	m_skyObj->Draw();
}
