/*
 * Write a program to remove all comments from a C program. Don't forget to
 * handle quoted strings and character constants properly. C comments don't
 * nest.
 *
 * Date: April 14, 2012
 */

#include <stdio.h>

#define MAXLINE 1000

int _getline(char line[], int maxline);

main()
{
  int i, j, len;
  int comment; /* 1 when a comment started, 0 when a comment ended */
  int start_pos, end_pos; /* Starting and ending points of a comment */
  char line[MAXLINE];

  comment = 0;

  while ((len = _getline(line, MAXLINE)) > 0) {
    for (i = 0; i < len; ++i) {

      if (comment == 0 && line[i] == '/' && line[i+1] == '*') {
        comment = 1;
        start_pos = i;
        end_pos = start_pos + 2;

        while (line[end_pos] != '*' && line[end_pos+1] != '/')
          ++end_pos;

        ++end_pos;

        for (/* void */; end_pos >= start_pos; --len, --end_pos)
          for (j = end_pos; j != len; ++j)
            line[j] = line[j+1];
      }
      else
      {
        comment = 0;
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
