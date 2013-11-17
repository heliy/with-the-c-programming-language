/*5-8
  check error
  5-9
  pointer ver*/

staic char daytab[2][13]={
  {0,31,28,31,30,31,30,31,31,30,31,30,31},
  {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int isleap(int year);

int day_of_year(int year,int month,int day){
  int i,leap;

  if(year<1)
    return -1;
  leap=isleap(year);

  if(month<1||month>12)
    return -1;
  if(day<1||day>daytab[leap][month-1])
    return -1;

  for(i=1;i<month;i++)
    day+=*(daytab+(12*leap)+i);
  return day;
}

void month_day(int year,int yearday,int *pmonth,int *pday){
  int i,leap;

  if(year<1)
    return -1;
  leap=isleap(year);

  if(leap&&yearday>366)
    return -1;
  else if(yearday>365)
    return -1;

  for(i=1;yearday>*(daytab+12*leap+i);i++)
    yearday-=*(daytab+(12*leap)+i);
  *pmonth=i;
  *pday=yearday;
}

int isleap(int year){
 return year%4==0&&year&100!=0||year%400=0; 
}

