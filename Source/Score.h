//-----------------------------------------------------------+
// �X�R�A�N���X
//      : �X�R�A�̉��Z��`��Ȃǂ��Ǘ�����N���X
//                                  Last Update : 2019/07/28
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "PlayerManager.h"

class Score final
{
public:

	Score();
	~Score();

	void Initialize();

	void Update();

	void Draw();

	//--------------------------------------------------------+
    // Getter/Setter �֘A
    //--------------------------------------------------------+
	// �X�R�A�̃Q�b�^�[
	const int& GetScore() const { return m_score; }
	// �X�R�A�̃Z�b�^�[
	void SetScore(const int score) { m_score = SCORE_POINT * score; }

private:

	int m_score;                        // �X�R�A

	static const int SCORE_POINT;       // �X�R�A�|�C���g(���Z�p)
};