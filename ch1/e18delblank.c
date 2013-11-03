#include<stdio.h>
#define MAXLINE 1000

int mygetline(char line[], int maxline);

/*Exercise 1-18
  remove trailing blanks anf tabs from each line
  and delete entrely blank ines. */

main()
{
  int len;
  char line[MAXLINE];

  while((len=mygetline(line,MAXLINE))>0)
    {
      printf("%d\n",len);
      for(;line[len]=='\t'||line[len]==' ';--len)
	;
      line[len]='\0';
      if(len>1) 
        printf("%s\n",line);
    }
}

int mygetline(char line[],int lim)
{
  int c,i;
  for(i=0;i<lim-1&&(c=getchar())!=EOF&&c!='\n';++i)
    line[i]=c;
  line[i]='\0';
  return i;
}
