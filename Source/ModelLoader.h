////-------------------------------------------------------------//
////
//// モデル情報管理(ロード・デリート)クラス
////
////-----------------------------------------------------------//
//#pragma once
//#include "DxLib.h"
//#include <iostream>
//#include <map>
//
//#define STR(var) #var    // 引数を文字列リテラルとして返すマクロ関数
//
//class ModelLoader final
//{
//public:
//
//	// モデルの種類と最大数
//	enum MODEL
//	{
//		PLAYER,
//		ENEMY,
//		FIELD,
//		ITEM,
//		MODEL_ALLNUM,
//	};
//
//	// プレイヤーモデルの種類
//	enum MODEL_PLAYER
//	{
//		MAIN,
//	};
//
//	// エネミーモデルの種類
//	enum MODEL_ENEMY
//	{
//		MAIN,
//	};
//
//	// フィールドモデルの種類
//	enum MODEL_FIELD
//	{
//		STAGE,
//		SKYDOME,
//
//	};
//
//	// アイテムモデルの種類
//	enum MODEL_ITEM
//	{
//		SCORE,
//		CURE,
//	};
//
//
//private:
//	ModelLoader();
//
//	void LoadModel();
//
//
//	void DeleteModel();
//
//	const int& GetModelNum(int in_num) { return MODEL::in_num; };
//
//	const char GetModel(const char* in_fileName, int in_num);
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
//	std::map<std::string, int> m_modelHandle;
//
//	static const std::string 
//
//};
//
//#define MODEL_LOAD ModelLoader::GetInstance()