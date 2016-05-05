#ifndef		MAP_HPP
#define		MAP_HPP

#include "std.hpp"
#include "sfml.hpp"
#include "File.hpp"

class	Map : public sf::Drawable
{
	public:
	Map();
	virtual ~Map();

	bool				load(std::string file);

	private:
	virtual void		draw(sf::RenderTarget& target, sf::RenderStates states)const;

	protected:
	sf::VertexArray		_vertices;
	sf::Texture			_texture;

	std::string			_name;
	std::string			_texpath;

	sf::Vector2u		_size;
	sf::Vector2u		_tilesize;
	std::vector<u32>	_tileindex;	
};

#endif
