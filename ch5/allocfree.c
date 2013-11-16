#include<stdio.h>

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp=allocbuf;

char *alloc(int n){

  if(allocbuf+ALLOCSIZE-allocp>=n){
    allocp+=n;
    /* printf("%p\n",allocp); */
    return allocp-n;
  }else
    return 0;
}

void afree(char *p){
  if(p>allocbuf&&p<allocbuf+ALLOCSIZE)
    allocp=p;
  /* printf("%p\n",allocp); */

}

main(){
  char *p1=alloc(sizeof(char)*2);
  p1="aa";

  /* printf("%p\n",p1); */

  char *p2=alloc(sizeof(char)*3);
  p2="bbb";

  afree(p1);

  /* printf("%p\n",allocp); */

  char *p3=alloc(sizeof(char)*4);
  p3="cccc";

  printf("%p\n",p3);

  printf("%c\n",*p3);

  printf("%p\n",p2);

  printf("%c\n",*p2);

  afree(p2);
  afree(p3);

/* 0x80485f7 */
/* c */
/* 0x80485f3 */
/* b */
}
