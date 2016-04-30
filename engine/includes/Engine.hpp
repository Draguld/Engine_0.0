#ifndef		ENGINE_HPP
#define		ENGINE_HPP

#include "std.hpp"
#include "sfml.hpp"

#include "Input.hpp"
#include "Scene.hpp"
#include "Scene_Title.hpp"

class		Engine
{
	public:
	Engine();
	~Engine();

	bool				initialize();
	int					run();
	int					DEVRUN();

	protected:

	int					P_mainMenu();

	sf::Clock			_mainClock;
	sf::RenderWindow	_window;
	sf::Event			_event;
	Input				_input;
};

#endif
