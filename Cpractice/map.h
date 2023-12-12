#pragma once
#ifndef MAP_H
#define MAP_H

/*forward delaration*/
typedef struct map_node MAP_NODE;
typedef struct map MAP;

struct map_node 
{
	void* key;
	void* value;
};

struct map
{
	int size;
};

MAP* createMAP(void);

#endif // !MAP_H
