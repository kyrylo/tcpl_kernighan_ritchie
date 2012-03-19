/*
 * Verify that the expression getchar() != EOF.
 *
 * Date: March 19, 2012
 */

#include <stdio.h>

main()
{
  // Ctrl^D returns 0. Any other keypress returns 1.
  printf("%d\n", getchar() != EOF);
}
