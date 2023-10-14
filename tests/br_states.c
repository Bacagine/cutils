/**
 * br_states.c
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@prtonmail.com>
 *
 * Description: Show the name of Brazilian states.
 *
 * Date: 14/10/2023
 */

#include <stdio.h>
#include "cutils/cutils.h"

int main(int argc, char **argv)
{
  int ii = 0;

  UNUSED(argc);
  UNUSED(argv);

  puts("The states of Brazil are:");

  for(ii = 0; kpszShortUFs[ii] != NULL; ii++)
  {
    printf("%s - (%s)\n", kpszLongUFs[ii], kpszShortUFs[ii]);
  }

  return 0;
}

