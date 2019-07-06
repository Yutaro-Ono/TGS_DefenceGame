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
#include "ObjectVisibleWall.h"

#define OBJECT_NUM_W 5
#define OBJECT_NUM_H 5

class ObjectVisibleWall;

class ObjectManager final
{
public:
	ObjectManager();
	~ObjectManager();

	void Initialize();
	void Delete();

	void Update();

	void Draw();

private:

	int m_fieldSourceHandle;                  // �t�B�[���h���f���̃n���h��
	int m_skySourceHandle;                    // �X�J�C�h�[���̃n���h��
									
	//std::vector<ObjectVisibleWall*> m_visibleWall;        // �����Ȃ���

	ObjectBase* m_fieldObj;                   // �t�B�[���h
	ObjectBase* m_skyObj;                     // ��

	static const int WALL_NUM;

	ObjectBase* m_object[OBJECT_NUM_H][OBJECT_NUM_W];
};