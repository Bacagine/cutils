#include <stdio.h>
#include "cutils/cutils.h"
#include "cutils/io.h"

int main(int argc, char **argv)
{
  char szCPF[64];

  memset(szCPF, 0, sizeof(szCPF));
  
  UNUSED(argc);
  UNUSED(argv);

  printf("Type a CPF to check if is valid: ");

  vFgets(szCPF, sizeof(szCPF), stdin);

  if(bCPF_IsValid(szCPF) == true)
  {
    printf("The CPF \"%s\" is valid\n", szCPF);
  }
  else
  {
    printf("The CPF \"%s\" is invalid\n", szCPF);
  }
  

  return 0;
}
