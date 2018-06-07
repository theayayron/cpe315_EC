#include <stdio.h>

#include "lab6.h"


/* Example test case 3.5 */

void add_float_test(float x, float y) {
    float sum;
    sum = float_add(x, y);
    printf("%f + %f = %f\n", x, y, sum);
}

int main() {
    INTFLOAT x;
    unsigned int i;

    printf("Test Cases: \n");
    add_float_test(1.35, 2.75);
    add_float_test(2.5, -3.0);
    add_float_test(62.5, -62.5);

    

    printf("Now do a performance test, repeating 1x10^9 times.\n");

    /* repeat count = 1000000000 = 1 x 10^9 = 1 billion times */
    /*
    for (i=0; i<1000000000; i++)
	{
	    float_add(2.0, 2.0);
	}
    printf("Ending performance test.\n");
    */
}

