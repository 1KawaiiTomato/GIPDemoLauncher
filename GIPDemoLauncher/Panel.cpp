#include "Panel.h"



void Panel::scroll(UIElement *p, float speed)
{
	p->relativeX -= speed/10;
}

void Panel::wobble(UIElement * p, float speed)
{
	p->angle+=0.001;
	p->relativeY = p->relativeY - ((sin(p->angle) * speed));
}

std::string Panel::getType()
{
	return "Panel";
}

Panel::Panel(std::string texturePath, float x, float y, std::vector<std::function<void(UIElement*, float)>> functions, float speed) : UIElement(texturePath, x, y)
{
	this->animations = functions;
	this->isAnimated = true;
	this->speed = speed;
	this->angle = 0.0f;
}

Panel::Panel(std::string texturePath, float x, float y) : UIElement(texturePath, x, y)
{
}

void Panel::update()
{
	for (auto it : animations) {
		it(this, this->speed);
	}
}

Panel::Panel()
{
}


Panel::~Panel()
{
}
