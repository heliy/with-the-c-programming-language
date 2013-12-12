#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/*5-14 -> 5-17
 *
 */

#define MAXLINE 5000
char *lineptr[MAXLINES];
int reverse=1;
int fold=0;
int dire=1;

int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int nlines);

void qsort(void *lineptr[],int left,int right,int (*comp)(void *,void *));
int numcmp(char *,char *);

main(int argc,char *argv[])
{
  int nlines;        /*number of input lines read*/
  int numeric=0;     /*1 if numeric sort*/

  if(argc >1 && strcmp(argv[1],"-n")==0){
    numeric=1;
    if(argc>2 && strcmp(argv[2],"-r")==0)
      reverse=-1;
  }
  if(argc >1 && strcmp(argv[1],"-f")==0){
    fold=1;
    if(argc>2 && strcmp(argv[2],"-d")==0)
      dire=0;
  }
  if((nlines=readlines(lineptr,MAXLINES))>=0){
    qsort((void **)lineptr,0,nlines-1,(int (*)(void*,void*))(numeric?numcmp:mystrcmp));
    writelines(lineptr,nlines);
    return 0;
  }else{
    printf("input too big to sort\n");
    return 1;
  }
}

void qsort(void *v[],int left,int right,int (*comp)(void *,void *))
{
  int i,last;

  void swap(void *v[],int,int);

  if(left>=right)
    return;
  swap(v,left,(left+right)/2);
  last=left;
  for(i=left+1;i<=right;i++)
    if((*comp)(v[i],v[left])<0)
      swap(v,++last,i);
  swap(v,left,last);
  qsort(v,left,last-1,comp);
  qsort(v,last+1,right,comp);
}

int numcmp(char *s1,char *s2)
{
  double v1,v2;

  v1=atof(s1);
  v2=atof(s2);
  if(v1<v2)
    return -1*reverse;
  else if(v1>v2)
    return 1*reverse;
  else
    return 0;
}

int mystrcmp(char *s1,char *s2){
  while(*s1!='\0'&&*s2!='\0'){
    if(dire||isalnum(*s1)||*s1==' ');
    else return 0;
    if(dire||isalnum(*s2)||*s2==' ');
    else return 0;

    if(*s1<*s2){
      if(((*s1+32)*fold)!=*s2)
        return -1;
    }
    else if(*s1>*s2){
      if(((*s1-32)*fold)!=*s2)
	return 1;    
    }
    s1++;
    s2++;
  }
  return 0;
}


void swap(void *v[],int i,int j)
{
  void tmp;
  tmp=v[i];
  v[i]=v[j];
  v[j]=tmp;
}

