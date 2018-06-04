#include <stdio.h>

#include "lab6.h"

/* Fully-implemented extract_float */


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

