#ifndef KALLOCATOR_H
#define KALLOCATOR_H

typedef typeof(sizeof(0)) size_t;

void* malloc(size_t size);
void free(void* ptr);

#endif //KALLOCATOR_H
