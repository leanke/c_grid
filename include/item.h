#ifndef ITEM_H
#define ITEM_H

typedef struct {
    char *name;
    int tier;
    int damage;
    int equippable;
    int stackable;
    int quantity;
} Item;

void printItem(Item *item);

#endif // ITEM_H
