//-----------------------------------------------------------+
// �Q�[�����ɂ�����C���^�[�t�F�[�X�����N���X
//      : �Q�[�����ɕ\������C���^�[�t�F�[�X�̑����I�ȏ������s��
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "InterfacePlayer.h"
#include "Score.h"
#include "Actor.h"
#include "Player.h"
#include "PlayerManager.h"
#include "GameSystem.h"
#include "TextGraph.h"

// �N���X�O���錾
class Player;
class InterfacePlayer;
class TextGraph;
class Score;

class InGameUIManager final
{

public:

	InGameUIManager();                                         // �R���X�g���N�^
	~InGameUIManager();                                        // �f�X�g���N�^

	void Initialize();                                         // �e�평����
	void Delete();                                             // �e��폜����

	void Update(Player& player);                               // �X�V����
	void Draw(Player& player, TextGraph& text);                // �`�揈��

	const int& GetScore()const { return m_nowScore; }          // �X�R�A�̃Q�b�^�[


private:

	int m_tutorialGraph;                  // �`���[�g���A���̉摜�n���h��

	int m_nowScore;                       // ���݂̃X�R�A

	InterfacePlayer* m_playerUI;          // �v���C���[��UI
	Score* m_score;                       // �X�R�A

};