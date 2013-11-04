#include<stdio.h>

#define MAXLINE 1000
#define TABSIZE 8     /*设置tab为8个空格*/

/*Exercise 1-21
  replace tabs int*/

char raw[MAXLINE];
char retab[MAXLINE];

int mygetline(void);
void entab(void);

int main(){
  int len;
  while((len=mygetline())>0){
    entab();
    printf("%s",retab);
  }
  return 0;
}

void entab(void){
  int i;
  int less=0;      /*因替换成tab而少的字符数*/

  int from=-1;      /*字符串里替换之前空格开始位置*/
  int to=-1;        /*空格结束位置*/

  for(i=0;raw[i]!='\0';i++){
    retab[i-less]=raw[i];

    if(raw[i]!=' '){
      if(from<to){  /*从from至to中间是空格*/
	int tabno=0;/*需要的tab个数*/
	int need=(TABSIZE-(i-less)%TABSIZE); /*至少一个tab需要的空格数*/
        int j=0;


	if((from-to)>need){
	  tabno=1+(from-to-need)/TABSIZE;
	   /*1表示空格开始至下一个tabstop可用\t填满，后面计算剩下的\t数*/
	  less+=(need+(tabno-1)*TABSIZE);
           /*替换开始*/
	  for(;j<tabno;j++){
	    retab[i-less+j]='\t';
	  }/*其他的不需要\t替换*/
	  less+=tabno;

	}
        from=to=(i-less+j);  /*准备下次替换*/
      }
      from+=1;
      to+=1;
    }
    else{
      to+=1;  /*空格标记进一*/
    }

  }
  retab[i-less]='\0';

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

