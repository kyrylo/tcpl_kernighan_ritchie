/*
 * Write a program to copy its input to its output, replacing each string of one\
 * or more blanks by a single blank.
 *
 * Date: March 20, 2012
 */

#include <stdio.h>

main()
{
  int c, prev;

  prev = 0;

  while ((c = getchar()) != EOF) {
    if (c != ' ' || c != prev) {
      putchar(c);
    }

    prev = c;
  }
}
