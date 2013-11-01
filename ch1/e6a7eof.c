#include<stdio.h>

/*Exercise 1-6 and 1-7.
 *Verify the exprression `getchar()!=EOF` is 0 or 1.
 *Print the value of EOF.
 */

main()
{
  int c;
  printf("Try C-c or/and C-d to break input...\n");
  c=(getchar()!=EOF);
  printf("%i\n",EOF);
  printf("%d\n",c);
}

/* `getchar()!=EOF` is 0.
 * EOF value is -1 
 */ 
