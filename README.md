# CUtils

My personal C Utilities Library for my C/C++ programs

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
#include <stdlib.h>
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

    exit(EXIT_FAILURE);
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

### Example 3 - cpf.c
```c
/**
 * cpf.c
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@prtonmail.com>
 *
 * Description: Check if a CPF is valid.
 *
 * Date: 14/10/2023
 */

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

```

### Example 4 - cnpj.c
```c
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

```

### Example 5 - br_states.c
```c
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
```


### Example 6 - usa_states.c
```c
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
```

### Example 7 - ssn.c
```c
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
```

### Compile the codes
```
$ gcc -o file_len file_len.c -lcutils
$ gcc -o getstr getstr.c -lcutils
$ gcc -o cpf cpf.c -lcutils
$ gcc -o cnpj cnpj.c -lcutils
$ gcc -o br_states br_states.c -lcutils
$ gcc -o usa_states usa_states.c -lcutils
```

OBS: if you would like to test without installing, make sure to run the following command in your terminal:

```
$ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./lib
```

### Uninstall
```
# ./mkuninstall
```

