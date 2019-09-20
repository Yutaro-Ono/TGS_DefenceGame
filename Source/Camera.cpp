//-----------------------------------------------------------------------+
// カメラクラス                                 
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+

// インクルードファイル
#include "Camera.h"
#include "PlayerManager.h"
#include "Actor.h"

// クラス前方宣言
class PlayerManager;

#define USE_LERP_CAMERA 0        // Lerpを使用するかしないか

// コンストラクタ
Camera::Camera()
{
	//奥行0.1～1000までをカメラの描画範囲とする
	SetCameraNearFar(1.0f, 40000.0f);
	// ポジションの設定
	m_position = VGet(0.0f, 115.0f, -120.0f);
}

// デストラクタ
Camera::~Camera()
{
	// 処理なし
}

// 更新処理
void Camera::Update(PlayerManager& playerManager)
{
	// プレイヤーマネージャー内のプレイヤーにアクセス
	Actor* player = playerManager.GetPlayerPointer();

	SetCameraPositionAndAngle(m_position, 50.0f * DX_PI_F / 180.0f, 0, 0);

//#if !USE_LERP_CAMERA
//	// z軸上で、プレイヤーから一定距離離れた状態でプレイヤーを常に見続けるよう位置調整
//	m_position = VGet(0, 10.0f, player->GetPosition().z - 30.0f);
//#else
//	// lerpを使用して実装.
//	// lerp(VECTOR a, VECTOR b, float t)は
//	// answer = a + ((b-a) * t)
//	VECTOR aimPos = VGet(0, player->GetPosition().y + 20.0f, player->GetPosition().z - 30.0f);
//	VECTOR posToAim = VSub(aimPos, m_position);
//	VECTOR scaledPosToAim = VScale(posToAim, 0.1f);
//	pos = VAdd(pos, scaledPosToAim);
//#endif
//	// カメラに位置を反映.
//	SetCameraPositionAndTarget_UpVecY(m_position, VGet(player->GetPosition().x, 0.0f, player->GetPosition().y));
//	//printfDx("pos : x = %f\ny = %f\nz = %f\n", pos.x, pos.y, pos.z);
}