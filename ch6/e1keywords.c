#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab/sizeof(struct key))

struct key{
  char *word;
  int count;
}keytab[NKEYS];

int getword(char *,int);
int binsearch(char *,struct key *,int);

main()
{
  int n;
  char word[MAXWORD];

  while(getword(word,MAXWORD)!=EOF)
    if(isalpha(word[0]))
      if((n=binsearch(word,keytab,NKEYS))>=0)
	keytab[n].count++;

  for(n=0;n<NKEYS;n++)
    if(keytab[n].count>0)
      printf("%4d %s\n",keytab[n].count,keytab[n].word);
  return 0;
}

int binsearch(char *word,struct key tab[],int n)
{
  int cond;
  int low,high,mid;

  low=0;
  high=n-1;
  while(low<=high){
    mid=(low+high)/2;
    if((cond=strcmp(word,tab[mid].word))<0)
      high=mid-1;
    else if(cond>0)
      low=mid+1;
    else
      return mid;
  }
  return -1;
}

int ignore=0;
int get=0;
int set=0;

int getword(char *word,int lim)
{
  int c,getch(void);
  void ungetch(int);
  char *w=word;

  while(issapce(c=getch()))
    ;
  if(c!=EOF)
    *w++=c;
  if(!isalpha(c)){
    *w='\0';
    return c;
  }
  for(;--lim>0;w++){
    *w=getch();
    if(ignore!=0){
      if((ignore=='/'&&*w=='\n')||(ignore=='\''&&*w=='\'')||(ignore=='"'&&*w=='"')){
	ignore=0;
	continue;
      }
      if(get==1){
	if(*w=='/')
	  ignore=0;
	else
	  get=0;
	continue;
      }
      if(ignore=='*'&&*w=='*')
	get=1;
      continue;
    }

    if(set==1){
      if(*w=='/'||*w=='*'){
	ignore=*w;
	set=0;
      }else{
	set=0;
      }
      continue;
    }

    if(*w=='/'){
      set=1;
      continue;
    }

    if(*w=='\''||*w=='"'){
      ignore=*w;
      continue;
    }

    if(isalnum(*w)||(*w=='_'))
      continue;

    ungetch(*w);
    break;

  }
  *w='\0';
  return word[0];
}
