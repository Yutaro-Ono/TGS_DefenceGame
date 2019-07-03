//-----------------------------------------------------------+
// �G�l�~�[�}�l�[�W���[�N���X
//      : �G�l�~�[�̏o���`���ł��Ǘ�����N���X
//                                  Last Update : 2019/07/03
//-----------------------------------------------------------+
#pragma once
#include <iostream>
#include <vector>
#include "DxLib.h"
#include "Enemy.h"


class EnemyManager final
{
public:

	void Initialize();                  // �e�평����(���f���̓ǂݍ��݁A�o���ʒu�̐ݒ�)

	void Delete();                      // �e��������

	void Update();                      // �X�V����

	void Draw();                        // �`�揈��


private:

	int m_enemySourceHandle;            // �G�l�~�[���f���̃n���h��

	std::vector<Actor*> enemy;


	static const int MAX_ENEMY_NUM;     // �G�̈�x�ɏo������ő吔


};
