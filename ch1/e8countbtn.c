#include<stdio.h>

/*Exercise 1-8.
 *Count blanks,tabs,newlines.
 */

main()
{
  int blanks,tabs,newlines;
  int c;

  blanks=0;
  tabs=0;
  newlines=-1;

  while((c=getchar())!=EOF)
    {
      if(c==' ')
	blanks++;
      else if(c=='\t')
	tabs++;
      else if(c=='\n')
        newlines++;
    }
  
  printf("Blanks:%d\n",blanks);
  printf("Tabs:%d\n",tabs);
  printf("Newlines:%d\n",newlines);
}
