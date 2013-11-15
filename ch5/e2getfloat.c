#include<ctype.h>
#include<stdio.h>

int getch(void);
void ungetch(int);

/*5-2
  get float return int*/

/*getfloat:get next float from input into *pn */
int getfloat(float *pn){
  double val,power;
  int c,sign=0;

  while(isspace(c=getch()))    /*skip white space*/
    ;
  if(!isdigit(c)&&c!=EOF&&c!='+'&&c!='-'&&c!='.'){
    ungetch(c);
    return 0;
  }
  sign=(c=='-')?-1:1;
  if(c=='+'||c=='-')
    c=getch();
  for(val=0.0;isdigit(c);c=getch()){
    val=10.0*val+(c-'0');
    }
  if(c=='.')
    c=getch();

  for(power=1.0;isdigit(c);c=getch()){
    val=10.0*val+(c-'0');
    power*=10;
  }

  (*pn)=sign*val/power;
  return c;
}

main(){
  float pn;
  int c=getfloat(&pn);
  printf("%f\n",pn);
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
 
