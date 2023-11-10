#pragma once
#include "Animation.h"

class SpriteAnimation :public Animation
{
public:
	SpriteAnimation(bool repeat = true);
	virtual void Update(float dt);
	void Draw(float x, float y, int SpriteWidth, int SpriteHeight);
	void SetProps(std::string textureId, int spriterow, int framecount, int speed, SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
	int Speed;
	int SpriteRow;
	int FrameCount;
	std::string TextureId;
	SDL_RendererFlip flip = SDL_FLIP_NONE;
};

