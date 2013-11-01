
# include<stdio.h>

/*Exercise 1-4.
  Print corresponding Celsius to Fahrenheit
  Fahrenheit= (Celsius * 9.0 ) / 5.0 + 32.0 */

main()
{
  float fathr,celsius;
  int from,to,step;

  printf("%s\t%s\n","Celsius","Fahrenheit");

  from=-10;
  to=150;
  step=10;

  celsius=from;
  while(celsius <= to)
  {
    fathr=(celsius * 9.0) / 5.0 +32.0;
    printf("%3.0f\t%6.2f\n", celsius , fathr);
    celsius = celsius + step;  
  }
}
