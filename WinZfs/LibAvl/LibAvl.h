#pragma once

#ifdef LibAvl_EXPORTS
#define LibAvl_API __declspec(dllexport)
#else
#define LibAvl_API __declspec(dllimport)
#endif
