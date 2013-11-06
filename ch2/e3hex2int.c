#include<stdio.h>
#include<ctype.h>

/*2-3
  convert a string of hex to int */

#define MAXLINE 1000

int power(int a,int b){
  if(b>0)
    return a*power(a,b-1);
  else
    return 1;
}

int htoi(char hex[]){
  int i,result=0;
  if(hex[0]=='\0') return 0;

  int pre=0;                /*数字前是否有0x或0X*/
  if(hex[1]!='\0'&&hex[0]=='0'&&tolower(hex[1])=='x')
    pre=2;

  for(i=0+pre;hex[i]!='\0';i++){
    if(isdigit(hex[i])){            /*数字*/
      result+=(hex[i]-'0')*power(16,i-pre);
    }
    else if(isalpha(hex[i])){
      char low=tolower(hex[i]);
      if(low>'f') break;
      result+=(low-'a'+10)*power(16,i-pre);
    } 
    else
      break;
  }
  return result;
}

int mygetline();

char raw[MAXLINE];

int main(){
  int len;
  int hex;
  while((len=mygetline())>0){
    hex=htoi(raw);
    printf("%d\n",hex);
  }
  return 0;
}


int mygetline(void){
  int c,i;

  for(i=0;i<MAXLINE-1&&(c=getchar())!=EOF&&c!='\n';++i)
    raw[i]=c;
  if(c=='\n'){
    raw[i]=c;
    ++i;
  }
  raw[i]='\0';
  return i;
}

