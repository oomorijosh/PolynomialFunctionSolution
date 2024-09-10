/* project 1, version 1.2 (Older: version 1.1)
 * Name: Joshua Omori
 * Class: EE 160
 * Current objective: Make the polynomial function so that it can take user input up to the 3rd power (assuming no - or fraction powers).
 * Overall objective: Create a program that takes in a polynomial function and finds the root(s) of it.  This will be done in a table format.
 * Inputs: min, max, steps, A-C(coefficients), and choice (used for repeating the program).
 * Outputs: Questions asking for inputs, a table (x, y) with x values being from min-max with user input amount of steps, number of sign changes, and the root whenever it occurs.
 * Compile Date: Oct 22, 2021
 */


#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

double myfunc(double A, double B, double C, double min);
double secant(double A, double B, double C, double, double);

int main(void) {
   double min;
   double max;
   double steps;
   double A;
   double B;
   double C;
   char choice;
   int done = FALSE;


// 1) Get nescessary inputs (should be obvious which ones from printf statemets)

   while (!done) {
      printf("Enter the coefficients for a polynomial of the form:\n");
      printf("   a + bx + cx^2\n\n");

      printf("Enter A B C: ");
      scanf("%lf %lf %lf", &A, &B, &C);
      printf("\n");

      printf("The function is: %.2lf + %.2lf x + %.2lf x^2 \n\n", A, B, C);

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
      if (myfunc(A,B,C,min)<0) {
         tempY=-1;
      }


// 3) make the table / majority of the calculations

      printf("   x-value      y-value\n");
      printf("   =======      =======\n");

      double x_0;
      int count=0;

   //repeats for <user input> amount of steps (+ 0.00001 vs just < is for a bug that doesn't repeat the x-value the right amount of times)
      for(min; min<=max+0.000001; min=min+x) {

      //done if y=0 (the root is x); adds one to the sign change counter
         if (myfunc(A,B,C,min)==0) {
            printf("%10.3lf  %11.3lf     <= the root located is: %.3lf\n", min, myfunc(A,B,C,min), min);
            count++;
         }

      //done if the sign remains the same
         else if (tempY*myfunc(A,B,C,min)>=0) {
            printf("%10.3lf  %11.3lf\n", min, myfunc(A,B,C,min));
         }

      //done if there is a sign change (potential bug fixed where this will activate more than once if y=0 with first if statement);
      //the root is caluclated using the secant function.  counter for sign change goes up one
         else {
            printf("%10.3lf  %11.3lf     <= the root located is: %.3lf\n", min, myfunc(A,B,C,min), secant(A,B,C,x_0,min));
            count++;
         }

      //tempY is previous y when repeated; x_0 is previous x when repeated (serves different purposes throuout the function)
         tempY=myfunc(A,B,C,min);
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


// calculates y from the coefficients of the polynomial function and x

double myfunc(double A, double B, double C, double min) {
   return (A) + (B*min) + (C*min*min);
}


//calculates the root from the coefficients of the polynomial function, x, and the previous x

double secant(double A, double B, double C, double x_0, double x_1) {
   double x_n;
   while (fabs(myfunc(A, B, C, x_1))>0.00001) {
         x_n = x_1 - myfunc(A, B, C, x_1) * (x_1 - x_0) / (myfunc(A, B, C, x_1) - myfunc(A, B, C, x_0));
         x_0 = x_1;
         x_1 = x_n;
   }
   return x_n;
}



