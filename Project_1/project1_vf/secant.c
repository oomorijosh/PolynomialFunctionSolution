//calculates the root from the coefficients of the polynomial function, x and the previous x 
//calls	on the myfunc()	function from project1_v2.c... secant.h is needed to do this

#include <math.h>
#include "myfunc.h"
#include "secant.h"

double secant(double A, double B, double C, double D, double E, double F, double x_0, double x_1) {
   double x_n;
   while (fabs(myfunc(A, B, C, D, E, F, x_1))>0.00001) {
         x_n = x_1 - myfunc(A, B, C, D, E, F, x_1) * (x_1 - x_0) / (myfunc(A, B, C, D, E, F, x_1) - myfunc(A, B, C, D, E, F, x_0));
         x_0 = x_1;
         x_1 = x_n;
   }
   return x_n;
}

