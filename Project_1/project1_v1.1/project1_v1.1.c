/* project 1, version 1.1
 * Name: Joshua Omori
 * Class: EE 160
 * Current objective: Make the basic coding outline that uses the predetermined function: 21 - 10x +x^2
 * Overall objective: Create a program that takes in a polynomial function and finds the root(s) of it.  This will be done in a table format.
 * Inputs: min, max, steps, and choice (used for repeating the program).
 * Outputs: Questions asking for inputs, a table (x, y) with x values being from min-max with user input amount of steps, number of sign changes, and the root whenever it occurs.
 * Compile Date: Oct 20, 2021 
 */


#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

double myfunc(double min);
double secant(double, double);

int main(void) {
   double min;
   double max;
   double steps;
   char choice;
   int done = FALSE;


// 1) Get nescessary inputs (should be obvious which ones from printf statemets)

   while (!done) {
      printf("The function is: 21 - 10x +x^2\n\n");

      printf("The range of x-values for calculations of the table\n");
      printf("Enter start end: ");
      scanf(" %lf %lf", &min, &max);
      printf("\n");

      printf("Enter the number of intervals for your table: ");
      scanf(" %lf", &steps);
      printf("\n");

// 2) do some calculations to make the table work (<x> for interval calculation and <tempY> for determining when the sign changes)

      double x = (max-min)/steps;
      double tempY=1;
      if (myfunc(min)<0) {
         tempY=-1;
      }


// 3) make the table / majority of the calculations

      printf("   x-value      y-value\n");
      printf("   =======      =======\n");

      double x_0;
      int count=0;

   //repeats for <user input> amount of steps (+ 0.00001 vs just < is for a bug that doesn't repeat
      for(min; min<=max+0.00001; min=min+x) {

      //done if y=0 (the root is x); adds one to the sign change counter
        if (myfunc(min)==0) {
            printf("%10.3lf  %11.3lf     <= the root located is: %.3lf\n", min, myfunc(min), min);
            count++;

      //done if the sign remains the same
         }
         else if(tempY*myfunc(min)>=0) {
            printf("%10.3lf  %11.3lf\n", min, myfunc(min));
         }

      //done if there is a sign change (potential bug fixed where this will activate more than once if y=0 with first if statement);
      //the root is caluclated using the secant function.  counter for sign change goes up one
         else {
            printf("%10.3lf  %11.3lf     <= the root located is: %.3lf\n", min, myfunc(min), secant(x_0,min));
            count++;
         }

      //tempY is previous y when repeated; x_0 is previous x when repeated (serves different purposes throuout the function)
         tempY=myfunc(min);
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

double myfunc(double min) {
   return 21 - (10*min) + (min*min);
}


//calculates the root from the coefficients of the polynomial function, x, and the previous x

double secant(double x_0, double x_1) {
   double x_n;
   while (fabs(myfunc(x_1))>0.00001) {
         x_n = x_1 - myfunc(x_1) * (x_1 - x_0) / (myfunc(x_1) - myfunc(x_0));
         x_0 = x_1;
         x_1 = x_n;
   }
   return x_n;
}

