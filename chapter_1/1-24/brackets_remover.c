/*
 * Write a program to check a C program for rudimentary syntax errors like
 * unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
 * double, escape sequences, and comments. (This program is hard if you do it in full
 * generality.)
 *
 * Note: The solution doesn't handle the following kind of input:
 *
 *   % ./a.out
 *   This ]is not a real[ program!
 *
 * What you see above is a valid input, according to this program. But in
 * effect, an error message should appear.
 *
 * Date: April 15, 2012
 */

#include <stdio.h>

#define MAXLINE 1000
#define L_SQR_BRACKET '['
#define R_SQR_BRACKET ']'
#define L_BRACKET     '('
#define R_BRACKET     ')'
#define S_QUOTE       '\''
#define D_QUOTE       '"'
#define SLASH         '/'
#define ASTERISK      '*'
#define L_BRACE       '{'
#define R_BRACE       '}'

int _getline(char line[], int maxline);
void msg_syntax_error(void);

main()
{
  int i, len;
  char line[MAXLINE];

  /* Flags of the appearance of the brackets and stuff */
  int sqr_bracket, bracket, s_quote, d_quote, comment, brace;

  while ((len = _getline(line, MAXLINE)) > 0) {
    sqr_bracket = bracket = s_quote = d_quote = comment = brace = 0;

    for (i = 0; i < len; ++i) {

      if (line[i] == L_SQR_BRACKET)
      {
        ++sqr_bracket;
      }
      else if (line[i] == R_SQR_BRACKET)
      {
        --sqr_bracket;
      }
      else if (line[i] == L_BRACKET)
      {
        ++bracket;
      }
      else if (line[i] == R_BRACKET)
      {
        --bracket;
      }
      else if (line[i] == S_QUOTE)
      {
        ++s_quote;
      }
      else if (line[i] == D_QUOTE)
      {
        ++d_quote;
      }
      else if (line[i] == SLASH && line[i+1] == ASTERISK)
      {
        ++comment;
      }
      else if (line[i] == ASTERISK && line[i+1] == SLASH)
      {
        --comment;
      }
      else if (line[i] == L_BRACE)
      {
        ++brace;
      }
      else if (line[i] == R_BRACE)
      {
        --brace;
      }
    }

    if (sqr_bracket == 0 && bracket == 0 &&
        (s_quote & 1) == 0  && (d_quote & 1) == 0 &&
        brace == 0 && comment == 0)
    {
      printf("%s", line);
    }
    else
    {
      msg_syntax_error();
    }

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

void msg_syntax_error()
{
  printf("Syntax error: unmatched something\n");
}
