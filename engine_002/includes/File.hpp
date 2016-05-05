#ifndef		FILE_HPP
#define		FILE_HPP

#include "std.hpp"

class	File
{
	public:
	File();
	~File();

	bool					read(std::string path);
	std::string				find(std::string key);
	u32						u32FromString(std::string str, u32 n);
	std::vector<u32>		u32ArrayFromString(std::string str);

	protected:
	std::vector<std::string>	_data;
};

#endif
