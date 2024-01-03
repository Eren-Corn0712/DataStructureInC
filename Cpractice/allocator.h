#pragma once
#ifndef ALLOCATOR_H
#define ALLOCATOR_H


typedef struct allocator Allocator;

typedef struct allocator {
	void* (*malloc)(void*, long);
	void* (*realloc)(void*, void*, long);
	void (*free)(void*, void*);
} allocator;


Allocator* createAllocator(void);


static void* TensorMalloc(void* ctx,  long size);
static void* TensorRealloc(void* ctx, void* ptr, long size);
static void TensorFree(void* ctx, void* ptr);
#endif // !ALLOCATOR_H
