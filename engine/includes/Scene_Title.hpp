#ifndef			SCENE_TITLE_HPP
#define			SCENE_TITLE_HPP

#include "std.hpp"
#include "sfml.hpp"

#include "VertexUtils.hpp"
#include "Scene.hpp"

class	Scene_Title : public Scene
{
	public:
	Scene_Title();
	Scene_Title(sf::RenderWindow *win, Input *input);
	~Scene_Title();

	virtual int			play();
	

	protected:
	sf::RenderWindow			*_win;
	Input						*_input;
	
	private:
	bool						init();

	sf::VertexArray				_vertices;
	std::string					_texPath;
	sf::Texture					_texture;

	enum						Layout
	{
		Background = 0,
		ButtonNew,
		ButtonLoad,
		ButtonSetting,
		ButtonQuit,
		Cursor,
	};

	std::vector<sf::FloatRect>	_position;
	std::vector<sf::FloatRect>	_texCoords;
};	

#endif
