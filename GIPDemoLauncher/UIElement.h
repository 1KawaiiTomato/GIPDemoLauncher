#pragma once
#include "allegro5/allegro.h"
#include "allegro5/allegro_native_dialog.h"
#include <iostream>
#include <string>
class UIElement
{
private:
	float relativeX;
	float relativeY;
	float relativeWidth;
	float relativeHeight;
	ALLEGRO_BITMAP *texture;
public:
	void render();
	UIElement();
	UIElement(std::string texturePath, float x, float y);
	~UIElement();
};

