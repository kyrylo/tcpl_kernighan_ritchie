/*
 * Write a program to print a histogram of the lengths of words in its input. It
 * is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging.
 *
 * Solution for a vertical histogram. The solution
 * lacks in some aspects, but I prefer concise style.
 *
 * Date: April 5, 2012
 */

#define IN  1
#define OUT 0
#define MAXLEN 21

#include <stdio.h>

main()
{
  int c, i, j, state, word_length;
  char words[MAXLEN];

  state = OUT;
  word_length = 0;
  for (i = 0; i < MAXLEN; ++i)
    words[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      ++words[word_length];
      word_length = 0;
    } else {
      ++word_length;
      state = IN;
    }
  }

  printf("\n");

  for (i = 1; i < MAXLEN; ++i)
    printf("%2d ", i);

  printf("\n");

  for (i = 1; i < MAXLEN; ++i) {
    for (j = 1; j < MAXLEN; ++j)
      if (words[j]) {
        printf("%2s ", "|");
        --words[j];
      } else {
        printf("%3s", " ");
      };

    printf("\n");
  }

  printf("\n");
}
