#include<stdio.h>

/*2-2
  for(i=0;i<lim-1&&(c=getchar())!='\n'&&c!=EOF;++i)
  s[i]=c;
  rewrite it without logical operators. */

int main(){
  int i,c,lim=1000;
  char s[lim];
  for(i=0;i<lim-1;++i){
    c=getchar();
    if(c=='\n') break;
    if(c==EOF) break;
    s[i]=c;
  }
  s[i]='\0';

  printf("%s\n",s);
}
