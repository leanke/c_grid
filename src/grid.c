#include <stdio.h>
#include <stdlib.h>
#include "../include/grid.h"
#include "../include/tile.h"

void initGameArray(GameArray *game, int rows, int cols) {
    game->rows = rows;
    game->cols = cols;
    game->array = (Tile **)malloc(rows * sizeof(Tile *));
    for (int i = 0; i < rows; i++) {
        game->array[i] = (Tile *)malloc(cols * sizeof(Tile));
        for (int j = 0; j < cols; j++) {
            game->array[i][j].entity = NULL;
            game->array[i][j].object = NULL;
            for (int k = 0; k < 5; k++) {
                game->array[i][j].items[k] = NULL;
            }
        }
    }
}


