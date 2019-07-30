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

	void Delete();

	void Update(Player& player);

	void Draw();

	//--------------------------------------------------------+
    // Getter/Setter �֘A
    //--------------------------------------------------------+
	// �X�R�A�̃Q�b�^�[
	const int& GetScore() const { return m_score; }

private:

	int m_score;                        // �X�R�A

	int m_holdScore;                    // �������̃X�R�A

	static const int SCORE_POINT;       // �X�R�A�|�C���g(���Z�p)
	static const double SCORE_MULTIPLE[6];                // �����A�C�e�����ɂ��X�R�A�l���{��
};