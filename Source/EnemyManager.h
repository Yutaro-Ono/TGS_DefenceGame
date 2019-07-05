//-----------------------------------------------------------+
// �G�l�~�[�}�l�[�W���[�N���X
//      : �G�l�~�[�̏o���`���ł��Ǘ�����N���X
//                                  Last Update : 2019/07/03
//-----------------------------------------------------------+
#pragma once
#include <iostream>
#include <vector>
#include "DxLib.h"
#include "Common.h"
#include "Actor.h"
#include "Enemy.h"

class Actor;
class Enemy;

class EnemyManager final
{
public:

	void Initialize();                  // �e�평����(���f���̓ǂݍ��݁A�o���ʒu�̐ݒ�)

	void Delete();                      // �e��������

	void Update();                      // �X�V����

	void Draw();                        // �`�揈��


private:

	int m_enemySourceHandle;            // �G�l�~�[���f���̃n���h��

	std::vector<class Enemy*> enemy;          // �G�l�~�[


	static const int ENEMY_MAX_NUM;     // �G�̈�x�ɏo������ő吔
	static const int ENEMY_ALL_NUM;     // �G�̍��v��

};
