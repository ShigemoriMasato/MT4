#include "Scene1_1.h"

void Scene1_1::Initialize() {
	axis = {1.0f, 1.0f, 1.0f};
	angle = 0.44f;
	rotateMatrix = MakeRotateAxisMatrix(angle, axis);
}

void Scene1_1::Update() {
}

void Scene1_1::Draw() {
	MyPrintf({300, 0}, rotateMatrix, "RotateMatrix");
}
