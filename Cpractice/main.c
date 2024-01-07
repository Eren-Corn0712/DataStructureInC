#include<stdlib.h>
#include<stdio.h>

#include"testStack.h"
#include"testQueue.h"
#include"testPair.h"
#include"cuTest.h"

#include "tensor.h"
#include "nn.h"
void RunAllTests(void) {
    // Create Suite
    CuString* output = CuStringNew();
    CuSuite* suite = CuSuiteNew();
    CuSuiteAddSuite(suite, TestStack());
    CuSuiteAddSuite(suite, TestQueue());
    CuSuiteAddSuite(suite, TestPair());

    // Run the tests
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);

    // Cleanup
    CuSuiteDelete(suite);
    CuStringDelete(output);
}

int main() {
    Tensor* input = createTensor((int[]) {10}, 1, 1.0);

    Linear* ll = createLinear(10, 20, true);

    Tensor* output = ll->forward(ll, input);

    printf("Debug");
    return 0;
}