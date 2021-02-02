#include<stdio.h>
#define MAXLINE 1000

int mygetline(char line[],int maxline);
void kaicopy(char to[],char from[],int begin);

/*Exercise 1-16.
  print the longest input lines and length.*/

main()
{
  int thislen=0;
  int totallen=0;
  int max;
  char line[MAXLINE];

  max=0;
  while((thislen=mygetline(line,MAXLINE))>0)
   { 
    printf("%d\n",thislen-1);
   }
  return 0;
}

int mygetline(char s[],int lim)
{
  int c,i;

  for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
    s[i]=c;
  if(c=='\n')
    {
      s[i]=c;
      ++i;
    }
  s[i]='\0';
  return i;
}

void kaicopy(char to[],char from [],int begin)
{
  int i;
  i=0;
  while((to[begin+i]=from[i])!='\0')
    ++i;
}
