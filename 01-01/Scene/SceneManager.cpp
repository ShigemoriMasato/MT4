#include "SceneManager.h"
#include <Scene1-1.h>
#include <Scene1_2.h>
#include <imgui.h>

void SceneManager::Initialize() {
	const int allChapterCount = 1 + 1;
	scenes_.resize(allChapterCount);

	for (int i = 0; i < allChapterCount; ++i) {
		scenes_[i].push_back(nullptr);
	}

	//Chapter 1
	scenes_[1].push_back(std::make_unique<Scene1_1>());
	scenes_[1].push_back(std::make_unique<Scene1_2>());

	currentChapter_ = 1;
	currentSection_ = 1;
}

void SceneManager::LoadScene(int chapter, int section) {
	if (scenes_.size() >= chapter && scenes_[chapter].size() >= section) {
		currentChapter_ = chapter;
		currentSection_ = section;
	}

	if (scenes_[currentChapter_][currentSection_]) {
		scenes_[currentChapter_][currentSection_]->Initialize();
	}
}

void SceneManager::Update() {

	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::Begin("Scene Manager");
	ImGui::PushID(0);
	ImGui::Text("Chapter: %d", currentChapter_);
	ImGui::SameLine();
	if (ImGui::Button("<<")) {
		currentChapter_--;
	}
	ImGui::SameLine();
	if (ImGui::Button(">>")) {
		currentChapter_++;
	}
	currentChapter_ = std::clamp(currentChapter_, 1, static_cast<int>(scenes_.size()) - 1);
	ImGui::PopID();

	ImGui::PushID(1);
	ImGui::Text("Section: %d", currentSection_);
	ImGui::SameLine();
	if (ImGui::Button("<<")) {
		currentSection_--;
	}
	ImGui::SameLine();
	if (ImGui::Button(">>")) {
		currentSection_++;
	}
	currentSection_ = std::clamp(currentSection_, 1, static_cast<int>(scenes_[currentChapter_].size()) - 1);
	ImGui::PopID();
	ImGui::End();

	if (currentChapter_ != preChapter_ || currentSection_ != preSection_) {

		if (preChapter_ != currentChapter_) {
			currentChapter_ = 1;
		}

		LoadScene(currentChapter_, currentSection_);
		preChapter_ = currentChapter_;
		preSection_ = currentSection_;
	}

	if (scenes_[currentChapter_][currentSection_]) {
		scenes_[currentChapter_][currentSection_]->Update();
	}

}

void SceneManager::Draw() {

	if (scenes_[currentChapter_][currentSection_]) {
		scenes_[currentChapter_][currentSection_]->Draw();
	}

}
