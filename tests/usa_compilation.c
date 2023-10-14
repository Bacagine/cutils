#include <stdio.h>
#include "cutils/cutils.h"

int main(int argc, char **argv)
{
  UNUSED(argc);
  UNUSED(argv);

#ifdef USA_COMPILATION
  printf("It is USA compilation\n");
#endif

  return 0;
}

