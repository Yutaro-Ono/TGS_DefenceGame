////-------------------------------------------------------------//
////
//// ���f�����Ǘ�(���[�h�E�f���[�g)�N���X
////
////-----------------------------------------------------------//
//#pragma once
//#include "DxLib.h"
//#include <iostream>
//#include <map>
//
//#define STR(var) #var    // �����𕶎��񃊃e�����Ƃ��ĕԂ��}�N���֐�
//
//class ModelLoader final
//{
//public:
//
//	// ���f���̎�ނƍő吔
//	enum MODEL
//	{
//		PLAYER,
//		ENEMY,
//		FIELD,
//		ITEM,
//		MODEL_ALLNUM,
//	};
//
//	// �v���C���[���f���̎��
//	enum MODEL_PLAYER
//	{
//		MAIN,
//	};
//
//	// �G�l�~�[���f���̎��
//	enum MODEL_ENEMY
//	{
//		MAIN,
//	};
//
//	// �t�B�[���h���f���̎��
//	enum MODEL_FIELD
//	{
//		STAGE,
//		SKYDOME,
//
//	};
//
//	// �A�C�e�����f���̎��
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
//	// �V���O���g��
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