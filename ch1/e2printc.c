#include<stdio.h>

main(){
  printf("Try to print \\c:\c\n");
}

/*
GCC 显示：
e2printc.c: 在函数‘main’中:
e2printc.c:4:10: 警告： 未知的转义序列：‘\c’ [默认启用]

运行：
Try to print \c:c
*/
