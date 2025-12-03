#pragma once
#include "Structure.h"

inline Matrix4x4 MakeRotateAxisMatrix(float a, Vector3 n) {

	n = n.Normalize();

	return {
		n.x * n.x * (1 - std::cos(a)) + std::cos(a), n.x * n.y * (1.0f - std::cos(a)) + n.z * std::sin(a), n.x * n.z * (1.0f - std::cos(a)) - n.y * std::sin(a), 0.0f,
		n.x + n.y * (1.0f - std::cos(a)) - n.z * std::sin(a), n.y* n.y* (1.0f - std::cos(a)) + std::cos(a), n.y* n.z* (1.0f - std::cos(a)) + n.x * std::sin(a), 0.0f,
		n.x* n.z* (1.0f - std::cos(a)) + n.y * std::sin(a), n.y* n.z* (1.0f - std::cos(a)) - n.x * std::sin(a), n.z* n.z* (1.0f - std::cos(a)) + std::cos(a), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};

}
