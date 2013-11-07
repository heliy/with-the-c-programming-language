#include<stdio.h>

/*2-4
  delete chars in s1 appeared in s2. */

#define MAXLINE 1000

int isin(char s[],char t){
  int i=0;
  while(s[i]!='\0'){
    if(s[i++]==t) return 1; 
  }
  return 0;
}

void squeeze(char s1[],char s2[]){
  int i=0,j=0;
  for(;s1[i]!='\0';i++){
    if(!isin(s2,s1[i]))
      s1[j++]=s1[i];
  }
  s1[j]='\0';
}

int mygetline(char s[]);

char s2[MAXLINE];
char s1[MAXLINE];

int main(){
  int len;

  printf("Input s1:");
  len=mygetline(s1);
  printf("Input s2:");
  len=mygetline(s2);

  squeeze(s1,s2);

  printf("result:%s\n",s1);
  return 0;
}


int mygetline(char raw[]){
  int c,i;

  for(i=0;i<MAXLINE-1&&(c=getchar())!=EOF&&c!='\n';++i)
    raw[i]=c;
  if(c=='\n'){
    raw[i]=c;
    ++i;
  }
  raw[i]='\0';
  return i;
}

