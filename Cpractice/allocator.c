#include "allocator.h"
#include <stdlib.h>



Allocator* createAllocator(void)
{
	Allocator* allocator = (Allocator*)malloc(sizeof(Allocator));
	if (allocator) {
		allocator->malloc = TensorMalloc;
		allocator->realloc = TensorRealloc;
		allocator->free = TensorFree;
	}
	return allocator;
}

void* TensorMalloc(void* ctx, long size)
{
	void* ptr;

	if (size < 0) {
		printf("$ Torch: invalid memory size -- maybe an overflow?");
	}
	if (size == 0) {
		return NULL;
	}
	ptr = malloc(size);
	if (!ptr) {
		printf("$ Torch: not enough memory: you tried to allocate %dGB. Buy new RAM!", size / 1073741824);
	}
	return ptr;
}

void* TensorRealloc(void* ctx, void* ptr, long size)
{
	if (!ptr) {
		return (TensorMalloc(ctx, size));
	}
	if (size == 0) {

		return NULL;
	}
	if (size < 0) {
		printf("$ Torch: invalid memory size -- maybe an overflow?");
	}
	ptr = realloc(ptr, size);

	if (!ptr) {
		printf("$ Torch: not enough memory: you tried to allocate %dGB. Buy new RAM!", size / 1073741824);
	}
	return ptr;
}

void TensorFree(void* ctx, void* ptr)
{
	free(ptr);
}
