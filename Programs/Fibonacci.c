#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define INPUTSIZE 46

time_t start, end;
double timeElapsed;
double i = 0, c;
 
double Fibonacci(double n)
{
   if ( n == 0 )
      return 0;
   else if ( n == 1 )
      return 1;
   else
   {
      //nice(-15);
      return ( Fibonacci(n-1) + Fibonacci(n-2) );
   }
} 

double main()
{
   
   start = clock();  
   for ( c = 1 ; c <= INPUTSIZE ; c++ )
   {
      Fibonacci(i);
      i++; 
   }
   end = clock();
   
   timeElapsed = (double) end - start;
    printf("Fibonacci : %f", timeElapsed);
    return timeElapsed;

}