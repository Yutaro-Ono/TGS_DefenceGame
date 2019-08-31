//-----------------------------------------------------------+
// �X�R�A�N���X
//      : �X�R�A�̉��Z��`��Ȃǂ��Ǘ�����N���X
//                                  Last Update : 2019/07/28
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "PlayerManager.h"
#include "TextGraph.h"
#include "Timer.h"

class TextGraph;
class Timer;

class Score final
{
public:

	Score();
	~Score();

	void Initialize();

	void Delete();

	void Update(Player& player);

	void Draw(TextGraph& text);

	void DrawAddScore(TextGraph& text);

	//--------------------------------------------------------+
    // Getter/Setter �֘A
    //--------------------------------------------------------+
	// �X�R�A�̃Q�b�^�[
	const int& GetScore() const { return m_score; }
	// �X�R�A���Z�t���O�̃Q�b�^�[
	const bool& GetAddScore() const { return m_addScore; }


private:

	//----------------------------------------------------------------------------------//
	// �X�R�A�\���p
	//---------------------------------------------------------------------------------//
	VECTOR m_scorePosition;             // �X�R�A�̃|�W�V����
	int m_score;                        // �X�R�A
	int m_holdScore;                    // �������̃X�R�A	


	//---------------------------------------------------------------------------------//
	// �X�R�A���Z�̕\���֘A
	//--------------------------------------------------------------------------------//
	VECTOR m_addPosition;                     // �擾�����X�R�A�̍��W
	int m_addScoreVal;                        // �X�R�A���Z��
	bool m_addScore;                         // �X�R�A�����Z���ꂽ���ǂ���

	Timer* m_timer;                          // �^�C�}�[

	static const int SCORE_POINT;       // �X�R�A�|�C���g(���Z�p)
	static const double SCORE_MULTIPLE[6];                // �����A�C�e�����ɂ��X�R�A�l���{��
};