//-----------------------------------------------------------+
// �^�C�g���V�[��
//      : �^�C�g����ʂ̏���
//                                  Last Update : 2019/07/10
//-----------------------------------------------------------+
#pragma once
#include "SceneBase.h"
#include "SoundFX.h"

class SoundFX;

class SceneTitle : public SceneBase
{

public:

	SceneTitle();
	~SceneTitle();

	void Initialize() override;

	void Delete() override;

	void Update(Camera& camera, Input& input, float deltaTime) override;

	void Draw() override;

	const int& GetNextScene() const { return toNext; };

private:

	int toNext;

	//--------------------------------------------------------------------------+
	// �摜�n���h���֌W
	//--------------------------------------------------------------------------+
	int m_titleLogoGraph;         // �^�C�g�����S�̉摜�n���h��
	int m_titleLogoW, m_titleLogoH;

	SoundFX* m_bgm;               // �^�C�g���ōĐ�����BGM

};