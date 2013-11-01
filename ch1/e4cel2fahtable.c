
# include<stdio.h>

/*Exercise 1-4.
  Print corresponding Celsius to Fahrenheit
  Fahrenheit= (Celsius * 9.0 ) / 5.0 + 32.0 */

main()
{
  float fahr,celsius;
  int from,to,step;

  printf("%s\t%s\n","Celsius","Fahrenheit");

  from=-10;
  to=150;
  step=10;

  celsius=from;
  while(celsius <= to)
  {
    fahr=(celsius * 9.0) / 5.0 +32.0;
    printf("%3.0f\t%6.2f\n", celsius , fahr);
    celsius = celsius + step;  
  }
}
