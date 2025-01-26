#ifndef GRID_H
#define GRID_H

#include "tile.h"

typedef struct {
    int rows;
    int cols;
    Tile **array; 
} GameArray;

void initGameArray(GameArray *game, int rows, int cols);
void printGameArray(GameArray *game);

#endif // GRID_H
