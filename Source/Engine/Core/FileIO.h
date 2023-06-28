#pragma once
#include <filesystem> //apart of new C++
#include <string>

//dont use using namespace std in headers, can get confusing
//forces anyone who uses the header to ALSO use the namespace std


namespace umbra
{
	std::string getFilePath();

}