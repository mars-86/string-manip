#ifndef _LIB_BYTE_COPY_INCLUDED_H_
#define _LIB_BYTE_COPY_INCLUDED_H_

#define COPY_BYTES_FWD(dest, src)   \
    do {                            \
        while (*src != '\0')        \
            *dest++ = *src++;       \
    } while (0)

#endif // _LIB_BYTE_COPY_INCLUDED_H_
