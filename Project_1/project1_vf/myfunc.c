//calculates y from the coefficients of the polynomial function and x
#include <math.h>
#include "myfunc.h"

double myfunc(double A, double B, double C, double D, double E, double F, double min) {
   return (A) + (B*min) + (C*pow(min,2)) + (D*pow(min,3)) + (E*pow(min,4)) + (F*pow(min,5));
}

