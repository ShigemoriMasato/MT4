#pragma once
#include <Scene/IScene.h>

class Scene1_4 : public IScene {
public:

	void Initialize() override;
	void Update() override;
	void Draw() override;

private:

	Quaternion rotation{};
	Vector3 pointY = { 2.1f, -0.9f, 1.3f };
	Matrix4x4 rotateMatrix{};
	Vector3 rotateByQuaternion{};
	Vector3 rotateByMatrix{};

};
