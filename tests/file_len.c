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

