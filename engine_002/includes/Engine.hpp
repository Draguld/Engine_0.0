#ifndef		ENGINE_HPP
#define		ENGINE_HPP

#include "std.hpp"
#include "sfml.hpp"

#include "Input.hpp"
#include "Scene.hpp"
#include "File.hpp"

#define	S_SETTINGFILEDEFAULT "resolution=640, 360\nframeratelimit=30\n"

class		Engine
{
	public:
	Engine();
	~Engine();

	bool				initialize();
	int					run();
	int					DEVRUN();

	private:
	void				init_settings();
		void				setDefaultSettingsValue();
		bool				createSettingsFile();
		bool				getSettingsFile();

	protected:
	//System
	sf::Clock			_mainClock;
	sf::RenderWindow	_window;
	sf::Event			_event;
	Input				_input;
	//Setting
	u32					_winX;
	u32					_winY;
	u32					_maxFps;
};

#endif
