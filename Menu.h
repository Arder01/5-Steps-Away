#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "define.h"
#include "Collision.h"

class Menu
{
public:
	static Menu* GetInstance() {
		return s_Instance = (s_Instance != NULL) ? s_Instance : new Menu();
	}
	bool Init();
	void Clean();
	void Quit();

	void Update();
	void Render();
	SDL_Renderer* GetRender() {
		return MainMenu;
	}
	bool IsRunning() {
		return m_IsRunning;
	}
private:
	Menu() {}
	bool m_IsRunning;

	SDL_Window* window;
	SDL_Renderer* MainMenu;
	static Menu* s_Instance;
};

