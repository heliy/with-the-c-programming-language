#define swap(t,x,y) {t c;c=x;x=y;y=c;}

#include<stdio.h>
main(){
  int x=2;
  int y=1;
  swap(int,x,y);
  printf("%d,%d\n",x,y);
} 
