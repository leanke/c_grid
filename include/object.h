#ifndef OBJECT_H
#define OBJECT_H

#include "item.h"

typedef struct {
    char *name;
    int tier;
    Item resource;
    int health;
} Object;

void printObject(Object *object);

#endif // OBJECT_H
