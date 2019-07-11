#pragma once
#include "SceneBase.h"
#include "GameSystem.h"

class SceneResult : public SceneBase
{
public:

	SceneResult();
	~SceneResult();

	void Initialize() override;

	void Delete() override;

	void Update(Input& input, Camera& camera, float deltaTime) override;

	void Draw() override;

	void SetScore(const int score) { m_score = score; }          // �X�R�A�̃Z�b�^�[

	const int& GetNextScene() const { return toNext; }           // ���̃V�[���ւ̃Z�b�^�[

private:

	int toNext;

	int m_score;


};