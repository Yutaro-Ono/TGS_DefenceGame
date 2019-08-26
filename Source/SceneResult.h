//-----------------------------------------------------------+
// ���U���g�V�[��
//      : ���U���g��ʂł̏���
//                                  Last Update : 2019/07/11
//-----------------------------------------------------------+
#pragma once
#include "SceneBase.h"
#include "GameSystem.h"
#include "SoundFX.h"

class SoundFX;

class SceneResult : public SceneBase
{
public:

	SceneResult(bool in_isGameOver);
	~SceneResult();

	void Initialize() override;

	void Delete() override;

	void Update(Camera& camera, Input& input, float deltaTime) override;

	void Draw() override;

	void SetScore(const int score) { m_score = score; }          // �X�R�A�̃Z�b�^�[

	SceneBase* SceneUpdate(Input& input) override;

private:

	int toNext;

	int m_score;

	bool m_gameOver;           // �Q�[���N���A���Q�[���I�[�o�[�����肷��t���O

	SoundFX* m_bgm;         // BGM�Đ��p

};