#include "tensor.h"
#include <stdio.h>
#include <stdlib.h>

Tensor* createTensor(long* shape, int dim)
{
	Tensor* tensor = (Tensor*)malloc(sizeof(Tensor));
	if (tensor) {
		tensor->self = tensor;
		tensor->shape = shape;
		tensor->dim = dim;
		tensor->stride = computeStride(shape, dim);
        tensor->allocator = createAllocator();
	}
	return tensor;
}

long* computeStride(const long* shape, int size) {
    // Check for invalid input
    if (shape == NULL || size == 0) {
        return NULL;
    }

    long* stride = (long*)malloc(sizeof(long) * size);

    // Check for memory allocation failure
    if (stride == NULL) {
        return NULL;
    }


    for (int i = size - 1; i >= 0; i--)
    {
        if (i == size - 1) {
            stride[i] = 1;
        }
        else {
            stride[i] = shape[i + 1] * stride[i + 1];
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("%ld\t", stride[i]);
    }

    return stride;
}