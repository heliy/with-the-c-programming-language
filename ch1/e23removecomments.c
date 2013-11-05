#include<stdio.h>
#include<string.h>

#define MAXLINE 1000

/*Exercise 1-23
  remove comments in C*/

char raw[MAXLINE];
char nocom[MAXLINE];

int mygetline(void);
void recoms(void);

int main(){
  int len;

  while((len=mygetline())>0){
    recoms();
    printf("%s",nocom);
  }
  return 0;
}

void recoms(void){

  int quotedflag=0;
  int rowflag=0;       /*行注释开始的flag*/
  int franflag=0;      /*段注释开始的flag*/

  int less=0;          /*因删去注释而减少的字符数*/

  int i;
  for(i=0;raw[i]!='\0';i++){
 
    /*先考虑是否是引号内内容*/
    if(quotedflag!=0){
      /*是的话则不是注释*/
      nocom[i-less]=raw[i];
      /*判断引号是否结束*/
      if(quotedflag==1&&raw[i]=='\'')
	quotedflag=0;    /*1为单引号*/
      if(quotedflag==2&&raw[i]=='"')
	quotedflag=0;    /*2为双引号*/
      continue;
    }

    /*是否是段注释*/
    if(franflag!=0){
      if(raw[i-2]!='/'&&raw[i-1]=='*'&&raw[i]=='/')
	franflag=0;

      less++;
      continue;
    }

    /*是否是行注释*/
    if(rowflag!=0){
      if(raw[i]=='\n')
	rowflag=0;

      less++;
      continue;
    }

    /*是否是新的引号*/
    if(raw[i]=='"')
      quotedflag=2;    
    if(raw[i]=='\'')
      quotedflag=1;

    /*开始注释段并撤销已添加的'/'*/
    if(raw[i-1]=='/'&&raw[i]=='*'){
      franflag=1;
      less+=2;
      continue;
    }

    /*开始注释行并撤销已添加的'/'*/
    if(raw[i-1]=='/'&&raw[i]=='/'){
      rowflag=1;
      less+=2;
      continue;
    }

    /*则为非注释内容*/
    nocom[i-less]=raw[i];

  }
  nocom[i-less]='\0';
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
