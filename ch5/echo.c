#include<stdio.h>

main(int argc,char *argv[]){
  /* int i; */
  /* for(i=1;i<argc;i++) */
  while(--argc>0)
    printf((argc>1)?"%s ":"%s",*++argv);
  printf("\n");
  return 0;
}
