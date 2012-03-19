/*
 * Experiment to find out what happens when prints's argument string contains
 * \c, where c is some character not listed above.
 *
 * Date: March 19, 2012
 */

#include <stdio.h>

main() {
  printf("Ru\eby\n"); // => "Ruy\n"
  printf("Ru\rby\n"); // => "by\n"
  printf("Ru\xby\n"); // => "  y\n"
}
