/**
 * dir.c
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * Description: 
 *
 * Date: 20/09/2023
 */

#include "cutils/cutils.h"
#include "cutils/dir.h"

#ifndef _WIN32
bool bPathIsDir(const char *kpszPath)
{
  struct stat stPath;

  stat(kpszPath, &stPath);

  if(S_ISDIR(stPath.st_mode) == 0)
  {
    return true;
  }
  
  return false;
}

bool bOpenDir(DIR **ppDir, const char *kpszDirName)
{
  if(!bPathIsDir(kpszDirName)) return false;

  if((*ppDir = opendir(kpszDirName)) == NULL)
  {
    return false;
  }

  return true;
}

void vListDir(DIR *pDir)
{
  UNUSED(pDir);
  return;
}

void vTreeDir(DIR *pDir)
{
  UNUSED(pDir);
  return;
}

bool bCloseDir(DIR **ppDir)
{
  if(*ppDir != NULL)
  {
    closedir(*ppDir);
    *ppDir = NULL;
    
    return true;
  }

  return false;
}

int iMkDir(const char *kpszDirName,
           const int iUmask)
{
  int iRsl;
  
  if(bPathIsDir(kpszDirName)) return -1;

  if((iRsl = mkdir(kpszDirName, iUmask)) != 0)
  {
    return 1;
  }

  return 0;
}

bool bRmDir(const char *kpszDirName)
{
  int iRsl;

  if((iRsl = rmdir(kpszDirName)) != 0)
  {
    return false;
  }

  return true;
}
#else
bool bPathIsDir(const char *kpszPath)
{
  return true;
}

bool bOpenDir(DIR **ppDir, const char *kpszDirName)
{
  return true;
}

void vListDir(DIR *pDir)
{
  return;
}

void vTreeDir(DIR *pDir)
{
  return;
}

bool bCloseDir(DIR **ppDir)
{
  return true;
}

int iMkDir(const char *kpszDirName,
           const int iUmask)
{
  return 0;
}

bool bRmDir(const char *kpszDirName)
{
  return true;
}
#endif

