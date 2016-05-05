#ifndef		INPUT_HPP
#define		INPUT_HPP

#include "std.hpp"
#include "sfml.hpp"

class	Input
{
	public:
	Input();
	~Input();
	
	enum	Button
	{
		START = 0,
		SELECT,
		A,
		B,
		Y,
		X,
		UP,
		DOWN,
		RIGHT,
		LEFT,
		TRIGGER_LEFT_ONE,
		TRIGGER_LEFT_TWO,
		TRIGGER_RIGHT_ONE,
		TRIGGER_RIGHT_TWO,
		COUNT = 14
	};

	void				update();

	bool				getButtonStat(int button)const;
	sf::RenderWindow	*getContext()const;
	sf::Event			*getEvent()const;
	bool				getClosureRequest()const;

	void				setButtonStat(int button, bool stat);
	void				setContext(sf::RenderWindow *context);
	void				setEvent(sf::Event *event);

	protected:
	bool				*_button;
	bool				_closureRequest;

	sf::RenderWindow	*_context;
	sf::Event			*_event;
};

#endif
