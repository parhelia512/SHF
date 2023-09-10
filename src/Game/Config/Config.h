#pragma once

#include "../../File/INIReader.h"
#include "../GameTypes.h"
#include "../../Engine/Engine.h"
#include "../../Engine/EngineBase.h"

class Config
{
public:
	Config();
	virtual ~Config();

	static bool fullScreen;
	static bool playerAlpha;
	static bool canChangeDisplayMode;

	static void load();
	static void save();
	static float getMusicVolume();
	static float getSoundVolume();
	static float setMusicVolume(float volume);
	static float setSoundVolume(float volume);

	static void getWindowSize(int& w, int& h);
	static void setDefaultWindowSize(int w, int h);

private:
	static int windowWidth;
	static int windowHeight;
};

