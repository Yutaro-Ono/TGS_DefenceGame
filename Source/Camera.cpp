//-----------------------------------------------------------------------+
// カメラクラス                                 
//                                              Last Update : 2019/07/01
//-----------------------------------------------------------------------+
#include "Camera.h"
#include "PlayerManager.h"
#include "Actor.h"

#define USE_LERP_CAMERA 1

// コンストラクタ
Camera::Camera()
{
	//奥行0.1～1000までをカメラの描画範囲とする
	SetCameraNearFar(1.0f, 200.0f);

	pos = VGet(0, 40, -100);
}

// デストラクタ
Camera::~Camera()
{
	// 処理なし
}

// 更新
void Camera::Update(PlayerManager& playerManager)
{
	// プレイヤーマネージャー内のプレイヤーにアクセス
	Actor* player = playerManager.GetPlayerPointer();

	SetCameraPositionAndAngle(pos, DX_PI / 30.0f, 0, 0);

//#if !USE_LERP_CAMERA
//	// z軸上で、プレイヤーから一定距離離れた状態でプレイヤーを常に見続けるよう位置調整
//	pos = VGet(0, player->GetPosition().y + 20.0f, player->GetPosition().z - 30.0f);
//#else
//	// lerpを使用して実装.
//	// lerp(VECTOR a, VECTOR b, float t)は
//	// answer = a + ((b-a) * t)
//	VECTOR aimPos = VGet(0, player->GetPosition().y + 20.0f, player->GetPosition().z - 30.0f);
//	VECTOR posToAim = VSub(aimPos, pos);
//	VECTOR scaledPosToAim = VScale(posToAim, 0.1f);
//	pos = VAdd(pos, scaledPosToAim);
//#endif
//	// カメラに位置を反映.
//	SetCameraPositionAndTarget_UpVecY(pos, player->GetPosition());
//	//printfDx("pos : x = %f\ny = %f\nz = %f\n", pos.x, pos.y, pos.z);
}