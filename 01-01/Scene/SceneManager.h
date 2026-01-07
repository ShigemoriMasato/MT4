#pragma once
#include "IScene.h"

class SceneManager {
public:

	SceneManager() = default;
	~SceneManager() = default;

	void Initialize();

	void LoadScene(int chapter, int section);

	void Update();
	void Draw();

private:

	std::vector<std::vector<std::unique_ptr<IScene>>> scenes_;

	int currentChapter_ = 1;
	int preSection_ = 0;
	int currentSection_ = 1;
	int preChapter_ = 0;
};
