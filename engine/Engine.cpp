#include "Engine.hpp"

Engine::Engine():
_mainClock(),
_window(),
_event()
{
		
}

Engine::~Engine()
{
		
}

bool					Engine::initialize()
{
	//Create the window.
	_window.create(sf::VideoMode(800, 450), "NONAME");
	_window.setFramerateLimit(60);

	//Restart _mainClock.
	_mainClock.restart();

	//Initialize member Input object.
	_input.setContext(&_window);
	_input.setEvent(&_event);
	return (true);
}

int						Engine::run()
{
	_window.close();
	return (0);
}

int						Engine::DEVRUN()
{
	P_mainMenu();
	_window.close();
	return (0);
}

int						Engine::P_mainMenu()
{
	Scene_Title		M(&_window, &_input);
	return (M.play());
}
