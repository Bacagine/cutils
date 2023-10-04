/**
 * cutils.c
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * Description: 
 *
 * Date: 20/09/2023
 */

#include <stdio.h>
#include "cutils/cutils.h"
#include "cutils/str.h"

bool bTerminalSupportColors(void)
{
  char *szTerm = getenv("TERM");
  
  if(bStrIsEmpty(szTerm) || !strcmp(szTerm, "dumb"))
  {
    return false;
  }
  
  return true;
}

bool bUserIsRoot(void)
{
#ifndef _WIN32
  uid_t uidEuid = geteuid();

  if(uidEuid == 0)
  {
    return true;
  }
#else
  return true;
#endif
  return false;
}

