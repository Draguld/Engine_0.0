#include "Map.hpp"

Map::Map():
_vertices(sf::Quads, 0),
_texture(),
_name("noname"),
_texpath("nopath"),
_size(0, 0),
_tilesize(0, 0),
_tileindex(0)
{
		
}

Map::~Map()
{
		
}

bool			Map::load(std::string file)
{
		
}
