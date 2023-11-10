#pragma once
#include "SDL.h"
#include <string>

class Animation {
public:
	Animation(bool repeat = true) :Repeat(repeat) { m_IsEnded = false; }
	inline int GetCurrentFrame() { return CurrentFrame; }
	inline void SetCurrentFrame(int x) { CurrentFrame = x; }
	inline bool IsEnded() { return m_IsEnded; }
	inline bool SetIsEnded(bool x) { m_IsEnded = x; }
private:
	bool Repeat;
	bool m_IsEnded;
	int CurrentFrame;
};