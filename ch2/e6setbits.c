#include<stdio.h>

/*2-6
  replace n bits after p of x with the last n bits of y*/

/*getlastbits : get the last n bits of x*/
unsigned getlastbits(int x,int n){
  return x&(~(~0<<n));
}

unsigned setbits(unsigned x,int p,int n,unsigned y){
  unsigned ylastn=getlastbits(y,n);    /*rightmost n bits of y*/
  unsigned xlastpn=getlastbits(x,p-n); /*unchanged bits of x after p*/

  x=(x>>p)<<n;
  x=x^ylastn;            /*add n bits to x*/

  x=(x<<(p-n));
  x=x^xlastpn;       /*add unchanged bits*/

  return x;
}

main(){
  unsigned x= 15;
  unsigned y=10;
  int p=3;
  int n=2;

  printf("%d\n",setbits(x,p,n,y));
}
