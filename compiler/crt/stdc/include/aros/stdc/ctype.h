#ifndef _STDC_CTYPE_H_
#define _STDC_CTYPE_H_

/*
    Copyright � 1995-2025, The AROS Development Team. All rights reserved.
    $Id$

    Desc: ANSI-C header file ctype.h
    Lang: english
*/

#include <aros/system.h>

#ifdef __cplusplus
extern "C" {
#endif

#define _ISupper    0x0001  /* UPPERCASE */
#define _ISlower    0x0002  /* lowercase */
#define _ISalpha    0x0004  /* a-y */
#define _ISdigit    0x0008  /* 0-9 */
#define _ISxdigit   0x0010  /* 0-9, a-f, A-F */
#define _ISspace    0x0020  /* Space, Tab, CR, LF, FF */
#define _ISprint    0x0040  /* 32-126, 160-255 */
#define _ISgraph    0x0080  /* [] */
#define _ISblank    0x0100  /* Space, Tab */
#define _IScntrl    0x0200  /* 0-31, 127 */
#define _ISpunct    0x0400  /* .,:;!? */
#define _ISalnum    (_ISalpha | _ISdigit)

extern const unsigned short int * const * const __ctype_b_ptr;
extern const unsigned char     * const * const __ctype_toupper_ptr;
extern const unsigned char     * const * const __ctype_tolower_ptr;

#define _istype(c, type) \
    ((*__ctype_b_ptr)[(unsigned char)(c)] & (unsigned short)(type))

#if !defined(STDC_NOINLINE) && !defined(STDC_NOINLINE_CTYPE)
#define __ctype_make_func(__name__, __body__)    \
__header_inline int __name__(int c)  \
{ return __body__; }
#else
#define __ctype_make_func(__name__, __body__)    \
__BEGIN_DECLS                          \
int __name__(int c); \
__END_DECLS
#endif

/* ISO C Standard Functions */
__ctype_make_func(isupper,  _istype(c, _ISupper))
__ctype_make_func(islower,  _istype(c, _ISlower))
__ctype_make_func(isalpha,  _istype(c, _ISalpha))
__ctype_make_func(isdigit,  _istype(c, _ISdigit))
__ctype_make_func(isxdigit, _istype(c, _ISxdigit))
__ctype_make_func(isspace,  _istype(c, _ISspace))
__ctype_make_func(isprint,  _istype(c, _ISprint))
__ctype_make_func(isgraph,  _istype(c, _ISgraph))
__ctype_make_func(iscntrl,  _istype(c, _IScntrl))
__ctype_make_func(ispunct,  _istype(c, _ISpunct))
__ctype_make_func(isalnum,  _istype(c, _ISalnum))

__ctype_make_func(toupper,  (*__ctype_toupper_ptr)[(unsigned char)(c)])
__ctype_make_func(tolower,  (*__ctype_tolower_ptr)[(unsigned char)(c)])

/* POSIX and GNU Extensions */
#if defined(_POSIX_C_SOURCE) || defined(_GNU_SOURCE)

# ifndef isblank
__ctype_make_func(isblank,  _istype(c, _ISblank))
# endif

# ifndef isascii
__ctype_make_func(isascii,  ((unsigned char)(c) <= 0x7f))
# endif

# ifndef toascii
__ctype_make_func(toascii,  ((c) & 0x7f))
# endif

#endif /* POSIX/GNU/AROS */

#define _toupper(c) toupper(c)
#define _tolower(c) tolower(c)

#ifdef __cplusplus
}
#endif

#endif /* _STDC_CTYPE_H_ */
