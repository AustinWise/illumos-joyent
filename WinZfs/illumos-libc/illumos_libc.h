#pragma once

#ifdef illumos_libc_EXPORTS
#define illumos_libc_API __declspec(dllexport)
#else
#define illumos_libc_API __declspec(dllimport)
#endif
