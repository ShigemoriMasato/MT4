#include "Scene1_3.h"

void Scene1_3::Initialize() {
	q1 = { 2.0f, 3.0f, 4.0f, 1.0f };
	q2 = { 1.0f, 3.0f, 5.0f, 2.0f };
}

void Scene1_3::Update() {
}

void Scene1_3::Draw() {
	Vector2 offset = { 0.0f, 100.0f };
	MyPrintf(offset, Quaternion::Identity(), "Identity");
	offset.y += 40.0f;
	MyPrintf(offset, q1.Conjugate(), "Conjugate");
	offset.y += 40.0f;
	MyPrintf(offset, q1.Inverse(), "Inverse");
	offset.y += 40.0f;
	MyPrintf(offset, q1.Normalize(), "Normalize");
	offset.y += 40.0f;
	MyPrintf(offset, q1 * q2, "Multiply(q1 * q2)");
	offset.y += 40.0f;
	MyPrintf(offset, q2 * q1, "Multiply(q2 * q1)");
	offset.y += 40.0f;
	MyPrintf(offset, q1.Norm(), "Norm");
}
