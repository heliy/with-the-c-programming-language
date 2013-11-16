#include<stdio.h>

/*5-6
  rewrite x6*/

#define MAXLINE 1000
char raw[MAXLINE];
int getline1(void){
  int c;
  char *p=raw;
  for(;p-raw<MAXLINE-1&&(c=getchar())!=EOF&&c!='\n';)
    *p++=c;
  if(c=='\n'){
    *p++=c;
  }
  *p='\0';
  return p-raw;
}

void reverse(char *s){
  char* c,*i=s;
  while(*s++)
    ;
  s--;
  while(i++<s--){
    *c=*i;
    *i=*s;
    *s=*c;
  }
}

void itoa(int n,char *s){
  char *c=s;
  int sign=0;
  if(n<0)
    sign=-1,n=-n;

  do{
    *s++=n%10+'0';
  }
  while((n/=10)>0);

  if(sign<0){
    *s++='-';
  }
  else
    *s='\0';
  reverse(c);
}

int strindex(char *s,char *t){
  char *i=s,*k=t;
  while(*i++){
  char *j=s;
  while(*k++&&*j++==*k)
    ;
  if(k>t&&*k)
    return i-s; 
  }
  return -1;
}

