/**
 * ssn.c
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@prtonmail.com>
 *
 * Description: Check if a SSN is valid.
 *
 * Date: 14/10/2023
 */

#include <stdio.h>
#include "cutils/cutils.h"
#include "cutils/io.h"

int main(int argc, char **argv)
{
  char szSSN[64];

  memset(szSSN, 0, sizeof(szSSN));

  UNUSED(argc);
  UNUSED(argv);

  printf("Type a SSN to validate: ");
  
  vFgets(szSSN, sizeof(szSSN), stdin);

  if(bSSN_IsValid(szSSN))
  {
    printf("The SSN %s is valid\n", szSSN);
  }
  else
  {
    printf("The SSN %s is invalid\n", szSSN);
  }

  return 0;
}

