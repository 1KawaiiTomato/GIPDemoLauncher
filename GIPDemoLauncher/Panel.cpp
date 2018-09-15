#include "Panel.h"



void Panel::scroll(UIElement *p, float speed)
{
	p->relativeX+= speed;
}

std::string Panel::getType()
{
	return "Panel";
}

Panel::Panel(std::string texturePath, float x, float y, void(*function)(UIElement*, float)) : UIElement(texturePath, x, y)
{
	animate = function;
	this->isAnimated = true;
}

Panel::Panel(std::string texturePath, float x, float y) : UIElement(texturePath, x, y)
{
}

void Panel::update()
{
	animate(this, -0.0001);
}

Panel::Panel()
{
}


Panel::~Panel()
{
}
