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

inline Quaternion MakeRotateAxisAngleQuaternion(Vector3 axis, float rotate) {
	float half = rotate * 0.5f;
	float s = sin(half);
	return {
		axis.x * s,
		axis.y * s,
		axis.z * s,
		cos(half)
	};
}


inline Matrix4x4 MakeTranslationMatrix(const Vector3& pos) {
	return {
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		pos.x, pos.y, pos.z, 1.0f
	};
}

inline Matrix4x4 MakeRotationXMatrix(float angle) {
	return {
		1.0f ,0.0f, 0.0f, 0.0f,
		0.0f, std::cosf(angle), std::sinf(angle), 0.0f,
		0.0f, -std::sinf(angle), std::cosf(angle), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};
}

inline Matrix4x4 MakeRotationYMatrix(float angle) {
	return {
		std::cosf(angle), 0.0f, -std::sinf(angle), 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		std::sinf(angle), 0.0f, std::cosf(angle), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};
}

inline Matrix4x4 MakeRotationZMatrix(float angle) {
	return {
		std::cosf(angle), std::sinf(angle), 0.0f, 0.0f,
		-sinf(angle), std::cosf(angle), 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};
}

inline Matrix4x4 MakeRotationMatrix(const Quaternion& q) {
	float xx = q.x * q.x;
	float yy = q.y * q.y;
	float zz = q.z * q.z;
	
	return {
		1.0f - 2.0f * (yy + zz), 2.0f * (q.x * q.y + q.z * q.w), 2.0f * (q.x * q.z - q.y * q.w), 0.0f,
		2.0f * (q.x * q.y - q.z * q.w), 1.0f - 2.0f * (xx + zz), 2.0f * (q.y * q.z + q.x * q.w), 0.0f,
		2.0f * (q.x * q.z + q.y * q.w), 2.0f * (q.y * q.z - q.x * q.w), 1.0f - 2.0f * (xx + yy), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};
}

inline Matrix4x4 MakeRotationMatrix(Vector3 angle) {
	return
		MakeRotationXMatrix(angle.x) *
		MakeRotationYMatrix(angle.y) *
		MakeRotationZMatrix(angle.z);
}

inline Matrix4x4 MakeScaleMatrix(const Vector3& scale) {
	return {
		scale.x, 0.0f, 0.0f, 0.0f,
		0.0f, scale.y, 0.0f, 0.0f,
		0.0f, 0.0f, scale.z, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};
}

inline Vector3 operator*(const Vector3& vec, const Matrix4x4& mat) {
	return {
		mat.m[0][0] * vec.x + mat.m[1][0] * vec.y + mat.m[2][0] * vec.z + mat.m[3][0],
		mat.m[0][1] * vec.x + mat.m[1][1] * vec.y + mat.m[2][1] * vec.z + mat.m[3][1],
		mat.m[0][2] * vec.x + mat.m[1][2] * vec.y + mat.m[2][2] * vec.z + mat.m[3][2]
	};
}

inline Vector3 operator*(const Vector3& vec, const Quaternion& q) {
	Quaternion p = { vec.x, vec.y, vec.z, 0.0f };
	Quaternion qConj = q.Conjugate();
	Quaternion result = q * p * qConj;
	return { result.x, result.y, result.z };
}

inline Quaternion Slerp(const Quaternion& q1, const Quaternion& q2, float t) {
	float cosTheta = dot(q1, q2);
	float theta = std::acos(cosTheta);

	float ratio0 = std::sin((1.0f - t) * theta) / std::sin(theta);
	float ratio1 = std::sin(t * theta) / std::sin(theta);

	return Quaternion(
		q1.x * ratio0 + q2.x * ratio1,
		q1.y * ratio0 + q2.y * ratio1,
		q1.z * ratio0 + q2.z * ratio1,
		q1.w * ratio0 + q2.w * ratio1
	).Normalize();
}

