#include<stdlib.h>
#include<stdio.h>

#include"testStack.h"
#include"testQueue.h"
#include"cuTest.h"

void RunAllTests(void) {
    // Create Suite
    CuString* output = CuStringNew();
    CuSuite* suite = CuSuiteNew();
    CuSuiteAddSuite(suite, TestStack());
    CuSuiteAddSuite(suite, TestQueue());

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
    RunAllTests();
	return 0;
}