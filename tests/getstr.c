/**
 * getstr.c
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@prtonmail.com>
 *
 * Description: Teste to cutils/io.h
 *
 * Date: 20/09/2023
 */

#include "cutils/cutils.h"
#include "cutils/string.h"
#include "cutils/io.h"

int main(int argc, char **argv)
{
  char szName[64];

  memset(szName, 0, sizeof(szName));

  UNUSED(argc);
  UNUSED(argv);

  printf("Type your name: ");
  vFgets(szName, sizeof(szName), stdin);

  printf("Hello %s\n", szName);

  return 0;
}

