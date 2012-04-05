/*
 * Write a function reverse(s) that reverses the character string s. Use it to
 * write a program that reverses its input a line at a time.
 *
 * Date: April 5, 2012
 */

#include <stdio.h>
#define MAXLINE 1000

int _getline(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char line[]);

main()
{
  int len;
  int max;
  char line[MAXLINE];

  max = 0;

  while ((len = _getline(line, MAXLINE)) > 0)
    if (len > 0) {
      reverse(line);
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

void reverse(char s[])
{
  int i, j;
  int len = 0;
  while (s[len] != '\0')
    ++len;
  char reversed_s[len];

  j = 0;

  /* Actual reversion */
  for (i = len-2; i >= 0; --i) {
    reversed_s[j] = s[i];
    ++j;
  }

  /* Copy the characters back to the orginal array */
  for (i = 0; i < len-1; ++i) {
    s[i] = reversed_s[i];
  }

  s[i] = '\n';
  s[i+1] = '\0';
}
