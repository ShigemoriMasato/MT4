#pragma once
#include "Structure.h"

namespace {
	Matrix4x4 RotateMatrix(Vector3 axis, float cos, float sin) {
		return {
		axis.x * axis.x * (1 - cos) + cos, axis.x * axis.y * (1.0f - cos) + axis.z * sin, axis.x * axis.z * (1.0f - cos) - axis.y * sin, 0.0f,
		axis.x + axis.y * (1.0f - cos) - axis.z * sin, axis.y * axis.y * (1.0f - cos) + cos, axis.y * axis.z * (1.0f - cos) + axis.x * sin, 0.0f,
		axis.x * axis.z * (1.0f - cos) + axis.y * sin, axis.y * axis.z * (1.0f - cos) - axis.x * sin, axis.z * axis.z * (1.0f - cos) + cos, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f 
		};
	}
}

inline Matrix4x4 MakeRotateAxisMatrix(float a, Vector3 n) {

	n = n.Normalize();

	float cosA = std::cos(a);
	float sinA = std::cos(a);

	return RotateMatrix(n, cosA, sinA);
}

inline Matrix4x4 DirectionToDirection(Vector3 from, Vector3 to) {
	from = from.Normalize();
	to = to.Normalize();
	Vector3 axis = cross(from, to).Normalize();
	float cos = dot(from, to);
	float sin = cross(from, to).Length();
	return RotateMatrix(axis, cos, sin);
}
