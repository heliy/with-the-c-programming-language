#include<stdio.h>
#define MAXLINE 1000

/*4-1
  get rightmost index */


int mygetline(char line[],int max);
int strindex(char source[],char searchfor[]);

char pattern[]="ould";

/*find all lines matching pattern*/
main(){
  char line[MAXLINE];
  int found=0;

  while(mygetline(line,MAXLINE)>0)
    if(strindex(line,pattern)>=0){
      printf("%s",line);
      found++;
    }
  return found;
}

int mygetline(char s[],int lim)
{
  int c,i;
  for(i=0;i<lim-1&&(c=getchar())!=EOF&&c!='\n';++i)
      s[i]=c;
  if(c=='\n')
    {
      s[i]=c;
      ++i;
    }
  s[i]='\0';
  return i;
}

/*strindex:return index of t in s,-1 if none*/
int strindex(char s[],char t[]){
  int i,j,k;
  int r=-1;

  for(i=0;s[i]!='\0';i++){
    for(j=i,k=0;t[k]!='\0'&&s[j]==t[k];j++,k++);
    if(k>0&&t[k]=='\0'&&i>r)
      r=i;
  }
  return r;
}
