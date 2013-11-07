#include<stdio.h>
#define BITSIZE 32  

/*2-8
  rotate x to right by n bits*/

unsigned getlastbits(int x,int n){
  return x&(~(~0<<n));
}

unsigned rightrot(unsigned x,int n){
  unsigned rot=getlastbits(x,n);
  return rot<<(BITSIZE-n)|(x>>n);
}

main(){
  printf("%iu\n",rightrot(5,2));
}
