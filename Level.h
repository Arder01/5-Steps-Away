#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "define.h"
#include "Collision.h"

class Level
{
public:
	static Level* GetInstance() {
		return s_Instance = (s_Instance != NULL) ? s_Instance : new Level();
	}
	bool Init();
	void Clean();
	void Quit();

	void Update();
	void Render();
	void Events();
	SDL_Renderer* GetRender() {
		return MainMenu;
	}
	bool IsRunning() {
		return m_IsRunning;
	}
private:
	Level() {}
	bool m_IsRunning;

	SDL_Window* window;
	SDL_Renderer* MainMenu;
	static Level* s_Instance;
};

