>The problem is distinguishing the end of input from valid data. The solution is that getchar returns a distinctive value when there is no more input, a value that cannot be confused with any real character. This value is called EOF, for ``end of file''. We must declare c to be a type big enough to hold any value that getchar returns. We can't use char since c must be big enough to hold EOF in addition to any possible char. Therefore we use int.  

打印EOF的值参考了[stackoverflow](http://stackoverflow.com/questions/11968558/print-the-value-of-eof-also-for-the-following-code-give-the-output)  
`getchar()!=EOF`的值以输入空字符串结束为1，以C-c C-d结束为0。  

p22  
`c='\t'` 应为 `c==‘'\t'`  

>错误：只允许在C99模式下使用'for'循环初始化变量声明  
>附注：使用-std=c99 或 -std=gnu99 来编译您的代码  

30p的实例程序里定义的getline与stdio.h里定义的getline冲突，改名。

Exercise 1-16 用指针解决，希望有更好的方法

# 1-23未考虑转义字符- -、、

# 1-24暂放

c头文件在/usr/include下

打印unsigned long :ul(类推  ?
# 2-1尚有问题

>the value of the right side is converted to the type of the left,which is the type of the result.

(type name)expression

0x与0X的区别？？？


