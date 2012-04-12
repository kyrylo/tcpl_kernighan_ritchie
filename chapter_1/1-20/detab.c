/*
 * Write a program detab that replaces tabs in the input with the proper number
 * of blanks to space to the next tab stop. Assume a fixed set of tab stops, say 
 * every n columns. Should n be a variable or a symbolic parameter?
 *
 * Note: This assignment was quite hard for me (although, I had thought, that it
 * was a piece of cake), so I had too look up the existing solution, which is
 * really elegant and impressive:
 *   http://users.powernet.co.uk/eton/kandr2/krx120.html
 *
 * Date: April 13, 2012
 */

#include <stdio.h>

#define MAXLINE 1000
#define TABSIZE 5

int _getline(char line[], int maxline);

main()
{
  int i, j, k, w_len;
  char line[MAXLINE];

  while (_getline(line, MAXLINE) > 0)
    for (i = w_len = 0; line[i] != '\0'; ++i)
      if (line[i] == '\t') {
        k = TABSIZE - (w_len % TABSIZE);
        for (j = 0; j < k; ++j) {
          putchar(' ');
          ++w_len;
        }
      } else {
        putchar(line[i]);
        ++w_len;
      };
}

int _getline(char s[], int lim)
{
  int c, i;

  for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}
