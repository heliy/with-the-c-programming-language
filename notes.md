>The problem is distinguishing the end of input from valid data. The solution is that getchar returns a distinctive value when there is no more input, a value that cannot be confused with any real character. This value is called EOF, for ``end of file''. We must declare c to be a type big enough to hold any value that getchar returns. We can't use char since c must be big enough to hold EOF in addition to any possible char. Therefore we use int.  

打印EOF的值参考了[stackoverflow](http://stackoverflow.com/questions/11968558/print-the-value-of-eof-also-for-the-following-code-give-the-output)  
`getchar()!=EOF`的值以输入空字符串结束为1，以C-c C-d结束为0。  

p22  
`c='\t'` 应为 `c==‘'\t'`  

>错误：只允许在C99模式下使用'for'循环初始化变量声明  
>附注：使用-std=c99 或 -std=gnu99 来编译您的代码  

30p的实例程序里定义的getline与stdio.h里定义的getline冲突，改名。

# 1-23未考虑转义字符- -、、

# 1-24暂放

c头文件在/usr/include下

### 打印unsigned long? 2-6/7/8

# 2-1尚有问题

>the value of the right side is converted to the type of the left,which is the type of the result.

(type name)expression

0x与0X的区别？？？ <-没区别

### 2-8：查limits.h里int为32bit <-这着好损

### 查看运行时间 3-1

acsii表 3-2

3-4 转换为unsigned

4-4与4-6的`add commands`是什么意思 我当加函数了
#4-5如何从math.h里提取函数啊！

### 4-6处理变量到底是什么 理解为输入`c=4`则将4存入名为c的变量

## 91page
按这个程序理解 用alloc申请内存和afree释放内存必须要按顺序？  
===|p1|p2|  
p1申请了了一块 p2再申请一块  
先释放p1的话p2不也跟着free了吗  
实验了一下没有预想的情况 为什么呢？

echo 默认换行

# 5-10 段错误 (core dumped) 、、、
# 5-11 至 5-13 暂时给跪
# 5-19/20 也给跪



