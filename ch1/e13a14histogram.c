#include<stdio.h>

/*Exercise 1-13 and 1-14
  print a histogram of the lengths of words in input,
  and the frequencies of different characters.
  bar is horizontal.*/

#define MAX 20

main()
{
  int c,i,j;
  int nlens[MAX+2];
  int nchars[26];
  int wordcount=0;

  // init array as 0
  for(i=0;i<(MAX+2);++i)
    nlens[i]=0;
  for(i=0;i<26;++i)
    nchars[i]=0;

  for(c=0;(c=getchar())!=EOF;)
    {
      if(c>='a'&&c<='z')
        ++nchars[c-'a'];
      if(c==' '||c=='\n'||c=='\t')
	{
	  if(wordcount>MAX)
            ++nlens[MAX+1];
          else if(wordcount==0);
          else
            ++nlens[wordcount];
          wordcount=0;
	} 
      else
          ++wordcount;
    }

  printf("histogram about the lengths of words.\n");
  for(i=0;i<MAX+2;i++)
    {
      for(j=0;j<nlens[i];j++)
	printf("=");
      printf("\n");
    }

   printf("histogram about frequencies of different characters.\n");
   for(i=0;i<26;i++)
     {
       printf("%d",nchars[i]);
       printf("%c|",i+'a');
       for(j=0;j<nchars[i];j++)
	 printf("=");
       printf("\n");
     }
}

