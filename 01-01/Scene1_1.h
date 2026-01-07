#pragma once
#include <Scene/IScene.h>

class Scene1_1 : public IScene {
public:

	void Initialize() override;
	void Update() override;
	void Draw() override;

private:

	Vector3 axis;
	float angle;
	Matrix4x4 rotateMatrix;

};
