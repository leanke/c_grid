#include <stdio.h>
#include "../include/item.h"

void printItem(Item *item) {
    printf("Item: %s\n", item->name);
    printf("Tier: %d\n", item->tier);
    printf("Damage: %d\n", item->damage);
    printf("Equippable: %d\n", item->equippable);
    printf("Stackable: %d\n", item->stackable);
    printf("Quantity: %d\n", item->quantity);
}
