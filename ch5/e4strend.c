#include<stdio.h>

/*5-4
  if t occurs at the end of s*/

int mstrend(char *s,char *t){
  char *c=t;
  while(*s)
   s++;
  while(*t)
   t++;
  do
    s--,t--;
  while((*s)==(*t));
  t++;
  if(c==t)
    return 1;
  else
    return 0;
}

main(){
  char *s="mashiki";
  char *t="ki";
  char *p="dabu";

  printf("%d\n",mstrend(s,t));
  printf("%d\n",mstrend(s,p));
}
