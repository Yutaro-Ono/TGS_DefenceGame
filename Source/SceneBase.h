//-----------------------------------------------------------+
// �V�[�����N���X
//      : �e�V�[���̊��N���X�B���ʏ������s��
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "DxLib.h"
#include "TextGraph.h"

// �N���X�O���錾
class Camera;
class Input;
class TextGraph;

class SceneBase
{

public:

	SceneBase();                                                                     // �R���X�g���N�^
	virtual ~SceneBase();                                                            // �f�X�g���N�^

	virtual void Initialize() = 0;                                                   // ����������

	virtual void Delete() = 0;                                                       // �������

	virtual void Update(Camera& camera, Input& input, float deltaTime) = 0;          // �X�V����

	virtual void Draw(TextGraph& text) = 0;                                          // �`�揈��

	//--------------------------------------------------------------------------------+
	// Getter/Setter �֘A
	//--------------------------------------------------------------------------------+
	// �V�[�����X�V���ꂽ���ǂ����̎擾
	virtual SceneBase* SceneUpdate(Input& input) = 0;

};