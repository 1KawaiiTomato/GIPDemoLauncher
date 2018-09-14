#include "Button.h"


std::string Button::getType()
{
	return "Button";
}

Button::Button()
{
}

Button::Button(std::string texturePath, float x, float y, void(*function)()) : UIElement(texturePath, x, y)
{
	this->onClick = function;
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << this->relativeWidth << std::endl;
}


Button::~Button()
{
}