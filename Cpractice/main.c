#include<stdlib.h>
#include<stdio.h>

#include"testStack.h"
#include"testQueue.h"
#include"testPair.h"
#include"cuTest.h"

#include "tensor.h"

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
    long shape[] = {2, 5, 5};
    Tensor* tensor = createTensor(shape, 3);
	return 0;
}