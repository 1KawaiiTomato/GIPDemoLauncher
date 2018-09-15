#pragma once
#include "UIElement.h"
#include <vector>

class Panel :
	public UIElement
{
private:
	float speed;
public:
	static void scroll(UIElement* p, float speed);
	std::function<void(UIElement*, float)> animate;
	std::string getType() override;
	Panel(std::string texturePath, float x, float y, void(*function)(UIElement*, float), float speed);
	Panel(std::string texturePath, float x, float y);
	void update();
	Panel();
	~Panel();
};

