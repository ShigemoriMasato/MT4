#include "Scene1_4.h"

void Scene1_4::Initialize() {
	rotation = MakeRotateAxisAngleQuaternion(Vector3(1.0f, 0.4f, -0.2f).Normalize(), 0.45f);
	rotateMatrix = MakeRotationMatrix(rotation);
	rotateByQuaternion = pointY * rotation;
	rotateByMatrix = pointY * rotateMatrix;
}

void Scene1_4::Update() {

}

void Scene1_4::Draw() {
	MyPrintf({ 0, 100 }, rotation, "rotation");
	MyPrintf({ 0, 140 }, rotateMatrix, "rotateMatrix");
	MyPrintf({ 0, 300 }, rotateByQuaternion, "rotateByQuaternion");
	MyPrintf({ 0, 320 }, rotateByMatrix, "rotateByMatrix");
}
