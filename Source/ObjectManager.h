//-----------------------------------------------------------+
// �I�u�W�F�N�g�}�l�[�W���[�N���X
//      : �I�u�W�F�N�g�̑����I�ȏ������s��
//                                  Last Update : 2019/07/01
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include <vector>
#include "Common.h"
#include "ObjectBase.h"
#include "ObjectField.h"
#include "ObjectPod.h"

class ObjectManager final
{
public:
	ObjectManager();
	~ObjectManager();

	void Initialize();
	void Delete();

	void Update();

	void Draw();

	ObjectBase* GetPodPointer() { return m_podObj; }       // ����|�b�h�̃|�C���^�Q�b�^�[

private:

	int m_fieldSourceHandle;                  // �t�B�[���h���f���̃n���h��
	int m_skySourceHandle;                    // �X�J�C�h�[���̃n���h��
	int m_podSourceHandle;                    // ����|�b�h�̃n���h��

	ObjectBase* m_fieldObj;                   // �t�B�[���h
	ObjectBase* m_skyObj;                     // ��
	ObjectBase* m_podObj;                     // ����|�b�h

};