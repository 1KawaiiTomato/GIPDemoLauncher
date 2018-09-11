#include "ElementManager.h"



void ElementManager::update()
{
}

void ElementManager::render()
{
	al_clear_to_color(this->white);
	for (auto it : elements) {
		it->render();
	}
	al_flip_display();
}

void ElementManager::addElement(UIElement *e)
{
	elements.push_back(e);
}

ElementManager::ElementManager()
{
	this->white = al_map_rgb(255, 255, 255);
}


ElementManager::~ElementManager()
{
}
