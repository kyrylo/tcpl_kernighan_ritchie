/*
 * Write a program to print all input lines that are longer than 80 characters.
 *
 * Date: April 5, 2012
 */

#include <stdio.h>
#define MAXLINE 1000
#define LOWER_BOUND 80

int _getline(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
  int len;
  int max;
  char line[MAXLINE];

  max = 0;

  while ((len = _getline(line, MAXLINE)) > 0)
    if (len > LOWER_BOUND)
      printf("%s", line);

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

  return i-1;
}
