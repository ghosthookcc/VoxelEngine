#ifndef EXPORTLOGIC_H
#define EXPORTLOGIC_H

#ifdef MODULES_STATIC_DEFINE
#  define MODULES_EXPORT
#  define MODULES_NO_EXPORT
#else
#  ifndef MODULES_EXPORT
#    ifdef modules_EXPORTS
        /* building this library */
#      define MODULES_EXPORT __declspec(dllexport)
#    else
        /* using this library */
#      define MODULES_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef MODULES_NO_EXPORT
#    define MODULES_NO_EXPORT
#  endif
#endif

#ifndef MODULES_DEPRECATED
#  define MODULES_DEPRECATED __declspec(deprecated)
#endif

#ifndef MODULES_DEPRECATED_EXPORT
#  define MODULES_DEPRECATED_EXPORT MODULES_EXPORT MODULES_DEPRECATED
#endif

#ifndef MODULES_DEPRECATED_NO_EXPORT
#  define MODULES_DEPRECATED_NO_EXPORT MODULES_NO_EXPORT MODULES_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef MODULES_NO_DEPRECATED
#    define MODULES_NO_DEPRECATED
#  endif
#endif

#endif
