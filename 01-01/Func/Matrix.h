#pragma once
#include "Structure.h"

namespace {
	Matrix4x4 RotateMatrix(Vector3 axis, float cos, float sin) {
		float oneMinusCos = 1.0f - cos;
		return {
		axis.x * axis.x * oneMinusCos + cos, axis.x * axis.y * oneMinusCos + axis.z * sin, axis.x * axis.z * oneMinusCos - axis.y * sin, 0.0f,
		axis.x * axis.y * oneMinusCos - axis.z * sin, axis.y * axis.y * oneMinusCos + cos, axis.y * axis.z * oneMinusCos + axis.x * sin, 0.0f,
		axis.x * axis.z * oneMinusCos + axis.y * sin, axis.y * axis.z * oneMinusCos - axis.x * sin, axis.z * axis.z * oneMinusCos + cos, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f 
		};
	}
}

inline Matrix4x4 MakeRotateAxisMatrix(float a, Vector3 n) {

	n = n.Normalize();

	float cosA = std::cos(a);
	float sinA = std::sin(a);

	return RotateMatrix(n, cosA, sinA);
}

inline Matrix4x4 DirectionToDirection(Vector3 from, Vector3 to) {
	from = from.Normalize();
	to = to.Normalize();

	float cos = dot(from, to);
	
	if (cos < -0.9999f) {
		Vector3 axis = {};
		if (from.x != 0 || from.y != 0) {
			axis = { from.y, -from.x, 0.0f };
		} else {
			axis = { from.z, 0.0f, -from.x };
		}
		axis = axis.Normalize();
		return RotateMatrix(axis, -1.0f, 0.0f);
	}

	Vector3 axis = cross(from, to).Normalize();
	float sin = cross(from, to).Length();

	return RotateMatrix(axis, cos, sin);
}
