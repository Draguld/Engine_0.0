#ifndef			SCENE_HPP
#define			SCENE_HPP

#include "std.hpp"
#include "sfml.hpp"

#include "Input.hpp"

class	Scene
{
	public:
	Scene();
	Scene(sf::RenderWindow *win, Input *input);
	Scene(Scene const & rhs);
	Scene &operator=(Scene const & rhs);
	~Scene();

	void				setContext(sf::RenderWindow *window);
	void				setInput(Input *input);

	sf::RenderWindow	*getContext()const;
	Input				*getInput()const;

	virtual int			play()=0;

	protected:
	sf::RenderWindow	*_win;
	Input				*_input;
};	

#endif
