#pragma once

#ifndef TENSOR_H
#define TENSOR_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "allocator.h"
// Forward declaration
typedef struct tensor Tensor;


struct tensor
{
    // pointer to myself
    Tensor* self;

    // size and shape infomation
    long* shape;
    long* stride;
    int dim;

    // data
    Allocator* allocator;
    
    // Operation and arguments;
};

Tensor* createTensor(long* shape, int size);

long* computeStride(long* shape, int size);
#endif // !TENSOR_H