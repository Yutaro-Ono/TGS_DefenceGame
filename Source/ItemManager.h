//-----------------------------------------------------------+
// �A�C�e���}�l�[�W���[�N���X
//      : �t�B�[���h��ɃA�C�e����ǉ��E�Ǘ�����N���X
//                                  Last Update : 2019/09/03
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include <stdio.h>
#include <vector>
#include "Item.h"
#include "SceneInGame.h"
#include "Timer.h"

class Item;

class ItemManager final
{
public:

	ItemManager();
	~ItemManager();

	void Initialize();

	void Delete();

	void Update(float deltaTime);

	void AddItem();

	// �����_���ȏo���ʒu�̃Q�b�^�[
	const VECTOR& GetRandomPosition(const float sizeFieldX, const float sizeFieldZ) const;
	// ���������A�C�e�����Ƃ̃|�C���^��Ԃ�
	Item* GetItemPointer(int itemNum) { return m_item[itemNum]; }
	// ���������A�C�e���̑�����Ԃ�
	const int& GetActiveItem()const { return (int)m_item.size(); }
	// ���݂̃t�B�[���h��̃A�C�e�����Q�b�^�[
	const int& GetItemOnField()const { return m_nowItem; }


private:

	int m_sourceModelHandle;                 // �A�C�e�����f���̃n���h��

	int m_nowItem;                           // �A�C�e�������o�Ă��邩

	std::vector<class Item*> m_item;         // �A�C�e��

	static const int ITEM_START_NUM;         // �J�n���̃A�C�e���̐�
	static const int ITEM_MAX;               // �A�C�e���̍ő吔

};