#ifndef MAP_HPP
#define MAP_HPP

#include "SFML_generic.hpp"
#include "ftcpp.hpp"
#include "Setting.hpp"

class Map : public sf::Drawable, public sf::Transformable
{
	public:

	Map();
	virtual ~Map();
	
	void			getBounding(sf::Vector2u tileSize, const int *BoundTiles, unsigned int width, unsigned int height);
	bool			loadFromFile(std::string filePath);

	private:

	virtual void	draw(sf::RenderTarget& target, sf::RenderStates states) const;
	bool			load(std::string texturePath, sf::Vector2u tilesize, const int *tiles, unsigned int width, unsigned height);

	public:

	sf::VertexArray	m_vertices;
	sf::VertexArray m_bounding;
	sf::Texture		m_texture;
	unsigned int	m_boundNb;
};

#endif
