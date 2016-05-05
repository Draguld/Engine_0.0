#ifndef		VERTEXUTILS_HPP
#define		VERTEXUTILS_HPP

#include "sfml.hpp"

class	VertexUtils
{
	public:
	static void				position(sf::Vertex *vertex, sf::FloatRect box);
	static void				position(sf::Vertex *vertex, sf::Vector2f position, sf::Vector2f size);
	static void				position(sf::Vertex *vertex, float left, float top, float width, float height);

	static void				texture(sf::Vertex *vertex, sf::FloatRect box);
	static void				texture(sf::Vertex *vertex, sf::Vector2f position, sf::Vector2f size);
	static void				texture(sf::Vertex *vertex, float left, float top, float width, float height);

	static void				color(sf::Vertex *vertex, sf::Color color, unsigned int n);

	static sf::FloatRect	getBox(sf::Vertex const *vertex);
	static sf::Vector2f		getPoint(sf::Vertex const *vertex);
	static sf::Color		getColor(sf::Vertex const *vertex);
};

#endif
