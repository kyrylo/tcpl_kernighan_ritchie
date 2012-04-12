/*
 * Write a program entab that replaces strings of blanks by the minimum number
 * of tabs and blanks to achieve the same spacing. Use the same tab stops as for
 * detab. When either a tab or a single blank would suffice to reach a tab stop,
 * which should be given preference?
 *
 * Note: You know it...
 *
 * Date: April 13, 2012
 */

#include <stdio.h>

#define MAXLINE 1000
#define TABSIZE 4

int _getline(char line[], int maxline);

main()
{
  int i, j, len, spaces;
  char line[MAXLINE];

  while ((len = _getline(line, MAXLINE)) > 0) {
    for (i = 0; i < len; ++i) {
      if (line[i] == ' ')
        spaces++;
      if (line[i] != ' ')
        spaces = 0;
      if (spaces == TABSIZE) {
        i   -= 3;
        len -= 3;
        line[i] = '\t';

        for (j = i+1; j < len; j++)
          line[j] = line[j+3];
        spaces = 0;

        line[len] = '\0';
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
