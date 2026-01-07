#pragma once
#include "Structure.h"
#include <string>
#include <Novice.h>

inline void printf(Vector2 offset, const Matrix4x4& mat, std::string tag = "Matrix4x4") {

	Novice::ScreenPrintf(int(offset.x), int(offset.y), "%s", tag.c_str());

	int beginX = int(offset.x);
	int beginY = int(offset.y) + 16;

	for (int i = 0; i < 4; ++i) {
		Novice::ScreenPrintf(beginX, beginY + i * 16, "| %8.3f %8.3f %8.3f %8.3f |", mat.m[i][0], mat.m[i][1], mat.m[i][2], mat.m[i][3]);
	}
}

inline void printf(Vector2 offset, const Matrix3x3& mat, std::string tag = "Matrix3x3") {

	Novice::ScreenPrintf(int(offset.x), int(offset.y), "%s", tag.c_str());

	int beginX = int(offset.x);
	int beginY = int(offset.y) + 16;

	for (int i = 0; i < 3; ++i) {
		Novice::ScreenPrintf(beginX, beginY + i * 16, "| %8.3f %8.3f %8.3f |", mat.m[i][0], mat.m[i][1], mat.m[i][2]);
	}
}

inline void printf(Vector2 offset, const Vector3& vec, std::string tag = "Vector3") {
	Novice::ScreenPrintf(int(offset.x), int(offset.y), "%s: { %8.3f, %8.3f, %8.3f }", tag.c_str(), vec.x, vec.y, vec.z);
}

inline void printf(Vector2 offset, const Vector2& vec, std::string tag = "Vector2") {
	Novice::ScreenPrintf(int(offset.x), int(offset.y), "%s: { %8.3f, %8.3f }", tag.c_str(), vec.x, vec.y);
}
