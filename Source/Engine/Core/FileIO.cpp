#include "FileIO.h"

namespace umbra
{
	std::string getFilePath()
	{
		return std::filesystem::current_path().string();
	}
}