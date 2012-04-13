/*
 * Write a program to "fold" long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of
 * input. Make sure your program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the specified column.
 *
 * Date: April 13, 2012
 */

#include <stdio.h>

#define MAXLINE 1000
#define MAXLENGTH 10

int _getline(char line[], int maxline);

main()
{
  int i, j, len, offset;
  char line[MAXLINE];

  while ((len = _getline(line, MAXLINE)) > 0) {
    for (i = 0; i < len; ++i) {

      if (i % MAXLENGTH == 0 && i != 0) {
        j = 0;
        offset = i;

        while (offset > 0 && line[offset] != ' ' && line[offset] != '\t') {
          ++j;
          offset = i - j;
        }

        if (offset != 0)
          line[offset] = '\n';
      }

    }
    printf("%s", line);
  }
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
