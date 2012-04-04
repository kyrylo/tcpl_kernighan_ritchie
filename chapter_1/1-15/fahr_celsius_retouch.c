/*
 * Rewrite the temperature conversion program of Section 1.2 to use a function
 * for conversion.
 *
 * Date: April 5, 2012
 */

#include <stdio.h>

float fahr_to_celsius(float);

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version */
main()
{
  float fahr;
  float lower, upper, step;

  lower = 0;   /* lower limit of temperatuire scale */
  upper = 300; /* upper limit */
  step = 20;   /* step size */

  fahr = lower;
  while (fahr <= upper) {
    printf("%3.0f %6.1f\n", fahr, fahr_to_celsius(fahr));
    fahr = fahr + step;
  }
}

/*
 * Converts a Fahrenheit degree to a Celsius equivalent.
 */
float fahr_to_celsius(float fahr)
{
  float celsius = (5.0/9.0) * (fahr-32.0);

  return celsius;
}
