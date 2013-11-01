#include<stdio.h>

/* Exericse 1-5.
 * Print Fahrenheit-Celsius table
 * from 300 to 0, step by 20.
 */

main()
{
  int fahr;

  for (fahr = 300; fahr >=0; fahr = fahr -20)
  {
    printf("%3d\t%6.2f\n", fahr ,(5.0/9.0)*(fahr-32));  
  }
}
