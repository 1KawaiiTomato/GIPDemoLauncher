#pragma once
#include "UIElement.h"
class Button :
	public UIElement
{
private:

public:
	std::string getType() override;
	Button();
	Button(std::string texturePath, float x, float y, void(*function)());
	~Button();
};

