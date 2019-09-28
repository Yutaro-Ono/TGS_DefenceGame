//-----------------------------------------------------------------------+
// �C���^�[�t�F�[�X(�v���C���[�X�e�[�^�X)�N���X                                     
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "InterfaceBase.h"
#include "InGameUIManager.h"
#include "Score.h"
#include "Player.h"
#include "TextGraph.h"
#include "Timer.h"

// �N���X�O���錾
class TextGraph;
class Timer;

class InterfacePlayer : public InterfaceBase
{

public:

	InterfacePlayer();                                   // �R���X�g���N�^
	~InterfacePlayer();                                  // �f�X�g���N�^

	void Initialize() override;                          // ����������

	void Delete();                                       // �������

	void Update() override;                              // �X�V����

	void Update(Player& player);                         // �X�V����(�v���C���[�ǐ�)

	void Draw(Player& player, TextGraph& text);          // �`�揈��


private:

	VECTOR m_stockPosition;          // �A�C�e���X�g�b�N��UI�̍��W
	VECTOR m_scorePosition;          // �X�R�A�̍��W

	int m_holdItem;                  // �X�R�A�A�C�e��������

	int hpGauge[5];                  // HP�Q�[�W
	int hpFrame;                     // HP�Q�[�W�t���[��

};