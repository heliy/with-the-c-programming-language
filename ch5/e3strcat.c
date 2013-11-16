#include<stdio.h>

/*5-3
  pointer version of strcat*/

/*strcat: copy t to the end of s*/
void mystrcat(char *s,char *t){
  while(*s++) /*go to end of s*/
    ;
  s--;       /*back before '\0'*/
  while((*s++=*t++))
    ;         /*copy*/
}

main(){
  char s[20]="sose";
  char t[10]="mori";

  mystrcat(s,t);

  printf("%s\n",s);

}
