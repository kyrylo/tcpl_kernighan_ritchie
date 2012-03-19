/*
 * Write a program to count blanks, tabs, and newlines.
 *
 * Date: March 20, 2012
 */

#include <stdio.h>

main()
{
  int c, nl, bl, tb;

  nl = bl = tb = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ')  ++bl;
    if (c == '\t') ++tb;
    if (c == '\n') ++nl;
  }

  printf("Blanks: %d\nTabs: %d\nNew lines: %d\n", bl, tb, nl);
}
