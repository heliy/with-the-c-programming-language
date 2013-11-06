#include<stdio.h>
#include<limits.h>

int main(){

  /*2-1
    ranges of char,short,int,long*/

  /*尚有问题*/

  unsigned long from;
  unsigned long to;

  /*对于signed从0开始加，如果超出变为负值的话，负值为下限值，最大正值为上线值*/
  /*unsinged 的最大值则为两者差值*/

  /*char*/
  char chardet=0;
  to=0;
  while(chardet<=CHAR_MAX){
    chardet++;
    to++;
  }
  from=-(to+1);
  printf("signed char:\n");
  printf("By detecting,it is from %d to %d.\n",from,to);
  printf("From head file,it is from %d to %d.\n",CHAR_MIN,CHAR_MAX);
  printf("\nunsigned char:\n");
  printf("By detecting,it is from 0 to %d.\n",to-from);
  printf("From head file,it is from 0 to %d.\n",UCHAR_MAX);

  /*short int*/
  short shortdet=0;
  to=0;
  while(shortdet>=0){
    shortdet++;
    to++;
  }
  from=shortdet;
  to--;
  printf("\nsigned short:\n");
  printf("By detecting,it is from %d to %d.\n",from,to);
  printf("From head file,it is from %d to %d.\n",SHRT_MIN,SHRT_MAX);
  printf("\nunsigned short:\n");
  printf("By detecting,it is from 0 to %d.\n",to-from);
  printf("From head file,it is from 0 to %d.\n",USHRT_MAX);

  /*int*/
  int intdet=0;
  to=0;
  while(intdet>=0){
    intdet++;
    to++;
  }
  from=intdet;
  to=--;
  printf("\nsigned int:\n");
  printf("By detecting,it is from %d to %d.\n",from,to);
  printf("From head file,it is from %d to %d.\n",INT_MIN,INT_MAX);
  printf("\nunsigned short:\n");
  printf("By detecting,it is from 0 to %d.\n",to-from);
  printf("From head file,it is from 0 to %d.\n",UINT_MAX);

  /*long*/
  long longdet=0;
  to=0;
  while(intdet>=0){
    intdet++;
    to++;
  }
  from=intdet;
  to=--;
  printf("\nsigned long:\n");
  printf("By detecting,it is from %d to %d.\n",from,to);
  printf("From head file,it is from %d to %d.\n",LONG_MIN,LONG_MAX);
  printf("\nunsigned long:\n");
  printf("By detecting,it is from 0 to %d.\n",to-from);
  printf("From head file,it is from 0 to %d.\n",ULONG_MAX);


}
