#include<stdio.h>

/*2-10
  `?:`version for lower*/

int lower(int c){
  return c>='A'&&c<='Z'?c-('A'-'a'):c;
}

main(){
  printf("%c\n",lower('C'));
}
