#include "Scene.hpp"

Scene::Scene():
_win(0),
_input(0)
{
		
}

Scene::Scene(sf::RenderWindow *win, Input *input):
_win(win),
_input(input)
{
		
}

Scene::Scene(Scene const & rhs)
{
	*this = rhs;
}

Scene	&Scene::operator=(Scene const & rhs)
{
	this->_win = rhs.getContext();
	this->_input = rhs.getInput();
	return (*this);
}

Scene::~Scene()
{
	this->_win = 0;
	this->_input = 0;
}

void				Scene::setContext(sf::RenderWindow *window)
{
	this->_win = window;
}

void				Scene::setInput(Input *input)
{
	this->_input = input;
}

sf::RenderWindow	*Scene::getContext()const
{
	return (this->_win);
}

Input				*Scene::getInput()const
{
	return (this->_input);
}
