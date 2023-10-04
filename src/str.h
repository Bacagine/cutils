/**
 * string.c
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * Description: My cutils file
 *
 * Date: dd/mm/aaaa
 */

#include <stdio.h>
#include "cutils/cutils.h"
#include "cutils/str.h"

bool bStrIsEmpty(const char *kpszStr)
{
  if(kpszStr == NULL || !strcmp(kpszStr, "") || !strcmp(kpszStr, "\n"))
  {
    return true;
  }
  
  return false;
}

void szStrUpper(char *pszDest, char *pszStrLower)
{
  int ii;
  
  for(ii = 0; pszStrLower[ii] != '\0'; ii++)
  {
    pszDest[ii] = toupper(pszStrLower[ii]);
  }
}

void szStrLower(char *pszDest, char *pszStrUpper)
{
  int ii;
  
  for(ii = 0; pszStrUpper[ii] != '\0'; ii++)
  {
    pszDest[ii] = tolower(pszStrUpper[ii]);
  }
}

void vRemoveEnter(char *pszStr)
{
  if(bStrIsEmpty(pszStr)) return;

  if(pszStr[strlen(pszStr)-1] == '\n')
  {
    pszStr[strlen(pszStr)-1] = '\0';
  }
}

void vRemoveNewLines(char *pszStr)
{
  if(bStrIsEmpty(pszStr)) return;

  strtok(pszStr, "\r\n");
}

