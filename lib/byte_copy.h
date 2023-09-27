#ifndef __LIB_BYTE_COPY_INCLUDED_H__
#define __LIB_BYTE_COPY_INCLUDED_H__

#define COPY_BYTES_FWD(dest, src)   \
    do {                            \
        while (*src != '\0')        \
            *dest++ = *src++;       \
    } while (0)

#endif // __LIB_BYTE_COPY_INCLUDED_H__
