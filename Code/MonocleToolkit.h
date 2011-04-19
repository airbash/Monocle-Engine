#pragma once

#include "Macros.h"
#include <string>

namespace Monocle
{
	//Time in seconds that has passed since the last frame
	extern double deltaTime;	

	//Time in seconds since game started
	extern double timeSinceStart;

	//Math symbol PI
	extern const float pi;

	//Convert radians to degrees
	extern const float rad2Deg;

	//Convert degrees to radians
	extern const float deg2Rad;

	// open a local file or remote URL
	void OpenURL(const std::string &url);
	std::string GetWorkingDirectory();
	void ForEachFile(const std::string &path, const std::string &type, void callback(const std::string &filename, intptr_t param), intptr_t param);
}
