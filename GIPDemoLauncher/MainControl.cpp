#include "MainControl.h"

bool MainControl::running = true;
ALLEGRO_DISPLAY *MainControl::display;
ElementManager MainControl::em;

void MainControl::stopMain()
{
	MainControl::running = false;
}

void MainControl::mainLoop()
{
	while (MainControl::running) {
		em.update();
		em.render();
	}
}

MainControl::MainControl()
{
	al_set_new_display_flags(ALLEGRO_FRAMELESS);
	MainControl::display = al_create_display(250, 550);
	MainControl::em = ElementManager();

	UIElement *e = new UIElement("Images/sample.png", 0, 0);
	em.addElement(e);
	e = new Button("Images/button.png", 0.12745, 0.1, []() {
															//MainControl::em->~ElementManager();
															al_destroy_display(MainControl::display);
															system("c:\\users\\RikF107\\Documents\\the crunch\\LD42.exe"); });
	em.addElement(e);
	e = new Button("Images/quit.png", 0.12745, .2, MainControl::stopMain);
	em.addElement(e);
}


MainControl::~MainControl()
{
}
