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
//	// �v���C���[�̃��f�������[�h
//	m_modelHandle[Model::PLAYER] = MV1LoadModel("Data/Model/Player/hackadoll.pmx");
//
//	// �t�B�[���h�̃��f�������[�h
//	//m_modelHandle[Model::FIELD] = MV1LoadModel("Data/Model/Field/Field.pmx");
//
//
//
//}
//
//void ModelLoader::DeleteModel()
//{
//
//	// ���[�h�����S�Ẵ��f�����폜
//	for (int i = 0; i < Model::MODEL_ALLNUM - 1; i++)
//	{
//		if (m_modelHandle[i] != NULL)
//		{
//			MV1DeleteModel(m_modelHandle[i]);     // ���f���n���h����NULL�łȂ���΍폜
//		}
//
//		m_modelHandle[i] = NULL;
//	}
//
//}
//
//
//// ���f���̎�ނɉ����āA�n���h����Ԃ�
//ModelLoader::static int& ModelLoader::GetModelHandle(Model model)
//{
//	return m_modelHandle[model];
//}
