#pragma once

#ifndef TENSOR_H
#define TENSOR_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
// Forward declaration
typedef struct tensor Tensor;

struct tensor
{
    // pointer to myself
    Tensor* self;

    // size and shape infomation
    int* shape;
    int* stride;
    int size; // total elements
    int dim;

    // Storage
    double* data;

    // Method 
    int (*getSize)(Tensor*);
    int (*_index)(Tensor*, int*);

    int (*set)(Tensor*, int*, double);
    int (*get)(Tensor*, int*);
};

Tensor* createTensor(int* shape, int dim, double val);


int* computeStride(int* shape, int size);
int computeSize(int* shape, int dim);



// access attribute method
Tensor* getSelf(const Tensor* self);
int getSize(const Tensor* self);
int getDim(const Tensor* self);
static int _index(Tensor* self, int* index);
void set(Tensor* self, int* index, double val);
double get(Tensor* self, int* index);
#endif // !TENSOR_H