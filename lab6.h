/* structure for a 2's complement floating point number */

typedef struct _intfloat
	{
	int fraction;
	int exponent;
	} INTFLOAT, *INTFLOAT_PTR;


/* function definition for extract_float */

void extract_float(float, INTFLOAT_PTR);

