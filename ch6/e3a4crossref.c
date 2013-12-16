#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAXWORD 100

struct word{
  char *w;
  int *location;
  int count;
  struct word *left;
  struct word *right;
}

int getword(char *,int);
int isnoise(char *);
struct word *addtree(struct word *,char *,int);
void treeprint(struct tnode *);

int line=0;
int max=0;
int totall=0;

main()
{
  struct word *root;
  char word[MAXWORD];

  root=NULL;
  while(getword(word,MAXWORD)!=EOF)
    if(word[0]=='\n')
      line++;
    else if(isnoise(word)==0)
      root=addtree(root,word,line);
  treeprint(root);
  qsort()
  orderprint(root);
  return 0;
}

void treeprint(struct word *p)
{
  int *t;
  if(p!=NULL){
    treeprint(p->left);
    printf("%s %4d:",p->w,p->count);
    for(t=p->location;t<p->location+count;p++)
      printf("%4d\t",*t);
    printf("\n");
    treeprint(p->right);
  }
}

struct word *talloc(void);
char *strdup(char *);

struct word *addtree(struct word *p,char *w,int line)
{
  int cond;
  if(r==NULL){
    totall++;
    p=talloc();
    p->w=strdup(w);
    p->location={line};
    p->count=1;
    p->left=p->right=NULL;
  }else if(cond=strcmp(w,p->w)==0){
    int *tmp=(p->location);
    ++tmp=line;
    ++tmp='\n';
    p->location=tmp;
    p->count++;
    if(p->count>max)
      max=p->count;
  }else if(cond<0)
    p->left=addtree(p->left,w);
  else
    p->right=addtree(p->right,w);
  return p;
}

struct word *talloc(void)
{
  return (struct word *) malloc(sizeof(struct word));
}

char *strdup(char *s)
{
  char *p;

  p=(char *)malloc(strlen(s)+1);
  if(p!=NULL)
    strcpy(p,s);
  return p;
}


char *trash[]={"the","of","in","and","for","a","to"} //and so on...
int isnoise(char *w)
{
  if(!isalphs(w[0]))
    return 1;
  char *p;
  for(p=keys;*p!='\0';p++)
    if(strcmp(w,p)==0)
      return 1;
  return 0;
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
