# CUTILS

My personal C util library for my C/C++ programs

To better understand my codes, read the README.md at [this link](https://github.com/Bacagine/Bacagine)


# How to use?

## Build and Install
```
# ./mkinstall
```

## Examples of usage

### Example 1 - file_len.c
```c
/**
 * file_len.c
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *
 * Description: Test of cutils/file.h
 *
 * Date: 20/09/2023
 */

#include <stdio.h>
#include <math.h>
#include "cutils/cutils.h"
#include "cutils/file.h"

/**
 * Convert the lenght in bytes to kilobytes.
 */
double dByte2KiloByte(long lByte);

/**
 * Convert the lenght in bytes to gigabytes.
 */
double dByte2GigaByte(long lBytes);

int main(int argc, char **argv)
{
  FILE *fpFile = NULL;
  char *pszFileName = "Makefile";
  
  UNUSED(argc);
  UNUSED(argv);
  
  if(!bFileExist(pszFileName))
  {
    fprintf(stderr, "E: %s no such file or directory!\n", pszFileName);
  }
  
  printf("The makefile have %.2lf KB\n", dByte2KiloByte(lGetFileLen(fpFile, pszFileName)));
  printf("The makefile have %lf GB\n", dByte2GigaByte(lGetFileLen(fpFile, pszFileName)));
  
  return 0;
}

double dByte2KiloByte(long lByte)
{
  return (double) lByte / 1024.0;
}

double dByte2GigaByte(long lBytes)
{
  return (double) lBytes / pow(1024.0, 3);
}


```

### Example 2 - getstr.c
```c
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

```

### Compile the codes

```
$ gcc -o file_len file_len.c -lcutils
$ gcc -o getstr getstr.c -lcutils
```

OBS: if you would like to test without installing, make sure to run the following command in your terminal:

```
$ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./lib
```

### Uninstall

```
# ./mkuninstall
```
