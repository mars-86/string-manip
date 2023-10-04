#ifndef __LIB_STR_MANIP_INCLUDED_H__
#define __LIB_STR_MANIP_INCLUDED_H__

#ifdef _WIN32
 #if defined __MINGW32__ || defined __MINGW64__
  #include "sys/win32/mingw/str_manip.h"
 #else

 #endif // __MINGW32__ || __MINGW64__
#else
 #include "sys/linux/str_manip.h"
#endif // _WIN32

#endif // __LIB_STR_MANIP_INCLUDED_H__
