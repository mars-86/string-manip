#ifndef _LIB_STR_MANIP_INCLUDED_H_
#define _LIB_STR_MANIP_INCLUDED_H_

#ifdef _WIN32
 #if defined __MINGW32__ || defined __MINGW64__
  #include "sys/win32/mingw/proto.h"
 #else

 #endif // __MINGW32__ || __MINGW64__
#else
 #include "sys/linux/proto.h"
#endif // _WIN32

#endif // _LIB_STR_MANIP_INCLUDED_H_
