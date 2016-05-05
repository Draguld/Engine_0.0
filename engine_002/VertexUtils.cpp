#include "VertexUtils.hpp"

void			VertexUtils::position(sf::Vertex *vertex, sf::FloatRect box)
{
	vertex[0].position = sf::Vector2f(box.left,				box.top				);
	vertex[1].position = sf::Vector2f(box.left + box.width, box.top				);
	vertex[2].position = sf::Vector2f(box.left + box.width, box.top + box.height);
	vertex[3].position = sf::Vector2f(box.left,				box.top + box.height);
}

void			VertexUtils::position(sf::Vertex *vertex, sf::Vector2f p, sf::Vector2f s)
{
	vertex[0].position = sf::Vector2f(p.x		, p.y		);
	vertex[1].position = sf::Vector2f(p.x + s.x	, p.y		);
	vertex[2].position = sf::Vector2f(p.x + s.x	, p.y + s.y );
	vertex[3].position = sf::Vector2f(p.x		, p.y + s.y );
}

void			VertexUtils::position(sf::Vertex *vertex, float l, float t, float w, float h)
{
	vertex[0].position = sf::Vector2f(l		, t		);
	vertex[1].position = sf::Vector2f(l + w	, t		);
	vertex[2].position = sf::Vector2f(l + w	, t + h	);
	vertex[3].position = sf::Vector2f(l		, t + h	);
}

void			VertexUtils::texture(sf::Vertex *vertex, sf::FloatRect box)
{
	vertex[0].texCoords = sf::Vector2f(box.left,				box.top				);
	vertex[1].texCoords = sf::Vector2f(box.left + box.width, box.top				);
	vertex[2].texCoords = sf::Vector2f(box.left + box.width, box.top + box.height);
	vertex[3].texCoords = sf::Vector2f(box.left,				box.top + box.height);
}

void			VertexUtils::texture(sf::Vertex *vertex, sf::Vector2f p, sf::Vector2f s)
{
	vertex[0].texCoords = sf::Vector2f(p.x		, p.y		);
	vertex[1].texCoords = sf::Vector2f(p.x + s.x	, p.y		);
	vertex[2].texCoords = sf::Vector2f(p.x + s.x	, p.y + s.y );
	vertex[3].texCoords = sf::Vector2f(p.x		, p.y + s.y );
}

void			VertexUtils::texture(sf::Vertex *vertex, float l, float t, float w, float h)
{
	vertex[0].texCoords = sf::Vector2f(l		, t		);
	vertex[1].texCoords = sf::Vector2f(l + w	, t		);
	vertex[2].texCoords = sf::Vector2f(l + w	, t + h	);
	vertex[3].texCoords = sf::Vector2f(l		, t + h	);
}

void			VertexUtils::color(sf::Vertex *vertex, sf::Color c, unsigned int n)
{
	for (unsigned int i = 0; i < n; i++)
		vertex[i].color = c;		
}

sf::FloatRect	VertexUtils::getBox(sf::Vertex const *vertex)
{
	return (sf::FloatRect(vertex[0].position.x, vertex[0].position.y, vertex[2].position.x - vertex[0].position.x, vertex[2].position.y - vertex[0].position.y));		
}

sf::Vector2f	VertexUtils::getPoint(sf::Vertex const *vertex)
{
	return (vertex->position);		
}

sf::Color		VertexUtils::getColor(sf::Vertex const *vertex)
{
	return (vertex->color);		
}
