#pragma once
#include <cmath>

struct Vector2 {
	float x;
	float y;
	Vector2 operator+(const Vector2& other) const {
		return {x + other.x, y + other.y};
	}
	Vector2 operator-(const Vector2& other) const {
		return {x - other.x, y - other.y};
	}
	Vector2 operator*(float scalar) const {
		return {x * scalar, y * scalar};
	}
	float Length() const {
		return std::sqrt(x * x + y * y);
	}
	Vector2 Normalize() const {
		float length = Length();
		if (length == 0) {
			return {0, 0};
		}
		return {x / length, y / length};
	}
};

struct Vector3 {
	float x;
	float y;
	float z;
	Vector3 operator+(const Vector3& other) const {
		return {x + other.x, y + other.y, z + other.z};
	}
	Vector3 operator-(const Vector3& other) const {
		return {x - other.x, y - other.y, z - other.z};
	}
	Vector3 operator*(float scalar) const {
		return {x * scalar, y * scalar, z * scalar};
	}
	float Length() const {
		return std::sqrt(x * x + y * y + z * z);
	}
	Vector3 Normalize() const {
		float length = Length();
		if (length == 0) {
			return {0, 0, 0};
		}
		return {x / length, y / length, z / length};
	}
};

inline float dot(const Vector2& a, const Vector2& b) {
	return a.x * b.x + a.y * b.y;
}
inline float dot(const Vector3& a, const Vector3& b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline float cross(const Vector2& a, const Vector2& b) {
	return a.x * b.y - a.y * b.x;
}
inline Vector3 cross(const Vector3& a, const Vector3& b) {
	return {
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	};
}

struct Matrix3x3 {
	float m[3][3];

	Matrix3x3 operator*(const Matrix3x3& other) const {
		Matrix3x3 result = {};
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				for (int k = 0; k < 3; ++k) {
					result.m[i][j] += m[i][k] * other.m[k][j];
				}
			}
		}
		return result;
	}
	Vector2 operator*(const Vector2& vec) const {
		return {
			m[0][0] * vec.x + m[0][1] * vec.y + m[0][2],
			m[1][0] * vec.x + m[1][1] * vec.y + m[1][2]
		};
	}
};

struct Matrix4x4 {
	float m[4][4];

	Matrix4x4 operator*(const Matrix4x4& other) const {
		Matrix4x4 result = {};
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				for (int k = 0; k < 4; ++k) {
					result.m[i][j] += m[i][k] * other.m[k][j];
				}
			}
		}
		return result;
	}
	Vector3 operator*(const Vector3& vec) const {
		return {
			m[0][0] * vec.x + m[0][1] * vec.y + m[0][2] * vec.z + m[0][3],
			m[1][0] * vec.x + m[1][1] * vec.y + m[1][2] * vec.z + m[1][3],
			m[2][0] * vec.x + m[2][1] * vec.y + m[2][2] * vec.z + m[2][3]
		};
	}
};

struct Quaternion {
	float x;
	float y;
	float z;
	float w;

	static Quaternion Identity() {
		return { 0.0f, 0.0f, 0.0f, 1.0f };
	}

	Quaternion Conjugate() const {
		return { -x, -y, -z, w };
	}

	Quaternion Normalize() const {
		float length = Norm();
		if (length == 0) {
			return {0, 0, 0, 1};
		}
		return { x / length, y / length, z / length, w / length };
	}

	Quaternion Inverse() const {
		Quaternion conj = Conjugate();
		float normSq = x * x + y * y + z * z + w * w;
		if (normSq == 0) {
			return {0, 0, 0, 1};
		}
		return { conj.x / normSq, conj.y / normSq, conj.z / normSq, conj.w / normSq };
	}

	float Norm() const {
		return std::sqrt(x * x + y * y + z * z + w * w);
	}

	Quaternion operator*(const Quaternion& r) const {
		Vector3 qv = { x, y, z };
		Vector3 rv = { r.x, r.y, r.z };

		float ansW = w * r.w - dot(qv, rv);
		Vector3 xyz = cross(qv, rv) + qv * r.w + rv * w;
		return { xyz.x, xyz.y, xyz.z, ansW };
	}
};
