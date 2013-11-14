#include<stdio.h>
#include<string.h>

/*3-5
  convert n into s as a string in base b character representation.*/

void reverse(char s[]){
  int c,i,j;
  for(i=0,j=strlen(s)-1;i<j;i++,j--){
    c=s[i];
    s[i]=s[j];
    s[j]=c;
  }


void itob(int n,char s[],int b){
  int i=0,sign=0;
  unsigned t;
  int c;

  if(n<0){
    sign=-1;
    t=-n;
  }
  else t=n;

  do{
    c=t%b;
    if(c>9) c=c-10+'A';
    else c=c+'0';
    s[i++]=c;
  }
  while((t/=b)>0);

  if(sign<0) {
    s[i]='-';
    s[i+1]='\0';
  }else{
    s[i]='\0';
  }
  reverse(s);
}

main(){
  char s[20];
  int n=-15;
  int b=16;

  itob(n,s,b);
  printf("%s\n",s);
}
