#include<stdio.h>

/*Exercise 1-12.
  prints its input one word per line.*/

main()
{
  int c;

  for(c=0;(c=getchar())!=EOF;)
  {
    if(c==' '||c=='\t')
      putchar('\n');
    else
      putchar(c);
  }
}
