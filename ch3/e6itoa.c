#include<stdio.h>
#include<string.h>

/*3-6
  int to array like %nd */

void reverse(char s[]){
  int c,i,j;
  for(i=0,j=strlen(s)-1;i<j;i++,j--){
    c=s[i];
    s[i]=s[j];
    s[j]=c;
  }
}

void itoa(int n,char s[],int len){
  int i=0,sign=0;
  unsigned t;
  int c;

  if(n<0){
    sign=-1;
    t=-n;
  }
  else t=n;

  do{
    s[i++]=t%10+'0';
  }
  while((t/=10)>0);

  for(;i<len;i++){
    s[i++]=32;
  } 

  if(sign<0) {
    s[i]='-';
    s[i+1]='\0';
  }else{
    s[i]='\0';
  }
  reverse(s);
  
}

int main(){
  char s[20];
  int n=235;
  int len=10;

  itoa(n,s,len);
  printf("%s\n",s);

  return 0;
}
