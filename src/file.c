/**
 * file.c
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * Description: 
 *
 * Date: 20/09/2023
 */

#include "cutils/file.h"

bool bOpenFile(FILE **fppFile, const char *kpszFileName, const char *kpszMode)
{
  if((*fppFile = fopen(kpszFileName, kpszMode)) == NULL)
  {
    return false;
  }

  return true;
}

bool bCloseFile(FILE **fppFile)
{
  if(*fppFile != NULL)
  {
    fclose(*fppFile);
    *fppFile = NULL;

    return true;
  }

  return false;
}

bool bFileExist(const char *kpszFileName)
{
  FILE *fpFile;
  
  if(!bOpenFile(&fpFile, kpszFileName, "r"))
  {
    return false;
  }
  
  bCloseFile(&fpFile);

  return true;
}

bool bRemoveFile(const char *kpszFileName)
{
  if(remove(kpszFileName) != 0)
  {
    return false;
  }

  return true;
}

long lGetFileLen(FILE *fpFile, const char *kpszFileName)
{
  long lBytes = 0;
  
  if(!bOpenFile(&fpFile, kpszFileName, "rb"))
  {
    return -1;
  }

  if(fseek(fpFile, 0L, SEEK_END) != 0)
  {
    bCloseFile(&fpFile);

    return -2;
  }

  if((lBytes = ftell(fpFile)) == -1)
  {
    return -3;
  }

  bCloseFile(&fpFile);
 
  return lBytes;
}

