#include<stdio.h>

/*5-5
  strncpy strncat strncmp*/

void mstrncpy(char *s,char*t,int n){
  while((*s++=*t++)&&(--n))
    ;
}

void mstrncat(char *s,char *t,int n){
  while(*s++)
    ;
  s--;
  while((*s++=*t++)&&(--n))
    ;
}

int mstrncmp(char *s,char *t,int n){
  do{
    if(*s=='\0')
      return 0;
  }
  while((*s++==*t++)&&(--n));
  return *s-*t;
}

main(){
  char s[20]="swat";
  char t[20]="dpot";
  int n=1;

  mstrncpy(s,t,n);
  mstrncat(s,t,n);
  int r=mstrncmp(s,"swpe",2);

  printf("%s\n",s);
  printf("%d\n",r);
}
