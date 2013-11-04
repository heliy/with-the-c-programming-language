#include<stdio.h>
#define MAXLINE 1000
#define TABSIZE 8      /*设置tab为8个空格*/

/*Exercise 1-20
  replaces tabs in the input with blanks */

char raw[MAXLINE];
char notab[MAXLINE*TABSIZE];

int mygetline(void);
void detab(void);

int main(){
  int len;
  while((len=mygetline())>0){
    detab();
    printf("%s",notab);
  }
  return 0;
}

void detab(void){
  int i;
  int push=0;                    /*因tab而移位的字符数*/
  for(i=0;raw[i]!='\0';i++){
    if(raw[i]=='\t'){
      int j;
      for(j=0;j<(TABSIZE-((i+push)%TABSIZE));++j){
	notab[i+push+j]=' ';
      }
      push+=(j-1);
    }
    else{
      notab[i+push]=raw[i];
    }
  }
  notab[i+push]='\0';
}

int mygetline(void){
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
