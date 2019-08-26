//-----------------------------------------------------------+
// �I�u�W�F�N�g���N���X
//      : �I�u�W�F�N�g�֘A(��Ƀt�B�[���h�\����)
//                                  Last Update : 2019/07/01
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "ModelLoader.h"

class ObjectBase
{
public:
	ObjectBase(int sourceModelHandle);
	virtual ~ObjectBase();

	virtual void Initialize() = 0;

	virtual void Update(float deltaTime) = 0;

	virtual void Draw();

	// �|�W�V�����̃Q�b�^�[/�Z�b�^�[
	const VECTOR& GetPosition() const { return m_position; };
	void SetPos(const VECTOR set) { m_position = set; }
	// ���a�̎擾(�����蔻��p)
	const float& GetRadius() const{ return m_radius; }

protected:

	VECTOR m_position;
	VECTOR m_direction;
	float m_radius;

	int m_modelHandle;

};