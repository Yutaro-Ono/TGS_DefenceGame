////-------------------------------------------------------------//
////
//// モデル情報管理(ロード・デリート)クラス
////
////-----------------------------------------------------------//
//#pragma once
//#include "DxLib.h"
//
//class ModelLoader final
//{
//public:
//
//	// モデルの種類と最大数
//	enum Model
//	{
//		PLAYER = 0,
//		FIELD,
//		OBJECT,
//		MODEL_ALLNUM,
//	};
//
//
//private:
//	ModelLoader();
//
//	void LoadModel();
//
//	void DeleteModel();
//
//	int m_modelHandle[MODEL_ALLNUM];
//
//public:
//
//	// シングルトン
//	static ModelLoader& GetInstance()
//	{
//		static ModelLoader loader;
//		return loader;
//	}
//
//	~ModelLoader();
//
//	static int& GetModelHandle(Model model);    // 要求されたモデルの種類に応じてハンドルを返す
//
//
//
//};
//
//#define MODEL_LOAD ModelLoader::GetInstance()