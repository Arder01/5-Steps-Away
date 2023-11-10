#include "Engine.h"
#include <iostream>
#include "Player.h"
#include "Timer.h"
#include "Input.h"
#include "TextureManager.h"
Engine* Engine::s_Instance = nullptr;
Player* MChar = nullptr;

bool Engine::Init() {
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
	/*Menu = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (Menu == nullptr) {
		SDL_Log("Failed to render Menu: %s", SDL_GetError());
	}*/
	Level1 = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (Level1 == nullptr) {
		SDL_Log("Failed to render : %s", SDL_GetError());
		return false;
	}
	if (Collision::GetInstance()->Load("Box","Assets/Collision/LevelCollision.xml") == false) {//using load instead of Parse as parse requires id and source
		std::cout << "Falied to extract Box dataset" << SDL_GetError() << std::endl;
	}
	if (TextureManager::GetInstance()->ParseTextures("Assets/Texture/Textures.tml") == false)
		std::cout << "Failed to parse texture" << SDL_GetError() << std::endl;
	MChar = new Player(340, 10, 62, 80);
	if (MChar == nullptr) SDL_Log("Failed to create player pointer :%s", SDL_GetError());
	return m_IsRunning = true;
}

void Engine::Events()
{
	Input::GetInstance()->Listen();
}
void Engine::Update() {
	float dt = Timer::GetInstance()->GetDeltaTime();
	MChar->Update(dt);
	//std::cout << dt << std::endl;
}
void Engine::Render() {
	SDL_SetRenderDrawColor(Level1, 255, 255, 255, 50);
	//SDL_RenderClear(Menu);
	//SDL_RenderPresent(Menu);
	SDL_RenderClear(Level1);
	/*SDL_Surface* grass = IMG_Load("Assets/Block1.png");
	if (grass == NULL) std::cout << "Error getting Grass" << SDL_GetError() << std::endl;
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, grass);
	if (texture == NULL) SDL_Log("Error converting grass to texture :%s", SDL_GetError());
	SDL_Rect srcrect = { 0,0,256,96 };
	SDL_Rect dstrect = { 200,200,256,96 };
	SDL_RenderCopyEx(renderer, texture, &srcrect, &dstrect, 0, nullptr, SDL_FLIP_NONE);*/
	TextureManager::GetInstance()->Draw("BG1", -75, 15, SWidth, SHeight);
	Collision::GetInstance()->Render();
	MChar->Render();
	SDL_RenderPresent(Level1);
}

void Engine::Quit() {
	m_IsRunning = false;
}

void Engine::Clean() {
	TextureManager::GetInstance()->Clean();
	SDL_DestroyRenderer(Level1);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}