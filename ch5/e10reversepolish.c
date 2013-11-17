#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*5-10
  reverse plolish with cli.*/

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

int main(int argc,char *argv[]){
  int type;
  int i=1;
  double op2;

  while((type=getop(argv[i]))!=EOF&&i<argc){
    printf("%s",argv[i]);
    switch(type){
    case NUMBER:
      push(atof(argv[i]));
      break;
    case '+':
      push(pop()+pop());
      break;
    case '*':
      push(pop()*pop());
      break;
    case '-':
      op2=pop();
      push(pop()-op2);
      break;
    case '/':
      op2=pop();
      if(op2!=0.0)
	push(pop()/op2);
      else
	printf("error:zero divisor\n");
      break;
    default:
      printf("error:unknown command\n");
      break;
    }
  i++;
  }
  printf("\t%.8g\n",pop());
}

#define MAXVAL 100

int sp=0;
double val[MAXVAL];

void push(double f){
  if(sp<MAXVAL)
    val[sp++]=f;
  else
    printf("erroe:stack full,can't push %g\n",f);
}
double pop(void){
  if(sp>0)
    return val[--sp];
  else{
    printf("error:stack empty\n");
    return 0.0;
  }
}

#include<ctype.h>
int getop(char s[]){
  int c=*s;
  if(c=='\0')
    return EOF;

  if(*(s+1)!='\0')
    if(!isdigit(c)&&c!='.'&&c!='-'&&c!='+')
      return c;    /*not a number*/
    return NUMBER;

  if(isdigit(c))
    return NUMBER;
  else
    return c;
}

