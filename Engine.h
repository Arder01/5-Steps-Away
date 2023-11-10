#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "define.h"
#include "Collision.h"

class Engine
{
public:
	static Engine* GetInstance() {
		return s_Instance = (s_Instance != NULL) ? s_Instance : new Engine();
	}
	bool Init();
	void Clean();
	void Quit();

	void Update();
	void Render();
	void Events();
	SDL_Renderer* GetRender() {
		return Level1;
	}
	bool IsRunning() {
		return m_IsRunning;
	}
private:
	Engine() {}
	bool m_IsRunning;

	SDL_Window* window;
	SDL_Renderer* Level1;
	SDL_Renderer* Menu;
	static Engine* s_Instance;
};

