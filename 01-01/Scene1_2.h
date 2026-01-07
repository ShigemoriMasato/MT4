#pragma once
#include <Scene/IScene.h>

class Scene1_2 : public IScene {
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;
private:
	std::vector<Vector3> from;
	std::vector<Vector3> to;
	std::vector<Matrix4x4> rotateMatrices;
};
