//-----------------------------------------------------------+
// �l�X�ȃX�P�[�����O�����o����N���X
//      : �摜�̃T�C�Y�̊g��k���Ȃǂ���ɒS������
//                                  Last Update : 2019/08/04
//-----------------------------------------------------------+
#pragma once
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

	int m_graphScale;             // �摜�T�C�Y

};