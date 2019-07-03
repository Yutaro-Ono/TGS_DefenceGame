//-----------------------------------------------------------------------+
// �J�����N���X                                 
//                                              Last Update : 2019/07/01
//-----------------------------------------------------------------------+
#include "Camera.h"
#include "PlayerManager.h"
#include "Actor.h"

class PlayerManager;

#define USE_LERP_CAMERA 1        // Lerp���g�p���邩���Ȃ���

// �R���X�g���N�^
Camera::Camera()
{
	//���s0.1�`1000�܂ł��J�����̕`��͈͂Ƃ���
	SetCameraNearFar(1.0f, 40000.0f);
	// �|�W�V�����̐ݒ�
	pos = VGet(0.0f, 90.0f, -130.0f);
}

// �f�X�g���N�^
Camera::~Camera()
{
	// �����Ȃ�
}

// �X�V
void Camera::Update(PlayerManager& playerManager)
{
	// �v���C���[�}�l�[�W���[���̃v���C���[�ɃA�N�Z�X
	Actor* player = playerManager.GetPlayerPointer();

	SetCameraPositionAndAngle(pos, 30.0f * DX_PI_F / 180.0f, 0, 0);

//#if !USE_LERP_CAMERA
//	// z����ŁA�v���C���[�����苗�����ꂽ��ԂŃv���C���[����Ɍ�������悤�ʒu����
//	pos = VGet(0, player->GetPosition().y + 20.0f, player->GetPosition().z - 30.0f);
//#else
//	// lerp���g�p���Ď���.
//	// lerp(VECTOR a, VECTOR b, float t)��
//	// answer = a + ((b-a) * t)
//	VECTOR aimPos = VGet(0, player->GetPosition().y + 20.0f, player->GetPosition().z - 30.0f);
//	VECTOR posToAim = VSub(aimPos, pos);
//	VECTOR scaledPosToAim = VScale(posToAim, 0.1f);
//	pos = VAdd(pos, scaledPosToAim);
//#endif
//	// �J�����Ɉʒu�𔽉f.
//	SetCameraPositionAndTarget_UpVecY(pos, player->GetPosition());
//	//printfDx("pos : x = %f\ny = %f\nz = %f\n", pos.x, pos.y, pos.z);
}