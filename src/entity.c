#include <stdio.h>
#include "../include/entity.h"
#include "../include/grid.h"

void printEntity(Entity *entity) {
    printf("Entity: %s\n", entity->name);
    printf("Position: (%d, %d)\n", entity->x, entity->y);
    printf("Health: %d\n", entity->health);
    printf("Skills:\n");
    printf("Attack: %d\n", entity->skills[0]);
    printf("Health: %d\n", entity->skills[1]);
    printf("Defense: %d\n", entity->skills[2]);
    printf("Woodcutting: %d\n", entity->skills[3]);
    printf("Mining: %d\n", entity->skills[4]);
}
void moveEntity(Entity *entity, int direction) {
    switch (direction) {
        case 0:
            entity->y--;
            break;
        case 1:
            entity->y++;
            break;
        case 2:
            entity->x--;
            break;
        case 3:
            entity->x++;
            break;
    }
}
void recieveDamage(Entity *entity, int damage) {
    entity->health -= damage;
}
void attackEntity(Entity *attacker, Entity *defender) {
    recieveDamage(defender, attacker->skills[0]);
}
void pickUpItem(Entity *entity, Item *item) {
    for (int i = 0; i < 9; i++) {
        if (entity->inventory[i] == NULL) {
            entity->inventory[i] = item;
            break;
        }
    }
}
void dropItem(Entity *entity, Item *item) {
    for (int i = 0; i < 9; i++) {
        if (entity->inventory[i] == item) {
            entity->inventory[i] = NULL;
            break;
        }
    }
}
