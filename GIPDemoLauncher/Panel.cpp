#include "Panel.h"



void Panel::scroll(UIElement *p, float speed)
{
	p->relativeX += speed;
}

std::string Panel::getType()
{
	return "Panel";
}

Panel::Panel(std::string texturePath, float x, float y, void(*function)(UIElement*, float), float speed) : UIElement(texturePath, x, y)
{
	this->animate = function;
	this->isAnimated = true;
	this->speed = speed;
}

Panel::Panel(std::string texturePath, float x, float y) : UIElement(texturePath, x, y)
{
}

void Panel::update()
{
	animate(this, this->speed);
}

Panel::Panel()
{
}


Panel::~Panel()
{
}
