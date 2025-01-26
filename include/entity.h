#ifndef ENTITY_H
#define ENTITY_H

#include "item.h"

typedef struct {
    int x;
    int y;
    char *name;
    int health;
    Item *inventory[9];
    int skills[5];
} Entity;

void printEntity(Entity *entity);
void moveEntity(Entity *entity, int direction);
void recieveDamage(Entity *entity, int damage);
void attackEntity(Entity *attacker, Entity *defender);
void pickUpItem(Entity *entity, Item *item);
void dropItem(Entity *entity, Item *item);

#endif // ENTITY_H
