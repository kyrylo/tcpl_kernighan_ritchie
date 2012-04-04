/*
 * Write a program to print a histogram of the frequencies of different
 * characters in its input.
 *
 * Date: April 5, 2012
 */

#define START  48 /* Start count from zero. */
#define MAXLEN 127

#include <stdio.h>

main()
{
  int c, i, j;
  char letters[MAXLEN];
  char freqs[MAXLEN];

  for (i = START; i < MAXLEN; ++i) {
    letters[i] = 0;
    freqs[i] = i;
  }

  while ((c = getchar()) != EOF) {
    ++letters[c];
    freqs[c] = c;
  }

  for (i = START; i < MAXLEN; ++i) {
    printf("%c ", freqs[i]);
    for (j = 0; j < letters[i]; ++j)
      printf("—");
    printf("\n");
  }
}
