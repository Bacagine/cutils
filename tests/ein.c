/**
 * ein.c
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@prtonmail.com>
 *
 * Description: Check if a EIN is valid.
 *
 * Date: 14/10/2023
 */

#include <stdio.h>
#include "cutils/cutils.h"
#include "cutils/io.h"

int main(int argc, char **argv)
{
  char szEIN[64];

  memset(szEIN, 0, sizeof(szEIN));
  
  UNUSED(argc);
  UNUSED(argv);

  printf("Type a EIN to check if is valid: ");

  vFgets(szEIN, sizeof(szEIN), stdin);

  if(bEIN_IsValid(szEIN) == true)
  {
    printf("The EIN \"%s\" is valid\n", szEIN);
  }
  else
  {
    printf("The EIN \"%s\" is invalid\n", szEIN);
  }
  

  return 0;
}

