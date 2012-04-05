/*
 * NOT SOLVED!
 * Revise the main routine of the longest-line program so it will correctly
 * print the length of arbitrary long input lines, and as much as possible
 * of the text.
 *
 * This assignment is fucking retarded. I don't even know, how to initialize an
 * array of unresolved size. I can't believe, that they haven't fixed it yet!
 *
 * Date: April 5, 2012
 */

#include <stdio.h>
#define MAXLINE 1000

int _getline(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
  int len;
  int max = 0;
  char line[MAXLINE];
  char longest[MAXLINE];

  while ((len = _getline(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }

  if (max > 0)
    printf("%s", longest);

  return 0;
}

int _getline(char s[],int lim)
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

void copy(char to[], char from[])
{
  int i = 0;

  while ((to[i] = from[i]) != '\0')
    ++i;
}
