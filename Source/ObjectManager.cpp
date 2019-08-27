//-----------------------------------------------------------------------+
// オブジェクトマネージャークラス                                    
//                                              Last Update : 2019/07/02
//-----------------------------------------------------------------------+
#include "ObjectManager.h"
#include "ObjectField.h"
#include "ObjectSky.h"
#include "ObjectVisibleWall.h"


// コンストラクタ
ObjectManager::ObjectManager()
	:m_fieldSourceHandle(-1)
	,m_skySourceHandle(-1)
	,m_podSourceHandle(-1)
{

}

// デストラクタ
ObjectManager::~ObjectManager()
{
}

// 各種初期化
void ObjectManager::Initialize()
{
	// フィールドモデルのロード
	m_fieldSourceHandle = MV1LoadModel("Data/Model/Field/Field/Field_Plate.mv1");
	// スカイドームのロード
	m_skySourceHandle = MV1LoadModel("Data/Skydome/Universe/Universe_Blue_ver.mv1");
	// 回収ポッドのモデルロード
	m_podSourceHandle = MV1LoadModel("Data/Model/Field/Collect_Pod/CollectPod.mv1");

	if (m_podSourceHandle == -1)
	{
		printfDx("ポッドのモデルがロードできていません");
	}

	// フィールドを生成
	m_fieldObj = new ObjectField(m_fieldSourceHandle);
	m_fieldObj->Initialize();
	// スカイドームを生成
	m_skyObj = new ObjectSky(m_skySourceHandle);
	m_skyObj->Initialize();
	// 回収ポッドを生成
	m_podObj = new ObjectPod(m_podSourceHandle);
	m_podObj->Initialize();
}

// 各種解放処理
void ObjectManager::Delete()
{
	// モデルの削除
	MV1DeleteModel(m_fieldSourceHandle);
	MV1DeleteModel(m_skySourceHandle);
	MV1DeleteModel(m_podSourceHandle);
	// インスタンスを破棄
	delete (m_fieldObj);
	delete (m_skyObj);
	delete (m_podObj);
}

// 更新処理
void ObjectManager::Update(float deltaTime)
{
	m_fieldObj->Update(deltaTime);
	m_podObj->Update(deltaTime);
}

// 描画処理
void ObjectManager::Draw()
{
	// スカイドームの描画
	m_skyObj->Draw();

	

	// フィールドの描画
	m_fieldObj->Draw();
	// 回収ポッドの描画
	m_podObj->Draw();
}
