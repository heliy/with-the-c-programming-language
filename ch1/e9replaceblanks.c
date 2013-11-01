#include<stdio.h>

/*Exercise 1-9.
 *Repalce blanks by a blank.
 */

main()
{
  int c;
  int blankflag=0;
  for(c=0;(c=getchar())!=EOF;)
  {
    if(c==' ')
    {
      if(blankflag==0)
      {
        blankflag=1;
        putchar(' ');
      }
    }
    else
    {
      blankflag=0;
      putchar(c);
    }
  }
}
