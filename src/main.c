#include <stdio.h>
#include <ncurses.h>
#include "../include/grid.h"
#include "../include/entity.h"
#include "../include/item.h"
#include "../include/object.h"
#include "../include/tile.h"

void printGameArrayNcurses(GameArray *game) {
    clear();
    for (int i = 0; i < game->rows; i++) {
        for (int j = 0; j < game->cols; j++) {
            if (game->array[i][j].entity != NULL) {
                if (game->array[i][j].entity->name == "Player") {
                    mvprintw(i, j * 2, "P");
                } else {
                    mvprintw(i, j * 2, "E");
                }
            } else if (game->array[i][j].object != NULL) {
                mvprintw(i, j * 2, "O");
            } else if (game->array[i][j].items[0] != NULL) {
                mvprintw(i, j * 2, "I");
            } else {
                mvprintw(i, j * 2, ".");
            }
        }
    }
    refresh();
}

void printSkills(Entity *entity) {
    mvprintw(12, 0, "Skills:");
    mvprintw(13, 0, "Attack: %d", entity->skills[0]);
    mvprintw(14, 0, "Health: %d", entity->skills[1]);
    mvprintw(15, 0, "Defense: %d", entity->skills[2]);
    mvprintw(16, 0, "Woodcutting: %d", entity->skills[3]);
    mvprintw(17, 0, "Mining: %d", entity->skills[4]);
    refresh();
}

int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    printw("Welcome to the Grid Game!\n");
    refresh();
    
    GameArray game;
    initGameArray(&game, 10, 10);
    printGameArrayNcurses(&game);

    Entity player = {0, 0, "Player", 100, {NULL}, {10, 100, 5, 1, 1}};
    Entity enemy = {5, 5, "Enemy", 100, {NULL}, {10, 100, 5, 1, 1}};
    Item sword = {"Sword", 1, 10, 1, 0, 1};
    Object tree = {"Tree", 1, sword, 50};

    game.array[0][0].entity = &player;
    game.array[0][1].object = &tree;
    game.array[0][2].items[0] = &sword;
    game.array[5][5].entity = &enemy;

    printGameArrayNcurses(&game);
    printSkills(&player);

    int input;
    while (1) {
        int direction;

        input = getch();
        switch (input) {
            case 'w':
                direction = 0;
                break;
            case 's':
                direction = 1;
                break;
            case 'a':
                direction = 2;
                break;
            case 'd':
                direction = 3;
                break;
            case 'q':
                endwin();
                return 0;
        }
        game.array[player.y][player.x].entity = NULL;
        moveEntity(&player, direction);
        game.array[player.y][player.x].entity = &player;
        printGameArrayNcurses(&game);
        printSkills(&player);
    }

    endwin();
    return 0;
}
