#include "ElementManager.h"



void ElementManager::deleteElements()
{
	for (auto it : elements) {
		delete it;
	}
	elements.clear();
}

void ElementManager::update()
{
	float w, h;
	w = al_get_display_width(al_get_current_display());
	h = al_get_display_height(al_get_current_display());

	ALLEGRO_EVENT E;
	al_get_next_event(EQ, &E);
	if (E.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
		for (auto it : elements) {
			if (E.mouse.x > it->relativeX*w && E.mouse.x < it->relativeX*w + it->relativeWidth &&
				E.mouse.y > it->relativeY*h && E.mouse.y < it->relativeY*h + it->relativeHeight) {
				std::cout << it->getType();
				if (it->getType() == "Button") {
					static_cast<Button*>(it)->isDown = true;
				}
			}
		}
	}
	else {
		if (E.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			for (auto it : elements) {
				if (it->getType() == "Button") {
					static_cast<Button*>(it)->isDown = false;
					if (E.mouse.x > it->relativeX*w && E.mouse.x < it->relativeX*w + it->relativeWidth &&
						E.mouse.y > it->relativeY*h && E.mouse.y < it->relativeY*h + it->relativeHeight) {
						it->onClick();
					}
				}
			}
		}
	}
	for (auto it : elements) {
		if (it->isAnimated) {
			static_cast<Panel*>(it)->update();
		}
	}
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
	EQ = al_create_event_queue();
	al_register_event_source(EQ, al_get_mouse_event_source());
}


ElementManager::~ElementManager()
{
	deleteElements();
}
