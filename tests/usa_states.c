/**
 * usa_states.c
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@prtonmail.com>
 *
 * Description: Show the name of USA states.
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

  puts("The states of USA are:");

  for(ii = 0; kpszShortUSA_States[ii] != NULL; ii++)
  {
    printf("%s - (%s)\n", kpszLongUSA_States[ii], kpszShortUSA_States[ii]);
  }

  return 0;
}

