/*
 * Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines.
 *
 * Date: April 5, 2012
 */

#include <stdio.h>
#define MAXLINE 1000

int _getline(char line[], int maxline);
void copy(char to[], char from[]);
void remove_trailing(char line[], int len);

main()
{
  int len;
  int max;
  char line[MAXLINE];

  max = 0;

  while ((len = _getline(line, MAXLINE)) > 0)
    if (len > 0) {
      remove_trailing(line, len);
      printf("%s", line);
    }

  return 0;
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

void remove_trailing(char s[], int len)
{
  int i;

  for (i = len; i > 0; --i)
    if (s[i-1] == ' ' || s[i-1] == '\t' || s[i-1] == '\n')
      s[i] = '\0';
    else {
      s[i+1] = '\n';
      s[i+2] = '\0';
      i = 0;
    }
}
