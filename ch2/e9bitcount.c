#include<stdio.h>

/*2-9
  fast bitcount*/

int bitcount(unsigned x){
  int b=0;
  while(x!=0){
    b++;
    x&=(x-1);
  }
  return b;
}

main(){
  printf("%d\n",bitcount(15));
}
