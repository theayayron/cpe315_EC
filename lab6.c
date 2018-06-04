#include <stdio.h>

#include "lab6.h"


/* Example test case 3.5 */

void extract_float_test(float x) {
  INTFLOAT y;
  extract_float(x, &y);
  printf("Float is: %3.1f Fraction is: 0x%08X, Exponent is: 0x%08X\n", x, y.fraction, y.exponent);
}

int main()
  {
    INTFLOAT x;
  unsigned int i;

  extract_float_test( 4.0);
  extract_float_test(1.0);
  extract_float_test(-4.0);
  extract_float_test(62.5);
  extract_float_test(-33.0);

  printf("Now do a performance test, repeating 1x10^9 times.\n");

/* repeat count = 1000000000 = 1 x 10^9 = 1 billion times */

  for (i=0; i<1000000000; i++)
     {
     extract_float( 3.3, &x);
     }
  printf("Ending performance test.\n");


  }

