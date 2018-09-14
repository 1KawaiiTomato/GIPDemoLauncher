#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include <iostream>
#include <Windows.h>
#include "ElementManager.h"
#include "Button.h"



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

	UIElement *e = new UIElement("Images/sample.png", 0, 0);
	em.addElement(e);
	e = new Button("Images/button.png", 0.12, 0.1, []() {
														al_destroy_display(display);
														em.~ElementManager();
														running = false;
														system("\"C:\\Users\\RikF107\\Documents\\the crunch\\LD42.exe\"");
	});
	em.addElement(e);
	e = new Button("Images/quit.png", 0.12, 0.2, []() {running = false; });
	em.addElement(e);

	while (running) {
		em.render();
		em.update();
	}
	
	return 0;
}