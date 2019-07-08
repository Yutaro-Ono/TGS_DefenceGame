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

	virtual void Delete() = 0;

	virtual void Update(float deltaTime) = 0;
	virtual void Draw() = 0;

	// �|�W�V�����̃Q�b�^�[/�Z�b�^�[
	virtual const VECTOR& GetPosition() const { return m_position; };

	virtual void SetPos(const VECTOR set) { m_position = set; }

	// ���a�̎擾(�����蔻��p)
	virtual const float& GetRadius() const = 0;

protected:

	VECTOR m_position;
	VECTOR m_direction;

	float m_hitRadius;

	float m_angle;

	int m_modelHandle;

};