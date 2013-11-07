#include<stdio.h>
#define MAXLINE 1000

/*2-5
  get location in s1 where the char occurs in s2 */

int isin(char s[],char t){
  int i=0;
  while(s[i]!='\0'){
    if(s[i++]==t) return 1; 
  }
  return 0;
}

int any(char s1[],char s2[]){
  int i=0;
  while(s1[i]!='\0'){
    if(isin(s2,s1[i]))
      return i;
    i++;
  }
  return -1;
}

int mygetline(char s[]);

char s2[MAXLINE];
char s1[MAXLINE];

int main(){
  int loc;

  printf("Input s1:");
  loc=mygetline(s1);
  printf("Input s2:");
  loc=mygetline(s2);

  loc=any(s1,s2);

  printf("result:%d\n",loc);
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
