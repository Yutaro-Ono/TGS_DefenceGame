//-----------------------------------------------------------+
// ���U���g�V�[��
//      : ���U���g��ʂł̏���
//                                         2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "SceneBase.h"
#include "GameSystem.h"
#include "SoundFX.h"

// �N���X�O���錾
class SoundFX;

class SceneResult : public SceneBase
{

public:

	SceneResult(bool in_isGameOver, int in_score);                                // �R���X�g���N�^
	~SceneResult();                                                               // �f�X�g���N�^

	void Initialize() override;                                                   // ����������
	void Delete() override;                                                       // �������

	void Update(Camera& camera, Input& input, float deltaTime) override;          // �X�V����
	void Draw(TextGraph& text) override;                                          // �`�揈��

	//--------------------------------------------------------------------------------+
	// Getter/Setter �֘A
	//--------------------------------------------------------------------------------+
	// �X�R�A�̃Z�b�^�[
	void SetScore(const int score) { m_score = score; }
	// �V�[�����X�V���ꂽ���ǂ������擾
	SceneBase* SceneUpdate(Input& input) override;


private:

	int          toNext;          // ���̃V�[���ւ̃t���O
	int         m_score;          // �X�R�A
	bool     m_gameOver;          // �Q�[���N���A���Q�[���I�[�o�[�����肷��t���O

	SoundFX*      m_bgm;          // BGM�Đ��p

};