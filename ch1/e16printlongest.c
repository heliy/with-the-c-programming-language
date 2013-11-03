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
  char* longest;
  char* front;

  max=0;
  while((thislen=mygetline(line,MAXLINE))>0)
   { 
    totallen+=thislen;
    char temp[totallen];
    kaicopy(temp,front,0);
    kaicopy(temp,line,totallen-thislen);

    if(thislen==MAXLINE && line[MAXLINE-1]!='\n')/*this line isn't complete */
	front=&temp;
    else
      {
        if(totallen>max)
         {
            max=totallen;
	    longest=&temp;
         }
        totallen=0;
	char end="\0";
	front=&end;
      }
}
  if(max>0)
    printf("%s\n%d\n",longest,max);
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
