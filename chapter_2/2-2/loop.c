/*
 * Write a loop equivalent to the for loop above without using && or ||.
 *
 *   for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 *   s[i] = c;
 *
 * Date: April 15, 2012
 */

#include <stdio.h>

#define MAXLINE 1000

main()
{
  int c, i, lim;
  char s[MAXLINE];

  i = 0;
  lim = MAXLINE;

  while (i < lim-1) {
    c = getchar();

    if (c == EOF)
      break;
    else if (c == '\n')
      break;

    s[i++] = c;
  }

  if (c == '\n')
    s[i] = c;

  s[++i] = '\0';

  printf("%s", s);
}
