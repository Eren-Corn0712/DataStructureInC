#include "nn.h"
#include "tensor.h"
#include <stdlib.h>


Linear* createLinear(int in_features, int out_features, bool bias)
{
	Linear* linear = (Linear*)malloc(sizeof(Linear));
	if (linear) {
		linear->in_features = in_features;
		linear->out_features = out_features;
		
		int weightShape[] = { out_features, in_features };
		linear->weight = createTensor(weightShape, 2, 1.0);

		int biasShape[] = { out_features };
		linear->bias = NULL;
		if (bias) {
			linear->bias = createTensor(biasShape, 1, 1.0);
		}

		linear->forward = forwardLinear;
		linear->backward = NULL;
	}
	return linear;
}

Tensor* forwardLinear(Linear* self, Tensor* input)
{
	Tensor* output = createTensor((int[]) { self->out_features }, 1, 0.0);
	Tensor* weight = self->weight;
	Tensor* bias = self->bias;
	weight->print(weight);
	bias->print(bias);

	for (int i = 0; i < self->out_features; i++) {
		double sumValue = 0.0;
		for (int j = 0; j < self->in_features; j++) {
			int x_index[] = { j };
			int w_index[] = { i, j };
			double x = input->get(input, x_index);
			double w = weight->get(weight, w_index);
			sumValue += w * x;
		}
		output->set(output, (int[]) { i }, sumValue);
	}
	return output;
}
