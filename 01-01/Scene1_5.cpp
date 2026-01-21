#include "Scene1_5.h"

void Scene1_5::Initialize() {
	rotation0 = MakeRotateAxisAngleQuaternion(Vector3(0.71f, 0.71f, 0.0f).Normalize(), 0.3f);
	rotation1 = MakeRotateAxisAngleQuaternion(Vector3(0.71f, 0.0f, 0.71f).Normalize(), 3.141592f);

	interpolate0 = Slerp(rotation0, rotation1, 0.0f);
	interpolate1 = Slerp(rotation0, rotation1, 0.3f);
	interpolate2 = Slerp(rotation0, rotation1, 0.5f);
	interpolate3 = Slerp(rotation0, rotation1, 0.7f);
	interpolate4 = Slerp(rotation0, rotation1, 1.0f);
}

void Scene1_5::Update() {
}

void Scene1_5::Draw() {
	float posY = 100.0f;
	MyPrintf({ 0, posY }, interpolate0, "interpolate0, Slerp(q0, q1, 0.0f)");;
	posY += 20.0f;
	MyPrintf({ 0, posY }, interpolate1, "interpolate1, Slerp(q0, q1, 0.3f)");;
	posY += 20.0f;
	MyPrintf({ 0, posY }, interpolate2, "interpolate2, Slerp(q0, q1, 0.5f)");;
	posY += 20.0f;
	MyPrintf({ 0, posY }, interpolate3, "interpolate3, Slerp(q0, q1, 0.7f)");;
	posY += 20.0f;
	MyPrintf({ 0, posY }, interpolate4, "interpolate4, Slerp(q0, q1, 1.0f)");;
}
