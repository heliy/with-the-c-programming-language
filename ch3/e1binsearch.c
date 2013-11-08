#include<stdio.h>

/*3-1*/

/*motobin:binsearch in book*/
int motobin(int x,int v[],int n){
  int low,high,mid;
  low=0;
  high=n-1;
  while(low<=high){
    mid=(low+high)/2;
    if(x<v[mid])
      high=mid+1;
    else if(x>v[mid])
      low=mid+1;
    else return mid;
  }
  return -1;
}

int kaibin(int x,int v[],int n){
  int low,high,mid;
  low=0;
  high=n-1;
  while(low<=high&&v[mid=(low+high)/2]!=x){
    if (x<v[mid])
      high=mid+1;
    else low=mid+1;
  }
  if(v[mid]==x) return mid;
  else return -1;
}
