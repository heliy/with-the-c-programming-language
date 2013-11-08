#include<stdio.h>

/*3-2
  change escape sequeces visible */

int escape(char s[],char t[]){
  int i=0,j=0;

  for(;t[i]!='\0';i++){
    switch(t[i]){
    case '\t':
      s[j++]='\\';
      s[j++]='t';
      break;
    case '\n':
      s[j++]='\\';
      s[j++]='n';
      break;
    default:
      s[j++]=t[i];
      break;
    }
  }

  s[i]=='\0';
}
