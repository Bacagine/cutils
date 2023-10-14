/**
 * cnpj.c
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@prtonmail.com>
 *
 * Description: Check if a CNPJ is valid.
 *
 * Date: 14/10/2023
 */

#include <stdio.h>
#include "cutils/cutils.h"
#include "cutils/io.h"

int main(int argc, char **argv)
{
  char szCNPJ[64];

  memset(szCNPJ, 0, sizeof(szCNPJ));
  
  UNUSED(argc);
  UNUSED(argv);

  printf("Type a CNPJ to check if is valid: ");

  vFgets(szCNPJ, sizeof(szCNPJ), stdin);

  if(bCNPJ_IsValid(szCNPJ) == true)
  {
    printf("The CNPJ \"%s\" is valid\n", szCNPJ);
  }
  else
  {
    printf("The CNPJ \"%s\" is invalid\n", szCNPJ);
  }
  

  return 0;
}

