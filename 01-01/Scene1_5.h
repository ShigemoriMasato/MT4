#pragma once
#include <Scene/IScene.h>

class Scene1_5 : public IScene {
public:

	void Initialize() override;
	void Update() override;
	void Draw() override;

private:

	Quaternion rotation0{};
	Quaternion rotation1{};

	Quaternion interpolate0{};
	Quaternion interpolate1{};
	Quaternion interpolate2{};
	Quaternion interpolate3{};
	Quaternion interpolate4{};
};
