#pragma once
#include "ElementManager.h"
class MainControl
{
private:
public:
	static ElementManager em;
	static ALLEGRO_DISPLAY *display;
	static bool running;
	static void stopMain();
	void mainLoop();
	MainControl();
	~MainControl();
};

