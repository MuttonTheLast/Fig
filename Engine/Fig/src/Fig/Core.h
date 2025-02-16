#pragma once

#ifdef FIG_BUILD_DLL
	#define FIG_API __declspec(dllexport)
#else
	#define FIG_API __declspec(dllimport)
#endif // FIG_BUILD_DLL
