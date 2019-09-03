//-----------------------------------------------------------+
// �Q�[�����ɂ�����C���^�[�t�F�[�X�����N���X
//      : �Q�[�����ɕ\������C���^�[�t�F�[�X�̑����I�ȏ������s��
//                                  Last Update : 2019/07/28
//-----------------------------------------------------------+
#pragma once
#include "InterfacePlayer.h"
#include "Score.h"
#include "Actor.h"
#include "Player.h"
#include "PlayerManager.h"
#include "GameSystem.h"
#include "TextGraph.h"

class Player;
class InterfacePlayer;
class TextGraph;
class Score;

class InGameUIManager final
{
public:

	InGameUIManager();
	~InGameUIManager();

	void Initialize();                  // �e�평����

	void Delete();                      // �e��폜����

	void Update(Player& player);        // �X�V����

	void Draw(Player& player, TextGraph& text);          // �`�揈��

	// �X�R�A�̃Q�b�^�[
	const int& GetScore()const { return m_nowScore; }


private:

	int m_tutorialGraph;               // �`���[�g���A���̉摜�n���h��

	int m_nowScore;                       // ���݂̃X�R�A

	InterfacePlayer* m_playerUI;       // �v���C���[��UI
	Score* m_score;                    // �X�R�A
};