#pragma once
#include <Scene/IScene.h>

class Scene1_3 : public IScene {
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;
private:
	Quaternion q1;
	Quaternion q2;
};
