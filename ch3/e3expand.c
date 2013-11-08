#include<stdio.h>

/*3-3
  expand s1 like 'a-c' to 'abc'*/


void expand(char s1[],char s2[]){
  int begin=0;    /*标记每段起始的符号*/
  int i=0;
  int j=0;

  for(;s1[i]!='\0';i++){
    if(s1[i]=='-'){
      if(s1[begin]=='-') {      /*跳过开头的'-'*/
         begin=1;
         continue;    
      }
      if(s1[i+1]=='\0') break;  /*忽略结尾的'-'*/    
      begin=i-1;
      printf("%d\n",begin);
      continue;
    }
    else if(i>0&&(s1[i-1]=='-')){       /*将begin至s1[i]添加至s2,不包括首尾*/
      int t=s1[begin]+1;
      for(;t<s1[i];t++)
  	s2[j++]=t;
    }
    s2[j++]=s1[i];

  }
  s2[j]='\0';
}

main(){
  char s1[10]="-a-c-e1-8-";
  char s2[30];

  expand(s1,s2);

  printf("%s\n",s2);
}
