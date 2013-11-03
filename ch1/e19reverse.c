#include<stdio.h>
#define MAXLINE 1000

void reverse(char rev[],char line[],int linelen);
int mygetline(char s[],int lim);

int main()
{
  int len;
  char line[MAXLINE];
  char reve[MAXLINE];

  while((len=mygetline(line,MAXLINE))>0)
    {
      reverse(reve,line,len);
      printf("%s\n",reve);
    }
}

void reverse(char reve[],char line[],int linelen)
{
  int i;
  for(i=0;i<linelen;i++)
    reve[i]=line[linelen-i-1];
  reve[linelen]='\0';
}

int mygetline(char s[],int lim)
{
  int c,i;
  for(i=0;i<lim-1&&(c=getchar())!=EOF&&c!='\n';++i)
    s[i]=c;
  s[i]='\0';
  return i;
}
