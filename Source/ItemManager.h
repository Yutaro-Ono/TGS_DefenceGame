//-----------------------------------------------------------+
// �A�C�e���}�l�[�W���[�N���X
//      : �t�B�[���h��ɃA�C�e����ǉ��E�Ǘ�����N���X
//                                  Last Update : 2019/07/25
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include <vector>
#include "Item.h"

class Item;

class ItemManager final
{
public:

	ItemManager();
	~ItemManager();

	void Initialize();

	void Delete();

	void Update(float deltaTime);

	void Draw();

	void AddItem();

	// �����_���ȏo���ʒu�̃Q�b�^�[
	const VECTOR& GetRandomPosition() const;

private:

	int m_sourceModelHandle;                 // �A�C�e�����f���̃n���h��

	std::vector<class Item*> m_item;         // �A�C�e��

	int m_numOnField;                        // ���݂̃t�B�[���h��ɂ���A�C�e���̑���

	static const int ITEM_MAX;               // �A�C�e���̍ő吔

};