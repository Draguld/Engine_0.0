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
	//Initialiser of setting.
	init_settings();
	//Create the window.
	_window.create(sf::VideoMode(_winX, _winY), "NONAME");
	_window.setFramerateLimit(_maxFps);

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
	while (_window.isOpen())
	{
		_input.update();
		if (_input.getClosureRequest() == true)
			_window.close();
			
	}
	return (0);
}

void					Engine::init_settings()
{
	if (access("cfg/settings.cfg", F_OK | R_OK) == -1)
	{
		createSettingsFile();
		setDefaultSettingsValue();
	}
	else
	{
		if (!getSettingsFile())
			setDefaultSettingsValue();
	}
}

bool					Engine::createSettingsFile()
{
	std::ofstream	flux_out;

	flux_out.open("cfg/settings.cfg", std::ios::out | std::ios::trunc);
	if (!flux_out)
		return (false);
	flux_out << S_SETTINGFILEDEFAULT;
	flux_out.close();
	return (true);
}

bool					Engine::getSettingsFile()
{
	File		setting;

	if (!setting.read("cfg/settings.cfg"))
		return (false);
	_winX = setting.u32FromString(setting.find("resolution="), 1);
	_winY = setting.u32FromString(setting.find("resolution="), 2);
	_maxFps = setting.u32FromString(setting.find("frameratelimit="), 1);
	if (_winX == (u32)-1 || _winY == (u32)-1 || _maxFps == (u32)-1)
		return (false);
	return (true);
}

void					Engine::setDefaultSettingsValue()
{
	_winX = 640;
	_winY = 360;
	_maxFps = 30;
}
