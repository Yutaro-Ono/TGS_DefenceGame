//-----------------------------------------------------------+
// �^�C�g���V�[��
//      : �^�C�g����ʂ̏���
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "SceneBase.h"
#include "SoundFX.h"
#include "Effect.h"

// �N���X�O���錾
class SoundFX;
class PlayEffect;

class SceneTitle : public SceneBase
{

public:

	SceneTitle();                                                                 // �R���X�g���N�^
	~SceneTitle();                                                                // �f�X�g���N�^

	void Initialize() override;                                                   // ����������
	void Delete() override;                                                       // �������

	void Update(Camera& camera, Input& input, float deltaTime) override;          // �X�V����
	void Draw(TextGraph& title) override;                                         // �`�揈��

	int SceneTransEffect(int in_alpha);                                           // �V�[���@�ۂ̃t�F�[�h�G�t�F�N�g

	const bool& GetNextScene() const { return m_toNext; };                        // ���̃V�[���ֈڍs����t���O��Ԃ�
	SceneBase* SceneUpdate(Input& input) override;                                // ���̃V�[���ֈڍs���鏈��


private:

	bool m_toNext;                // ���̃V�[���ֈڍs����t���O

	unsigned int m_logoAlpha;                  // ���S�̓��ߕ\���p
	unsigned int m_screenAlpha;                // ��ʂ̓��ߕ\���p

	bool m_alphaCount;            // ���ߏ����p

	//--------------------------------------------------------------------------+
	// �摜�n���h���֌W
	//--------------------------------------------------------------------------+
	int m_titleLogoGraph;            // �^�C�g�����S�̉摜�n���h��
	int m_titleLogoW;                // �^�C�g�����S�摜�̉����T�C�Y
	int m_titleLogoH;                // �^�C�g�����S�摜�̏c���T�C�Y

	PlayEffect* m_bgEffect;          // �w�i�̃G�t�F�N�g
	SoundFX* m_bgm;                  // �^�C�g���ōĐ�����BGM
	SoundFX* m_enterSE;              // ���艹
	TextGraph* m_text;               // �`��p�e�L�X�g�t�H���g

};