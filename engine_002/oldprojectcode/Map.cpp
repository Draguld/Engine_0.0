#include "Map.hpp"

	Map::Map()
	{
			
	}
	
	Map::~Map()
	{
			
	}

	void	Map::getBounding(sf::Vector2u tileSize, const int *boundTiles, unsigned int width, unsigned int height)
	{
		int		boundNb = 0;
		int		pos = 0;
		for (unsigned int k = 0; k < width * height; k++)
		{
			boundNb += boundTiles[k];
		}
		m_boundNb = boundNb;
		m_bounding.setPrimitiveType(sf::Quads);
		m_bounding.resize((boundNb)* 4);

		for (unsigned int i = 0; i < width; i++)
			for (unsigned int j = 0; j < height; j++)
			{
				int	tileNumber = boundTiles[i + j * width];
				if (tileNumber == 1)
				{
					sf::Vertex* quads = &m_bounding[(pos) * 4];

					quads[0].position = sf::Vector2f (i * tileSize.x, j * tileSize.y);
					quads[1].position = sf::Vector2f ((i + 1) * tileSize.x, j * tileSize.y);
					quads[2].position = sf::Vector2f ((i + 1) * tileSize.x, (j + 1) * tileSize.y);
					quads[3].position = sf::Vector2f (i * tileSize.x, (j + 1) * tileSize.y);
					pos++;
				}
			}
	}
// aditioner toute les valeur du tableau de int pour conaitre le nombre de colision

	bool	Map::load(std::string texturePath, sf::Vector2u tileSize, const int *tiles, unsigned int width, unsigned int height)
	{
		if (!m_texture.loadFromFile(texturePath))
			return (false);

		m_vertices.setPrimitiveType(sf::Quads);
		m_vertices.resize(width * height * 4);

		for (unsigned int i = 0; i < width; i++)
			for (unsigned int j = 0; j < height; j++)
			{
				int tileNumber = tiles[i + j * width];
				
				int tu = tileNumber % (m_texture.getSize().x / tileSize.x);
				int tv = tileNumber / (m_texture.getSize().x / tileSize.x);
				
				sf::Vertex* quads =  &m_vertices[(i + j * width) * 4];
				
				quads[0].position = sf::Vector2f (i * tileSize.x, j * tileSize.y);
				quads[1].position = sf::Vector2f ((i + 1) * tileSize.x, j * tileSize.y);
				quads[2].position = sf::Vector2f ((i + 1) * tileSize.x, (j + 1) * tileSize.y);
				quads[3].position = sf::Vector2f (i * tileSize.x, (j + 1) * tileSize.y);

				quads[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
				quads[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
				quads[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
				quads[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
			}
	return (true);
	}

	bool	Map::loadFromFile(std::string filePath)
	{
		Setting			reader;
		std::string		texPath;
		int				*tiles;
		int				*boundTiles;
		sf::Vector2u	tileSize;
		sf::Vector2u	tileNb;
		std::string		buffer;
		std::string		minibuf;
		int				i;
		int				k;

		if (!reader.readSetting(filePath))
			return (false);
		if (!reader.isValidSetting("[TEXTURE_PATH]"))
			return (false);
		if (!reader.isValidSetting("[TILESIZE_X]") || !reader.isValidSetting("[TILESIZE_Y]"))
			return (false);
		if (!reader.isValidSetting("[NB_TILE_X]") || !reader.isValidSetting("[NB_TILE_Y]"))
			return (false);
		if (!reader.isValidSetting("[LEVEL]"))
			return (false);
		texPath = reader.getSetting_str("[TEXTURE_PATH]");
		tileSize.x = reader.getSetting_nbr("[TILESIZE_X]");
		tileSize.y = reader.getSetting_nbr("[TILESIZE_Y]");
		tileNb.x = reader.getSetting_nbr("[NB_TILE_X]");
		tileNb.y = reader.getSetting_nbr("[NB_TILE_Y]");
		tiles = new int [tileNb.x * tileNb.y];
		buffer = reader.getSetting_str("[LEVEL]");
		i = 0;
		k = 0;
		while (buffer[i] != '\0')
		{
			while (buffer[i] >= '0' && buffer[i] <= '9')
			{
				minibuf += buffer[i];
				i++;
			}
			if (!minibuf.empty() && k < (int)tileNb.x * (int)tileNb.y)
			{
				tiles[k] = ftcpp_atoi(minibuf.substr(0, minibuf.length()));
				minibuf.clear();
				k++;
			}
			i++;
		}
		boundTiles = new int [tileNb.x * tileNb.y];
		buffer = reader.getSetting_str("[BOUNDING]");
		i = 0;
		k = 0;
		while (buffer[i] != '\0')
		{
			if (buffer[i] >= '0' && buffer[i] <= '1')
			{
				if (k < (int)tileNb.x * (int)tileNb.y)
					boundTiles[k] =	buffer[i] - '0';
				k++;
			}
			i++;		
		}
		getBounding(tileSize, boundTiles, tileNb.x, tileNb.y);
		if(!load(texPath, tileSize, tiles, tileNb.x, tileNb.y))
		{
			delete[] tiles;
			delete[] boundTiles;
			tiles = 0;
			boundTiles = 0;
			return (false);
		}
		delete[] tiles;
		delete[] boundTiles;
		tiles = 0;
		boundTiles = 0;
		return (true);
	}

	void	Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		states.texture = &m_texture;
		target.draw(m_vertices, states);		
	}
