#include<ctype.h>
#include<stdio.h>

int getch(void);
void ungetch(int);

/*5-1
  push '+' or '-' have no digit follow back*/

/*getint:get next interger from input into *pn */
int getint(int *pn){
  int c,sign=0;
  int follow=0;

  while(isspace(c=getch()))    /*skip white space*/
    ;
   do{
    if(!isdigit(c)&&c!=EOF&&c!='+'&&c!='-'){
      ungetch(c);
      return 0;
    }
    sign=(c=='-')?-1:1;
    if(c=='+'||c=='-')
      c=getch();
    for(*pn=0;isdigit(c);c=getch()){
      follow=1;
      *pn=10*(*pn)+(c-'0');
    }
    (*pn)*=sign;
    if(c!=EOF)
      ungetch(c);
    printf("%d\n",follow);
    if(follow==0)
      ungetch(c);
    else
      break;
  }while(1);
  
  return c;
}

main(){
  int pn;
  int c=getint(&pn);
  printf("%d\n",pn);
  printf("%d\n",c);

}

#include<string.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp=0;

int getch(void){
  return (bufp>0)?buf[--bufp]:getchar();
}

void ungetch(int c){
  if(bufp>=BUFSIZE)
    printf("ungetch:too many characters\n");
  else
    buf[bufp++]=c;
}
 
