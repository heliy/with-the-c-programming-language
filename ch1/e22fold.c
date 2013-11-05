#include<stdio.h>

#define MAXLINE 1000
#define SIZE 10     /*定义的折叠长度n*/ 

/*Exercise 1-22
 fold long input lines into short lines.*/

/*对原输入处理使得最后靠近SIZE的空格替换成\n*/
char raw[MAXLINE];
char innew[MAXLINE];

int mygetline(void);
void fold(void);

int main(){
  int len;
  while((len=mygetline())>0){
    fold();
    printf("%s",innew);
  }
  return 0;
}

void fold(void){
  int i;
  int blankmark=0;  /*标记空格的位置*/
  int lastnew=0;    /*标记上次换行的位置*/
  int push=0;       /*添加的换行符个数*/

  for(i=0;raw[i]!='\0';i++){
    innew[i+push]=raw[i];

    if(raw[i]==' '){
      blankmark=i;  /*标记最新的空格位置*/
    }

    if((i-lastnew)==SIZE){
      if(raw[blankmark]!=' ') {  /*此时换行前没有空格*/
	innew[i+push]='\n';
	push++;
	lastnew=i;
      }
      else{
        innew[blankmark+push]='\n';
        lastnew=blankmark;
      }
    }

    printf("%s\n",innew);
    printf("%d\n",i-lastnew);
  }
  innew[i+push]='\0';
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
