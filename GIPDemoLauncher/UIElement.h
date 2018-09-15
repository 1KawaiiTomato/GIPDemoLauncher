#pragma once
#include "allegro5/allegro.h"
#include "allegro5/allegro_native_dialog.h"
#include <iostream>
#include <string>
#include <functional>
#include <unordered_map>

class UIElement
{
protected:
	ALLEGRO_BITMAP *texture;
public:
	std::unordered_map<std::string, float> values;
	bool isAnimated;
	float relativeX;
	float relativeY;
	float relativeWidth;
	float relativeHeight;
	std::function<void(void)> onClick;
	//void(*onClick)();
	virtual void render();
	virtual std::string getType();
	UIElement();
	UIElement(std::string texturePath, float x, float y);
	~UIElement();
};

