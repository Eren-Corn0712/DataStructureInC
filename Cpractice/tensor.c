#include "tensor.h"
#include <stdio.h>
#include <stdlib.h>

Tensor* createTensor(int* shape, int dim, double val)
{
	Tensor* tensor = (Tensor*)malloc(sizeof(Tensor));
	if (tensor) {
		tensor->self = tensor;
		tensor->shape = shape;
		tensor->dim = dim;
		tensor->stride = computeStride(shape, dim);
        tensor->size = computeSize(shape, dim);
        tensor->data = (double*)malloc(sizeof(double) * tensor->size);
        for (int i = 0; i < tensor->size; i++) {
            tensor->data[i] = val;
        }
        
        // method
        tensor->getSize = getSize;
        tensor->_index = _index;
        tensor->set = set;
        tensor->get = get;
	}
	return tensor;
}

int* computeStride(const int* shape, int size) {
    // Check for invalid input
    if (shape == NULL || size == 0) {
        return NULL;
    }

    int* stride = (int*)malloc(sizeof(int) * size);

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
    return stride;
}


int computeSize(int* shape, int dim)
{
    if (shape == NULL) {
        return 0;
    }

    int size = 1;
    for (int i = 0; i < dim; i++) {
        size *= shape[i];
    }

    return size;
}


Tensor* getSelf(const Tensor* self)
{
    return self->self;
}

int getSize(const Tensor * self)
{
    return self->size;
}

int getDim(const Tensor* self)
{
    return self->dim;
}

int _index(Tensor* self, int* index)
{   
    
    int position = 0;
    for (int k = 0; k < self->dim - 1; k++) {
        position += (self->stride[k] * index[k]);
    }
    return position;
}


void set(Tensor* self, int* index, double val)
{
    int pos = self->_index(self, index);
    self->data[pos] = val;
}

double get(Tensor* self, int* index)
{
    int pos = self->_index(self, index);
    return self->data[pos];
}
