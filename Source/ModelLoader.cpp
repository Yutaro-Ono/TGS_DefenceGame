//#include "ModelLoader.h"
//
//
//
//ModelLoader::~ModelLoader()
//{
//	LoadModel();
//}
//
//void ModelLoader::LoadModel()
//{
//	// プレイヤーのモデルをロード
//	m_modelHandle[Model::PLAYER] = MV1LoadModel("Data/Model/Player/hackadoll.pmx");
//
//	// フィールドのモデルをロード
//	//m_modelHandle[Model::FIELD] = MV1LoadModel("Data/Model/Field/Field.pmx");
//
//
//
//}
//
//void ModelLoader::DeleteModel()
//{
//
//	// ロードした全てのモデルを削除
//	for (int i = 0; i < Model::MODEL_ALLNUM - 1; i++)
//	{
//		if (m_modelHandle[i] != NULL)
//		{
//			MV1DeleteModel(m_modelHandle[i]);     // モデルハンドルがNULLでなければ削除
//		}
//
//		m_modelHandle[i] = NULL;
//	}
//
//}
//
//
//// モデルの種類に応じて、ハンドルを返す
//ModelLoader::static int& ModelLoader::GetModelHandle(Model model)
//{
//	return m_modelHandle[model];
//}
