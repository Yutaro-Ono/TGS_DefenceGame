//-----------------------------------------------------------+
// �l�X�ȃX�P�[�����O�����o����N���X
//      : �摜�̃T�C�Y�̊g��k���Ȃǂ���ɒS������
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "DirectorBase.h"

class DirectorScaler : public DirectorBase
{

public:

	DirectorScaler();                     // �R���X�g���N�^
	~DirectorScaler();                    // �f�X�g���N�^

	void Initialize() override;           // �e�평��������
	void Delete() override;               // �e��������

	// �摜�̊g��k�����o
	void Zoomer(const int in_graphSize, const int in_maxSize, const int in_miniSize, float deltaTime);

	// �摜�T�C�Y�̃Q�b�^�[
	const int& GetGraphScale() const { return m_graphScale; }

private:

	int     m_graphScale;          // �摜�T�C�Y

};