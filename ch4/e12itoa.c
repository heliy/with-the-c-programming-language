#include<stdio.h>
#include<string.h>

/*3-6 3-7
  reverse,itoa a recursive version */

void reverse(char s[],int i,int j){
  if(i<j){
    c=s[i];
    s[i]=s[j];
    s[j]=c;
    reverse(s,i+1,j-1);
  }
}

void itoa(int n,char s[]){
  if(n<0){
    putchar('-');
    n=-n;
  }
  if(n/10){
    itoa(n/10,s);
  }
  s[strlen(s)]=n/10+'0';
  reverse(s);
}
