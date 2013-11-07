#include<stdio.h>

/*2-7
  invert n bits after p of x*/

unsigned getbits(unsigned x,int p,int n){
  return (x>>(p+1-n))&(~(~0<<n));
}

unsigned invert(unsigned x,int p,int n){
  unsigned changeto=getbits(~x,p,n);
  unsigned unchange=getbits(x,p-n,p-n);

  return  x&((~0<<p)|unchange)|(changeto<<(p-n));

}

main(){
  unsigned x=15;
  int p=3;
  int n=2;

  printf("%d\n",invert(x,p,n));
}
