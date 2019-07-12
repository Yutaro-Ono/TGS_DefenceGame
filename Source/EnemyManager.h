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
#include "Timer.h"

class Actor;
class Enemy;
class Timer;

class EnemyManager final
{
public:

	void Initialize();                  // �e�평����(���f���̓ǂݍ��݁A�o���ʒu�̐ݒ�)

	void Delete();                      // �e��������

	void Update(PlayerManager& playerManager, float deltaTime);                      // �X�V����

	void Draw();                        // �`�揈��

	void AddEnemy();                    // �G�l�~�[��ǉ�����

	// ���������G�l�~�[���Ƃ̃|�C���^���擾����
	Enemy* GetEnemyPointer(int enemyNum) { return m_enemy[enemyNum]; }
	//// �A�N�e�B�u�ȃG�l�~�[�̐���Ԃ�
	const int& GetActiveEnemy() const { size_t e_max; int num; e_max = m_enemy.size(); num = (int)e_max; return num; }

private:

	int m_enemySourceHandle;            // �G�l�~�[���f���̃n���h��

	std::vector<class Enemy*> m_enemy;          // �G�l�~�[


	static const int ENEMY_MAX_NUM;     // �G�̈�x�ɏo������ő吔
	static const int ENEMY_ALL_NUM;     // �G�̍��v��

};
