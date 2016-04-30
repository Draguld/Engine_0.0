#include "Scene_Title.hpp"

Scene_Title::Scene_Title():
_win(0),
_input(0),
_vertices(sf::Quads, 0),
_texPath("textures/menu/basic.png"),
_texture(),
_position(0),
_texCoords(0)
{
		
}

Scene_Title::Scene_Title(sf::RenderWindow *win, Input *input):
_win(win),
_input(input),
_vertices(sf::Quads, 0),
_texPath("textures/menu/basic.png"),
_texture(),
_position(0),
_texCoords(0)
{
		
}

Scene_Title::~Scene_Title()
{
	this->_win = 0;
	this->_input = 0;
}

int					Scene_Title::play()
{
	bool	run;

	run = true;
	init();
	while (run)
	{
		_input->update();
		if (_input->getClosureRequest())
			run = false;
		_win->clear(sf::Color::Black);
		_win->draw(_vertices, &_texture);
		_win->display();
	}
	return (0);
}

bool				Scene_Title::init()
{
	sf::FloatRect		buffer(0, 0, 0, 0);
	sf::Vector2f		winSize(0, 0);
	if (!_texture.loadFromFile(_texPath))
		return (false);

	winSize = (sf::Vector2f)_win->getSize();
	_vertices.resize(24);
	//Background
	_position.push_back(sf::FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
	_texCoords.push_back(sf::FloatRect(0, 0, 160, 90));
	//Button newGame
	_position.push_back(sf::FloatRect(0.1f, 0.55f, 0.3f, 0.075f));
	_texCoords.push_back(sf::FloatRect(0, 90, 48, 12));
	//Button loadGame
	_position.push_back(sf::FloatRect(0.1f, 0.65f, 0.3f, 0.075f));
	_texCoords.push_back(sf::FloatRect(48, 90, 48, 12));
	//Button setting
	_position.push_back(sf::FloatRect(0.1f, 0.75f, 0.3f, 0.075f));
	_texCoords.push_back(sf::FloatRect(0, 102, 48, 12));
	//Button quit
	_position.push_back(sf::FloatRect(0.1f, 0.85f, 0.3f, 0.075f));
	_texCoords.push_back(sf::FloatRect(48, 102, 48, 12));
	//Cursor
	_position.push_back(sf::FloatRect(0.04f, 0.55f, 0.05f, 0.075f));
	_texCoords.push_back(sf::FloatRect(96, 90, 12, 12));

	for (unsigned int i = 0; i < 6; i++)
	{
		buffer = sf::FloatRect(_position[i].left * winSize.x,		//LEFT
							   _position[i].top * winSize.y,		//TOP
							   _position[i].width * winSize.x,		//WIDTH
							   _position[i].height * winSize.y);	//HEIGHT
		VertexUtils::position(&_vertices[i * 4], buffer);
		VertexUtils::texture(&_vertices[i * 4], _texCoords[i]);
	}
	return (true);
}
