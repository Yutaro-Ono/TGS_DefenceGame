//-----------------------------------------------------------+
// ���U���g�V�[��
//      : ���U���g��ʂł̏���
//                                  Last Update : 2019/09/03
//-----------------------------------------------------------+
#pragma once
#include "SceneBase.h"
#include "GameSystem.h"
#include "SoundFX.h"

class SoundFX;

class SceneResult : public SceneBase
{
public:

	SceneResult(bool in_isGameOver, int in_score);
	~SceneResult();

	void Initialize() override;

	void Delete() override;

	void Update(Camera& camera, Input& input, float deltaTime) override;

	void Draw(TextGraph& text) override;

	void SetScore(const int score) { m_score = score; }          // �X�R�A�̃Z�b�^�[

	SceneBase* SceneUpdate(Input& input) override;

private:

	int toNext;                    // ���̃V�[���ւ̃t���O

	int m_score;                   // �X�R�A

	bool m_gameOver;               // �Q�[���N���A���Q�[���I�[�o�[�����肷��t���O

	SoundFX* m_bgm;                // BGM�Đ��p

};