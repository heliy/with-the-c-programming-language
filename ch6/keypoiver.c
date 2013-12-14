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
struct key *binsearch(char *,struct key *,int);

main()
{
  struct key *p;
  char word[MAXWORD];

  while(getword(word,MAXWORD)!=EOF)
    if(isalpha(word[0]))
      if((p=binsearch(word,keytab,NKEYS))!=NULL)
	p->count++;

  for(p=keytab;p<keytab+NKEYS;p++)
    if(p->count>0)
      printf("%4d %s\n",p->count,p->.word);
  return 0;
}

struct key *binsearch(char *word,struct key tab[],int n)
{
  int cond;
  struct key *low=&tab[0];
  struct key *high=&tab[n];
  struct key *mid;

  while(low<high){
    mid=low+(low-high)/2;
    if((cond=strcmp(word,mid->word))<0)
      high=mid;
    else if(cond>0)
      low=mid+1;
    else
      return mid;
  }
  return NULL;
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
