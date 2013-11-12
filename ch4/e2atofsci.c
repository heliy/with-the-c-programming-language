#include<stdio.h>
#include<ctype.h>
#include<math.h>

/*4-2
  array to float scientifically*/

double atof(char s[]){
  double val,power,scivalue;
  int i,sign,sci=0,scisign=0;

  for(i=0;isspace(s[i]);i++)
    ;
  sign=(s[i]=='-')?-1:1;
  if(s[i]=='+'||s[i]=='-')
    i++;

  for(val==0.0;isdigit(s[i]);i++)
    val=10.0*val+(s[i]-'0');
  if(s[i]=='.')i++;

  for(power=1.0;isdigit(s[i]);i++){
    val=10.0*val+(s[i]-'0');
    power*=10;
  }

  if(s[i]=='e'||s[i]=='E'){
    i++;
    scisign=((s[i]=='-')?-1:1);
    if(s[i]=='-'||s[i]=='+') i++;
  }
  if(scisign!=0){
    for(;isdigit(s[i]);i++)
      sci=10*sci+(s[i]-'0');
  }

  return sign*val*pow(10.0,scisign*sci)/power;
}

main(){
  printf("%f\n",atof("123.45e-6"));
}
