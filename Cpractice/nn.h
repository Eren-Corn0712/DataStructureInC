#pragma once
#ifndef NN_H
#define NN_H
#include "tensor.h"
// Forward declaration

typedef struct linear Linear;



struct linear
{
	int in_features;
	int out_features;
	Tensor* weight;
	Tensor* bias;
	Tensor* (*forward)(Linear*, Tensor*);
	void (*backward)(Tensor*);
};


Linear* createLinear(int in_features, int out_features, bool bias);

Tensor* forwardLinear(Linear* self, Tensor* input);

#endif // !NN_H
