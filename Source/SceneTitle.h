//-----------------------------------------------------------+
// �^�C�g���V�[��
//      : �^�C�g����ʂ̏���
//                                  Last Update : 2019/07/10
//-----------------------------------------------------------+
#pragma once
#include "SceneBase.h"


class SceneTitle : public SceneBase
{

public:

	SceneTitle();
	~SceneTitle();

	void Initialize() override;

	void Delete() override;

	void Update(Input& input, Camera& camera, float deltaTime) override;

	void Draw() override;

	const int& GetNextScene() const { return toNext; };

private:

	int toNext;

};