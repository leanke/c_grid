#ifndef TILE_H
#define TILE_H

#include "entity.h"
#include "object.h"
#include "item.h"

typedef struct {
    Entity *entity;
    Object *object;
    Item *items[5];
} Tile;

#endif // TILE_H
