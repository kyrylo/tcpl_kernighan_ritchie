/*
 * Write a program to determine the ranges of char, short, int, and long
 * variables, both signed and unsigned, by printing appropriate values from
 * standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types.
 *
 * Date: April 15, 2012
 */

#include <stdio.h>
#include <limits.h>

main()
{
  printf("Ranges from limits.h:\n\n");

  printf("char bit: %d\n", CHAR_BIT);
  printf("signed char min: %d\n", SCHAR_MIN);
  printf("signed char max: %d\n", SCHAR_MAX);
  printf("unsigned char min: 0\n");
  printf("unsigned char max: %d\n\n", UCHAR_MAX);

  printf("(signed) short int min: %d\n", SHRT_MIN);
  printf("(signed) short int max: %d\n", SHRT_MAX);
  printf("unsigned short int min: 0\n");
  printf("unsigned short int max: %u\n\n", USHRT_MAX);

  printf("(signed) int min: %d\n", INT_MIN);
  printf("(signed) int max: %d\n", INT_MAX);
  printf("unsigned int min: 0\n");
  printf("unsigned int max: %u\n\n", UINT_MAX);

  printf("(signed) long int min: %ld\n", LONG_MIN);
  printf("(signed) long int max: %ld\n", LONG_MAX);
  printf("unsigned long int min: 0\n");
  printf("unsigned long int max: %lu\n", ULONG_MAX);
}
