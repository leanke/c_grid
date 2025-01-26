#include <stdio.h>
#include "../include/tile.h"

void printTile(Tile *tile) {
    if (tile->entity) {
        printEntity(tile->entity);
    }
    if (tile->object) {
        printObject(tile->object);
    }
    for (int i = 0; i < 5; i++) {
        if (tile->items[i]) {
            printItem(tile->items[i]);
        }
    }
}
