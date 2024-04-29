#pragma once

#include <iostream>
#include <memory>

typedef int PVResult;
typedef uint32_t uint;
typedef std::string string;

template<typename T>
using PV_REF = std::shared_ptr<T>;

template<typename T>
using PV_UNQ = std::unique_ptr<T>;

#ifdef PV_BUILD_DLL
	#define PV_API __declspec(dllexport)
#else
	#define PV_API __declspec(dllimport)
#endif

#ifndef _WIN32 or _WIN64
	#error Priviya Only Supports Windows!
#endif