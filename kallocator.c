#include "kallocator.h"

#include <stdio.h>
#include <dlfcn.h>

void* malloc(size_t size) {
    static void* (*libc_malloc)(size_t) = NULL;

    if (libc_malloc == NULL) {
        libc_malloc = dlsym(RTLD_NEXT, "malloc");
        if (libc_malloc == NULL) {
            fprintf(stderr, "missing libc:malloc\n");
        }
    }

    void* result = libc_malloc(size);

    fprintf(stderr, "malloc(%zu): %p\n", size, result);

    return result;
}

void free(void* ptr) {
    static void (*libc_free)(void*) = NULL;

    if (libc_free == NULL) {
        libc_free = dlsym(RTLD_NEXT, "free");
        if (libc_free == NULL) {
            fprintf(stderr, "missing libc:free\n");
        }
    }

    libc_free(ptr);

    fprintf(stderr, "free(%p)\n", ptr);
}
