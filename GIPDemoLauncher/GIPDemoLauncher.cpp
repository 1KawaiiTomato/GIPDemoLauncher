#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include <iostream>
#include <Windows.h>
#include "ElementManager.h"
#include "Button.h"
#include "Panel.h"



int main()
{
	al_init();
	al_init_image_addon();

	al_install_mouse();
	//TCHAR lpszClientPath[500] = TEXT("c:\\users\\RikF107\\source\\repos\\GIPDemo\\GIPDemo\\Debug\\GIPDemo.exe");
	//CreateProcess(lpszClientPath, NULL, NULL, NULL, true, HIGH_PRIORITY_CLASS, NULL, NULL, NULL, NULL);

	/*
	STARTUPINFOA *si;
	_PROCESS_INFORMATION *pi;

	memset(&si, 0, sizeof(si));
	memset(&pi, 0, sizeof(pi));

	CreateProcessA("C:\\Users\\RikF107\\source\\repos\\GIPDemo\\GIPDemo\\Debug\\GIPDemo.exe", NULL, NULL, NULL, true, HIGH_PRIORITY_CLASS, NULL, NULL, si, pi);
	*/
	
	static bool running = true;
	static ALLEGRO_DISPLAY *display;
	static ElementManager em;

	
	al_set_new_display_flags(ALLEGRO_FRAMELESS);
	display = al_create_display(250, 550);


	/*ALLEGRO_EVENT_QUEUE *EQ;
	EQ = al_create_event_queue();
	ALLEGRO_TIMER *timer;
	timer = al_create_timer(1/60);
	al_register_event_source(EQ, al_get_timer_event_source(timer));
	al_start_timer(timer);*/


	UIElement *e = new Panel("Images/sample.png", 0, 0, { Panel::scroll }, { {"sSpeed", 0.0001} });
	em.addElement(e);
	e = new Panel("Images/poboraria.png", 0.02, 0.07, { Panel::wobble }, { {"wSpeed", 0.002}, {"wHeight", 0.00006}, {"wAngle", 0.0f} });
	em.addElement(e);
	e = new Panel("Images/pobogames.png", 0.02, 0.83);
	em.addElement(e);
	e = new Button({ "Images/play.png", "Images/playdown.png" }, 0.12, 0.23, []() {
														al_destroy_display(display);
														em.~ElementManager();
														running = false;
														system("\"C:\\Users\\RikF107\\Documents\\the crunch\\LD42.exe\""); });
	em.addElement(e);
	e = new Button({ "Images/quit.png", "Images/quitdown.png" }, 0.12, 0.33, []() {running = false; });
	em.addElement(e);

	while (running) {
		em.render();
		em.update();
	}
	
	return 0;
}