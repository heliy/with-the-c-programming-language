#include<stdio.h>

/*Exercise 1-10.
 *Make tabs and backspaces visible.
 */

main()
{
  int c;

  for(c=0;(c=getchar())!=EOF;)
  {
    if(c=='\t')
      printf("\\t");
    else if(c=='\b')
      printf("\\b");
    else
      putchar(c);
  }
}
