/*
 * Modify the temperature conversion program to print the table in reverse
 * order, that is, from 300 degrees to 0.
 *
 * Date: March 19, 2012
 */

#include <stdio.h>

main()
{
  float fahr, celsius;
  float lower, upper, step;

  lower = 0; /* lower limit of temperatuire scale */
  upper = 300; /* upper limit */
  step = 20; /* step size */

  fahr = upper;
  while (fahr >= lower) {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr - step;
  }
}
