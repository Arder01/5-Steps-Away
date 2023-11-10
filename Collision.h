#pragma once
#include <vector>
#include <iostream>
#include "define.h"
#include "SDL.h"
#include <string>
#include "TinyXml/tinyxml.h"
#include <utility>

class Collision
{
public:
	bool CheckCollision(SDL_Rect a);
	bool Parse(std::string id, std::string source);
	void Render();
	bool Load(const std::string& id, const std::string& source);
	static Collision* GetInstance() {
		return s_instance = (s_instance != nullptr) ? s_instance : new Collision();
	}
	inline std::string GetFlag() { return Flag; }
	inline void SetFlag(std::string x) { Flag = x; }
	//vector<vector<int>> v;
	//Collision() :w(SWidth), h(SHeight), v(SWidth, vector<int>(SHeight,0)) {}
private:
	std::string id;
	std::string Flag = "Ground";
	std::string source;
 	std::vector<std::pair<SDL_Rect,std::string>> v;
	static Collision* s_instance;
};