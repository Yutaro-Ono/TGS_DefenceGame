//-----------------------------------------------------------+
// �A�C�h��(��q�Ώ�)�N���X
//      : �A�C�h���̌ŗL����
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "DxLib.h"
#include "Actor.h"
#include "HitChecker.h"

class Idol : public Actor
{

public:

	Idol(int sourceModelHandle);                    // �R���X�g���N�^
	~Idol() {};                                     // �f�X�g���N�^

	void Initialize() override;                     // ����������
	void Delete() override;                         // �������

	void Update(float deltaTime) override;          // �X�V����
	void Draw()override;                            // �`�揈��

	//--------------------------------------------------------------------------+
    // Getter/Setter �֘A
    //--------------------------------------------------------------------------+
	// ���a�̎擾
	const float& GetRadius()const { return m_hitRadius; }


private:

	static const VECTOR SCALE_SIZE;          // ���f���̊g�嗦

};