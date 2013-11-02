#include<stdio.h>

float getcelsius(int fahr)
{
  return 5.0*(fahr-32.0)/9.0;
}

int main()
{
  int lower=0,upper=300,step=20;
  int fahr;
  for(fahr=lower;fahr<upper;fahr+=step)
    printf("%3d\t%6.2f\n",fahr,getcelsius(fahr));
  return 0;
}
