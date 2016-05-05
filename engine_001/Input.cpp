#include "Input.hpp"

Input::Input():
_button(0),
_closureRequest(false)
{
	_button = new bool[14];
}

Input::~Input()
{
	delete[] _button;
	_button = 0;
}

void			Input::update()
{
	while (_context->pollEvent(*_event))
	{
		if (_event->type == sf::Event::Closed)
			_closureRequest = true;
		if (_event->type == sf::Event::KeyPressed)
		{
				if (_event->key.code == sf::Keyboard::Q)
					_button[Input::Button::START] = true;
				else if (_event->key.code == sf::Keyboard::E)
					_button[Input::Button::SELECT] = true;
				else if (_event->key.code == sf::Keyboard::S)					
					_button[Input::Button::A] = true;
				else if (_event->key.code == sf::Keyboard::D)					
					_button[Input::Button::B] = true;
				else if (_event->key.code == sf::Keyboard::W)
					_button[Input::Button::Y] = true;
				else if (_event->key.code == sf::Keyboard::A)
					_button[Input::Button::X] = true;
				else if (_event->key.code == sf::Keyboard::Up)					
					_button[Input::Button::UP] = true;
				else if (_event->key.code == sf::Keyboard::Down)					
					_button[Input::Button::DOWN] = true;
				else if (_event->key.code == sf::Keyboard::Right)					
					_button[Input::Button::RIGHT] = true;
				else if (_event->key.code == sf::Keyboard::Left)					
					_button[Input::Button::LEFT] = true;
				else if (_event->key.code == sf::Keyboard::Num1)					
					_button[Input::Button::TRIGGER_LEFT_ONE] = true;
				else if (_event->key.code == sf::Keyboard::Num2)					
					_button[Input::Button::TRIGGER_LEFT_TWO] = true;
				else if (_event->key.code == sf::Keyboard::Num3)					
					_button[Input::Button::TRIGGER_RIGHT_ONE] = true;
				else if (_event->key.code == sf::Keyboard::Num4)					
					_button[Input::Button::TRIGGER_RIGHT_TWO] = true;
		}
		if (_event->type == sf::Event::KeyReleased)
		{
				if (_event->key.code == sf::Keyboard::Q)
					_button[Input::Button::START] = false;
				else if (_event->key.code == sf::Keyboard::E)
					_button[Input::Button::SELECT] = false;
				else if (_event->key.code == sf::Keyboard::S)					
					_button[Input::Button::A] = false;
				else if (_event->key.code == sf::Keyboard::D)					
					_button[Input::Button::B] = false;
				else if (_event->key.code == sf::Keyboard::W)
					_button[Input::Button::Y] = false;
				else if (_event->key.code == sf::Keyboard::A)
					_button[Input::Button::X] = false;
				else if (_event->key.code == sf::Keyboard::Up)					
					_button[Input::Button::UP] = false;
				else if (_event->key.code == sf::Keyboard::Down)					
					_button[Input::Button::DOWN] = false;
				else if (_event->key.code == sf::Keyboard::Right)					
					_button[Input::Button::RIGHT] = false;
				else if (_event->key.code == sf::Keyboard::Left)					
					_button[Input::Button::LEFT] = false;
				else if (_event->key.code == sf::Keyboard::Num1)					
					_button[Input::Button::TRIGGER_LEFT_ONE] = false;
				else if (_event->key.code == sf::Keyboard::Num2)					
					_button[Input::Button::TRIGGER_LEFT_TWO] = false;
				else if (_event->key.code == sf::Keyboard::Num3)					
					_button[Input::Button::TRIGGER_RIGHT_ONE] = false;
				else if (_event->key.code == sf::Keyboard::Num4)					
					_button[Input::Button::TRIGGER_RIGHT_TWO] = false;
		}
	}
}

bool			Input::getButtonStat(int button)const
{
	if (button >= 0 && button < Input::Button::COUNT)
		return (_button[button]);
	return (false);
}

sf::RenderWindow	*Input::getContext()const
{
	return (this->_context);		
}

sf::Event			*Input::getEvent()const
{
	return (this->_event);
}

bool				Input::getClosureRequest()const
{
	return (this->_closureRequest);
}

void				Input::setButtonStat(int button, bool stat)
{
	if (button >= 0 && button < Input::Button::COUNT)
		this->_button[button] = stat;
}

void			Input::setContext(sf::RenderWindow *context)
{
	_context = context;
}

void			Input::setEvent(sf::Event *event)
{
	_event = event;
}
