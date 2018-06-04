#include <stdio.h>

#include "lab6.h"


/* Example test case 3.5 */

void add_float_test(float x) {
    INTFLOAT y;
    add_float(x, &y);
  
}

int main() {
    INTFLOAT x;
    unsigned int i;

    printf("Now do a performance test, repeating 1x10^9 times.\n");

    /* repeat count = 1000000000 = 1 x 10^9 = 1 billion times */

    for (i=0; i<1000000000; i++)
	{
	    /* add_float(); */
	}
    printf("Ending performance test.\n");
}

