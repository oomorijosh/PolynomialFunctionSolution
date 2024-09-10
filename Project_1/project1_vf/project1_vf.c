/* project 1, version final (Older: version 1.1, 1.2, 1, 2)
 * Name: Joshua Omori
 * Class: EE 160
 * Final objective: Further split the project into separate modules (secant.c, myfunc.c, myfunc.h and secant.h).
 * Overall objective: Create a program that takes in a polynomial function and finds the root(s) of it.  This will be done in a table format.
 * Inputs: min, max, steps, A-F(coefficients), and choice (used for repeating the program).
 * Outputs: Questions asking for inputs, a table (x, y) with x values being from min-max with user input amount of steps, number of sign changes, and the root whenever it occurs.
 * Compile Date: Oct 24, 2021
 */


#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

//double myfunc(double A, double B, double C, double D, double E, double F, double min);
//double secant(double A, double B, double C, double D, double E, double F, double, double);

//secant.h and myfunc.h is needed to compile the functions
#include "secant.h"
#include "myfunc.h"

int main(void) {
   double min;
   double max;
   double steps;
   double A;
   double B;
   double C;
   double D;
   double E;
   double F;
   char choice;
   int done = FALSE;


// 1) Get necessary inputs (should be obvious which ones from printf statements)

   while (!done) {
      printf("Enter the coefficients for a polynomial of the form:\n");
      printf("   a + bx + cx^2 + dx^3 + ex^4 + fe^5\n\n");

      printf("Enter A B C D E F: ");
      scanf("%lf %lf %lf %lf %lf %lf", &A, &B, &C, &D, &E, &F);
      printf("\n");

      printf("The function is: %.2lf + %.2lf x + %.2lf x^2 + %.2lf x^3 + %.2lf x^4 + %.2lf x^5 \n\n", A, B, C, D, E, F);

      printf("The range of x-values for calculations of the table\n");
      printf("Enter start end: ");
      scanf(" %lf %lf", &min, &max);
      printf("\n");

      printf("Enter the number of intervals for your table: ");
      scanf(" %lf", &steps);
      printf("\n");


// 2) do some calculations to make the table work (<x> for interval calculation and <tempY> for determining when the sign changes)
      double x;
      x=(max-min)/steps;
      double tempY=1;
      if (myfunc(A,B,C,D,E,F,min)<0) {
         tempY=-1;
      }


// 3) make the table / majority of the calculations

      printf("   x-value      y-value\n");
      printf("   =======      =======\n");

      double x_0;
      int count=0;


   //repeats for <user input> amount of steps (+ 0.00001 vs just < is for a bug that doesn't repeat the x-value the right amount of times)

      for(min; min<=max+0.00001; min=min+x) {

   // done if y=0 (the root is x); adds one to the sign change counter
         if (myfunc(A,B,C,D,E,F,min)==0) {
            printf("%10.3lf  %11.3lf     <= the root located is: %.3lf\n", min, myfunc(A,B,C,D,E,F,min), min);
            count++;
         }
   // done if the sign remains the same
         else if (tempY*myfunc(A,B,C,D,E,F,min)>=0) {
            printf("%10.3lf  %11.3lf\n", min, myfunc(A,B,C,D,E,F,min));
         }

   // done if there is a sign change (potential bug fixed where this will activate more than once if y=0 with first if statement);
   // the root is calculated using the secant function.  counter for sign change goes up one
         else {
            //printf("***%lf %lf\n", x_0, min);
            printf("%10.3lf  %11.3lf     <= the root located is: %.3lf\n", min, myfunc(A,B,C,D,E,F,min), secant(A,B,C,D,E,F,x_0,min));
            count++;
         }

   // tempY is previous y when repeated; x_0 is previous x when repeated (serves different purposes throughout the function)
         tempY=myfunc(A,B,C,D,E,F,min);
         x_0=min;
      }
      printf("\n");


// 4) Displays the total sign change and asks if the whole process should be repeated

      printf("Total sign changes located on the table: %i\n\n", count);

      printf("Do you wish to change the search range for the table? (y/n): ");
      scanf(" %c", &choice);

      if (choice=='n'||choice=='N') {
         done=TRUE;
      }
      else {
         printf("\n==============================================================\n\n");
      }
   }
   return 0;
}
