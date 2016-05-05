#include "File.hpp"

File::File():
_data()
{
		
}

File::~File()
{
		
}

bool			File::read(std::string path)
{
	std::ifstream				flux_in;
	std::string					buffer;
	std::string					longbuffer;

	if (access(path.c_str(), F_OK | R_OK) == -1)
		return (false);
	//READ and stock in _data//
	flux_in.open(path, std::ios::in);
	if (!flux_in)
		return (false);
	_data.clear();
	buffer.clear();
	longbuffer.clear();
	while (std::getline(flux_in, buffer))
	{
		if (buffer[buffer.size() - 1] == '\\')
		{
			while (buffer[buffer.size() - 1] == '\\')
			{
				buffer.erase(buffer.size() - 1, 1);
				longbuffer += buffer;
				std::getline(flux_in, buffer);
			}
			longbuffer += buffer;
			_data.push_back(longbuffer);
			longbuffer.clear();
		}
		_data.push_back(buffer);
	}
	flux_in.close();
	return (true);
}

std::string			File::find(std::string key)
{
	for (u32 i = 0; i < _data.size(); i++)
	{
		if (_data[i].find(key) != (size_t) -1)
			return (_data[i].substr(key.size()));
	}
	return ("");
}

u32					File::u32FromString(std::string str, u32 n)
{
	u32		buffer = 0;
	u32		cn = 0;

	if (n == 0)
		n = 1;
	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			cn++;
			while (str[i] >= '0' && str[i] <= '9')
			{
				buffer *= 10;
				buffer += (str[i] - '0');
				i++;
			}
			if (cn == n)
				return (buffer);
			else
				buffer = 0;
		}
	}
	return ((u32)-1);
	
}

std::vector<u32>	File::u32ArrayFromString(std::string str)
{
	std::vector<u32>	data(0);
	u32					buffer = 0;

		for (u32 i = 1; (buffer = u32FromString(str, i)) != (u32) - 1; i++)
			data.push_back(buffer);
	return (data);
}
