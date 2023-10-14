#include <stdio.h>
#include "cutils/cutils.h"

int main(int argc, char **argv)
{
  UNUSED(argc);
  UNUSED(argv);

#ifdef BR_COMPILATION
  printf("It is Brazilian compilation\n");
#endif

  return 0;
}

