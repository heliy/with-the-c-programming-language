#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*4-3
  add modulus,negative is ok.*/

#define MAXOP 100
#define NUMBER '0'
#define VAR 'a'

int getop(char []);
void push(double);
double pop(void);

/*reverse Polish calculator*/
main(){
  int type;
  double op2;
  char s[MAXOP];
  double varis[26];
  double rightnow;

  int j;
  for(j=0;j<26;j++){
    varis[j]='\0';
  }

  while((type=getop(s))!=EOF){
    switch(type){
    case NUMBER:
      push(atof(s));
      break;
    case VAR:
      push(varis[s-'a']);              /*is variable*/
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
    case '%':                              /*modulus operator*/
      op2=pop();
      if(op2>0.0){
        push(pop()%op2);
      }
      else
	printf("error:zero mod\n");
      break;
    case '^':                              /*pow in math*/
      op2=pop();
      push(power(pop(),op2));
    case '=':                              /*get variables*/
      op2=pop();
      val[s[0]-'a']=op2;
    case '\n':
      printf("\t%.8g\n",pop());
      break;
    default:
      printf("error:unknown command %s\n",s);
      break;
    }
  }
  return 0;
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

/*print the top elements withour popping*/
void stackprint(void){
  if(sp>0)
    printf("%g",val[sp]);
  else
    printf("error:stack empty\n");
}

/*duplicate val to s, return the top index of val*/
int duplicate(double s[]){
  int i=sp-1;
  for(;i>-1;i--){
    s[i]=val[i];
  }
  return sp-1;
}

/*swap the top two elements*/
void swap2top(void){
  double change;
  change=val[sp-1];
  val[sp-1]=val[sp-2];
  val[sp-2]=change;
}

/*clear the stack*/
void clear(){
  while(sp>0)
    val[--sp]='\0';
  val[0]=='\0';
}

#include<ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]){
  int i,c;
  int sign=0;
  while((s[0]=c=getch())==' '||c=='\t')
    ;
  s[1]='\0';
  if(c-'a'<26&&c>='a'&&vars[c-'a']!='\0')
    return VAR;           /*is a variable*/
  if(!isdigit(c)&&c!='.'&&c!='-'&&c!='+')
    return c; /*not a number*/
  if(c=='-'||c=='+'){     /*for negative*/
    s[0]=c;
    i=1;
  }
  else
    i=0;
  if(isdigit(c))   /*collect interger part*/
    while(isdigit(s[++i]=c=getch()))
      ;
  if(c=='.')       /*collect fraction part*/
    while(isdigit(s[++i]=c=getch()))
      ;
  s[i]='\0';
  if(c!=EOF)
    ungetch(c);
  return NUMBER;
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

void ungets(int s[]){
  int i;
  for(i=strlen(s);i>0;){
    ungetch(s[--i]);
  }
}
