#include <stdio.h>

#include "lab6.h"

/* Fully-implemented extract_float */

float float_add(float a, float b) {
    INTFLOAT x, y, result;
    int bit_sum = 0;
    float *sum;
    
    /* extract two's compliment components of the two given floats */
    extract_float(a, &x);
    extract_float(b, &y);
    printf("%X, %X\n", x.exponent, x.fraction);
    printf("%X, %X\n", y.exponent, y.fraction);


    if(x.exponent > y.exponent) {
	/* shift y fraction right and increase expononent until equal */
	while(x.exponent != y.exponent) {
	    y.fraction = y.fraction >> 1;
	    y.exponent = y.exponent + 1;
	}
    } else if(x.exponent < y.exponent) {
	/* same as above but for x */
	while(x.exponent != y.exponent) {
	    x.fraction = x.fraction >> 1;
	    x.exponent = x.exponent + 1;
	}
    } 
    
    if(x.exponent == y.exponent) {
	result.exponent = x.exponent + 1;
    } else {
	printf("Error: exponents not equal\n");
    }

    x.fraction = x.fraction >> 1;
    y.fraction = y.fraction >> 1;
    result.fraction = x.fraction + y.fraction;

    /* normalize result left shifting and decrementing exponent */
    if(result.fraction != 0) {
	while(
	      /* check if signed bit and adjacent are eqaual */
	      (result.fraction & 0xC0000000 == 0xC0000000) ||
	      (result.fraction & 0xC0000000 == 0)) {
		result.fraction = result.fraction << 1;
		result.exponent--;
	}
    }

    if(result.fraction == 0) {
	return 0;
    } else if (result.fraction < 0) {
	bit_sum |= 0x80000000;
	if(result.fraction == 0x80000000) {
	    result.fraction = result.fraction >> 1;
	    result.exponent++;
	    result.fraction = - result.fraction;
	}
    }

    printf("E: %d, F: %X\n", result.exponent, result.fraction);

    /* moving result into IEEE format */
    result.exponent += 126;
    result.fraction = result.fraction >> 8; /* only 8 for hidden 1 */
    result.exponent = result.exponent << 23;
    bit_sum |= result.exponent;
    bit_sum != result.fraction;

    return *((float*)&bit_sum);
}

float hardware_float_add(float a, float b) {
    return a + b;
}

void extract_float(float f, INTFLOAT_PTR xp)
{
    unsigned  int uintf;

    uintf = (unsigned int) *(unsigned int *) &f;  /* Get unsigned int version of float */

    if (uintf == 0)
	{
	    xp->fraction = 0;
	    xp->exponent = 0;
	    return;
	}

    /* extracting exponent */
    xp->exponent = ((int)((uintf & 0x7FFFFFFF) >> 23)) - 126;

    /* extracting fraction */
    xp->fraction = 0x00800000;
    xp->fraction = xp->fraction | uintf;
    xp->fraction = xp->fraction & 0x00FFFFFF;
    xp->fraction = xp->fraction << 7;

    /* testing signed bit */
    if(f < 0) {
	xp->fraction = -xp->fraction;
    }

    return;
}
