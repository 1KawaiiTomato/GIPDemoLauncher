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
	static void wobble(UIElement *p, float speed);

	std::vector<std::function<void(UIElement*, float)>> animations;

	std::string getType() override;
	void update();

	Panel(std::string texturePath, float x, float y, std::vector<std::function<void(UIElement*, float)>> functions, float speed);
	Panel(std::string texturePath, float x, float y);
	Panel();
	~Panel();
};

