#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXWORD 100

int cmpsize=6;

struct name{
  char *word;
  int count;
}

struct varigroup{
  struct name *list;
  int listlen;
  struct varigroup *left;
  struct varigroup *right;
}

int getword(char *,int);
int isvari(char *);
struct varigroup *addword(struct varigroup *,char *,int);
void treeprint(struct varigroup *);

main(int argc,char *argv[])
{
  if(argc>1)
    cmpsize=atoi(argv[1]);

  struct varigroup *root;
  char word[MAXWORD];

  root=NULL;
  while(getword(word,MAXWORD)!=EOF)
    if(isvari(word))
      root=addword(root,word,cmpsize);
  treeprint(root);
  return 0;
}

void listprint(struct name*,int);

void treeprint(struct varigroup *p)
{
  if(p!=NULL){
    treeprint(p->left);
    listprint(p->list,p->listlen);
    treeprint(p->right);
  }
}

void listprint(struct name *l,int n)
{
  int i=0;
  for(;i<n;i++)
    printf("%4d %s\n",(l+i)->count,(l+i)->word);
}


struct varigroup *talloc(void);
struct name *getnew(char *);
void add2list(struct varigroup *,char *);

struct varigroup *addword(struct variroup *g,char *w,int s)
{
  int cond;

  if(g==NULL){
    g=talloc();
    g->list=getnew(w);
    g->listlen=1;
    g->left=g->right=NULL;
  }else if(cond=strncmp(w,g->list[0]->word,s)==0)
    add2list(g,w);
  else if(cond<0)
    g->left=addword(g->left,w,s);
  else
    g->right=addword(g->right,w,s);
  return g;
}

strunct varigroup * talloc(void)
{
  return (struct varigroup *) malloc(sizeof(struct varigroup));
}

struct name *getnew(char *w)
{
  struct name new[]={w,1}
  return new;
}

void add2list(struct varigroup *r,char *w)
{
  struct name *p=r->list;
  for(;p<(r->list+r->listlen);p++)
    if(strcmp(p->word,w)==0){
      p->count++;
      return;
    }
  p=getnew(w);
  p++=NULL;
}


char *keys[]={"auto","short","int","long","float","double","char","struct","union","enum","typedef","const","unsigned","signed","extern","register","static","volatile","void","if","else","switch","for","do","while","goto","continue","break","default","sizeof","return",'\0'} 　　
int isvari(char *w){
  if(!isalphs(w[0]))
    return 0;
  char *p;
  for(p=keys;*p!='\0';p++)
    if(strcmp(w,p)==0)
      return 0;
  return 1;
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
