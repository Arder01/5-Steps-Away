#include "Menu.h"
#include "Timer.h"
#include "Input.h"
#include "Level.h"
Menu* Menu::s_Instance = nullptr;

bool Menu::Init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0)
	{
		SDL_Log("Failed to initialize SDL :  %s", SDL_GetError());
		return false;
	}
	SDL_WindowFlags  WindowFlag = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
	window = SDL_CreateWindow("5 Steps Away", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SWidth, SHeight, WindowFlag);
	if (window == nullptr) {
		SDL_Log("Failed to create window :%s", SDL_GetError());
		return false;
	}
	MainMenu = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (MainMenu == nullptr) {
		SDL_Log("Failed to render : %s", SDL_GetError());
		return false;
	}
	if (Collision::GetInstance()->Load("Box", "Assets/Collision/MenuCollision.xml") == false) {//using load instead of Parse as parse requires id and source
		std::cout << "Falied to extract Box dataset" << SDL_GetError() << std::endl;
	}
}

void Menu::Update() {
	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_Q)) {

	}
}