#include <stdio.h>

#include "lab6.h"

/* Fully-implemented extract_float */

float float_add(float a, float b) {
    INTFLOAT x, y, result;
    float sum = 0;
    unsigned int *sum_ptr = &sum;
    
    /* extract two's compliment components of the two given floats */
    extract_float(a, &x);
    extract_float(b, &y);

    if(x.exponent > y.exponent) {
	/* shift y fraction right and increase expononent until equal */
    } else if(x.exponent < y.exponent) {
	/* same as above but for x */
    } 
    
    if(x.exponent == y.exponent) {
	result.exponent = x.exponent + 1;
    } else {
	printf("Error: exponents not equal\n");
    }

    a.fraction = a.fraction >> 1;
    b.fraction = b.fraction >> 1;
    result.fraction = a.fraction + b.fraction;

    /* normalize result left shifting and decrementing exponent */

    if(result.fraction == 0) {
	return 0;
    } else if (result.fraction < 0) {
	float_result |= 0x80000000;
	if(result.fraction == 0x80000000) {
	    result.fraction = result.fraction >> 1;
	    result.exponent++;
	    result.fraction = - result.fraction;
	}
    }

    /* copy fraction field from bits after hidden 1 */
    result.exponent += 126;
    /* move fields into correct positions */

    return 0;
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

