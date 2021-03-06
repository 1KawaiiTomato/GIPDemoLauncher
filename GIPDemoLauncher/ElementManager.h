#pragma once
#include <iostream>
#include <vector>
#include "Button.h"
#include "Panel.h"

class ElementManager
{
private:
	ALLEGRO_COLOR white;
	std::vector<UIElement*> elements;
	ALLEGRO_EVENT_QUEUE *EQ;
public:
	void deleteElements();
	void update();
	void render();
	void addElement(UIElement *e);
	ElementManager();
	~ElementManager();
};

