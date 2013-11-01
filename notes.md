>The problem is distinguishing the end of input from valid data. The solution is that getchar returns a distinctive value when there is no more input, a value that cannot be confused with any real character. This value is called EOF, for ``end of file''. We must declare c to be a type big enough to hold any value that getchar returns. We can't use char since c must be big enough to hold EOF in addition to any possible char. Therefore we use int.  

打印EOF的值参考了[stackoverflow](http://stackoverflow.com/questions/11968558/print-the-value-of-eof-also-for-the-following-code-give-the-output)  
`getchar()!=EOF`的值以输入空字符串结束为1，以C-c C-d结束为0。  


