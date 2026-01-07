#include "Scene1_2.h"

void Scene1_2::Initialize() {
	from = {
		{1.0f, 0.0f, 0.0f},
		{1.0f, 0.7f, 0.5f},
		{-0.6f, 0.9f, 0.2f}
	};
	to = {
		{-1.0f, 0.0f, 0.0f},
		{-1.0f, -0.7f, -0.5f},
		{0.4f, 0.7f, -0.5f}
	};
	rotateMatrices.clear();
	for (size_t i = 0; i < from.size(); ++i) {
		rotateMatrices.push_back(DirectionToDirection(from[i], to[i]));
	}
}

void Scene1_2::Update() {
}

void Scene1_2::Draw() {
	for (size_t i = 0; i < from.size(); ++i) {
		printf({0.0f, 100.0f + float(i) * 100.0f}, from[i], "From");
		printf({400.0f, 100.0f + float(i) * 100.0f}, to[i], "To");
		printf({800.0f, 100.0f + float(i) * 100.0f}, rotateMatrices[i], "RotateMatrix");
	}
}
