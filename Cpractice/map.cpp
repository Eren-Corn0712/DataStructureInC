#include "map.h"
#include<stdlib.h>


MAP* createMAP(void)
{
    MAP* map = (MAP*)malloc(sizeof(MAP));
    if (map) {
        map->size = 0;
    }
    return map;
}

