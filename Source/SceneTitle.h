//-----------------------------------------------------------+
// �^�C�g���V�[��
//      : �^�C�g����ʂ̏���
//                                  Last Update : 2019/07/10
//-----------------------------------------------------------+
#pragma once
#include "SceneBase.h"
#include "SoundFX.h"
#include "Effect.h"

class SoundFX;
class PlayEffect;

class SceneTitle : public SceneBase
{

public:

	SceneTitle();
	~SceneTitle();

	void Initialize() override;

	void Delete() override;

	void Update(Camera& camera, Input& input, float deltaTime) override;

	void Draw(TextGraph& title) override;

	const bool& GetNextScene() const { return m_toNext; };

	// ���̃V�[���ֈړ�
	SceneBase* SceneUpdate(Input& input) override;

private:

	bool m_toNext;

	int m_alpha;                  // ���S�̓��ߕ\���p
	bool m_alphaCount;            // ���ߏ����p

	//--------------------------------------------------------------------------+
	// �摜�n���h���֌W
	//--------------------------------------------------------------------------+
	int m_titleLogoGraph;         // �^�C�g�����S�̉摜�n���h��
	int m_titleLogoW, m_titleLogoH;

	PlayEffect* m_bgEffect;       // �w�i�̃G�t�F�N�g
	SoundFX* m_bgm;               // �^�C�g���ōĐ�����BGM
	SoundFX* m_enterSE;           // ���艹

	TextGraph* m_text;
};