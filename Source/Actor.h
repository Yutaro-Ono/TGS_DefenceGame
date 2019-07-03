//----------------------------------------------------------------------+
// �A�N�^�[���N���X
//      : �A�N�^�[(�ړ�����I�u�W�F�N�g�C�L�����N�^�[)
//                                             Last Update : 2019/07/01
//----------------------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "ObjectBase.h"
class Actor
{
public:
	Actor(const int sourceModelHandle);
	virtual ~Actor();

	virtual void Initialize() = 0;

	virtual void Update() = 0;
	void Draw();

	// �|�W�V�����̃Q�b�^�[/�Z�b�^�[
	const VECTOR& GetPosition() const { return m_position; };
	void SetPos(const VECTOR set) { m_position = set; }
	// ���a�̎擾(�����蔻��p)
	float GetRadius() const { return m_radius; }

protected:

	VECTOR m_position;
	VECTOR m_direction;
	float m_radius;

	int m_modelHandle;

};