////-------------------------------------------------------------//
////
//// ���f�����Ǘ�(���[�h�E�f���[�g)�N���X
////
////-----------------------------------------------------------//
//#pragma once
//#include "DxLib.h"
//
//class ModelLoader final
//{
//public:
//
//	// ���f���̎�ނƍő吔
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
//	// �V���O���g��
//	static ModelLoader& GetInstance()
//	{
//		static ModelLoader loader;
//		return loader;
//	}
//
//	~ModelLoader();
//
//	static int& GetModelHandle(Model model);    // �v�����ꂽ���f���̎�ނɉ����ăn���h����Ԃ�
//
//
//
//};
//
//#define MODEL_LOAD ModelLoader::GetInstance()