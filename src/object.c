#include <stdio.h>
#include "../include/object.h"

void printObject(Object *object) {
    printf("Object: %s\n", object->name);
    printf("Tier: %d\n", object->tier);
    printf("Resource: %s\n", object->resource.name);
    printf("Health: %d\n", object->health);
}
