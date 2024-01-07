#include "nn.h"
#include "tensor.h"
#include <stdlib.h>


Linear* createLinear(int in_features, int out_features, bool bias)
{
	Linear* linear = (Linear*)malloc(sizeof(Linear));
	if (linear) {
		linear->in_features = in_features;
		linear->out_features = out_features;
		linear->weight = createTensor(
			(int[]) {out_features, in_features},
			2,
			1.0
		);
		linear->bias = NULL;
		if (bias) {
			linear->bias = createTensor(
				(int[]) {out_features},
				1,
				1.0
			);
		}

		linear->forward = forwardLinear;
		linear->backward = NULL;
	}
	return linear;
}

Tensor* forwardLinear(Linear* self, Tensor* input)
{
	Tensor* output = createTensor(
		(int[]) {self->out_features},
		1,
		0.0
	);

	for (int i = 0; i < self->out_features; i++) {
		double out = 0.0;
		for (int j = 0; j < self->in_features; j++) {
			double x = input->get(input, (int[]) { j });
			double y = self->weight->get(self->weight, (int[]) {i, j});
			out += (x * y);
		}
		// Add bias if available
		if (self->bias != NULL) {
			out += self->bias->get(self->bias, (int[]) { i });
		}
		printf("out = %d\n", out);
		output->set(output, (int[]) {i}, out);
	}

	return output;
}
