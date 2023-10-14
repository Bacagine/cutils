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

bool bCPF_IsValid(const char *pszCPF)
{
  char szCPF[64];
  int ii;
  int jj = 0;
  int iRsl = 0;
  bool bEquals = true;
  
  memset(szCPF, 0, sizeof(szCPF));
  
  /**
   * Ignore '.' and '-' of string
   */
  for(ii = 0; pszCPF[ii] != '\0'; ii++)
  {
    if(pszCPF[ii] != '.' && pszCPF[ii] != '-')
    {
      szCPF[jj++] = pszCPF[ii];
    }
  }
  
  /**
   * Check the quantity of digits
   */
  if(strlen(szCPF) > 11)
  {
    return false;
  }

  /**
   * Is numeric?
   */
  for(ii = 0; szCPF[ii] != '\0'; ii++)
  {
    if(!isdigit(szCPF[ii]))
    {
      return false;
    }
  }

  /**
   * Check if all numbers are equals
   */
  for(ii = 0; szCPF[ii] != '\0'; ii++)
  {
    if(szCPF[0] != szCPF[ii])
    {
      bEquals = false;
      break;
    }
  }

  if(bEquals)
  {
    return false;
  }
  
  /****************************************************************************
   *                                                                          *
   *                   Validating the first digit after '-'                   *
   *                                                                          *
   ****************************************************************************/
  for(ii = 0, jj = 10; ii != 9; ii++, jj--)
  {
    iRsl += (szCPF[ii] - '0') * jj;
  }
  
  iRsl = iRsl * 10 % 11;
  
  if(iRsl == 10)
  {
    iRsl = 0;
  }

  if(iRsl != (szCPF[9] - '0'))
  {
    return false;
  }
   
  /****************************************************************************
   *                                                                          *
   *                   Validating the second digit after '-'                  *
   *                                                                          *
   ****************************************************************************/
  iRsl = 0;

  for(ii = 0, jj = 11; ii != 10; ii++, jj--)
  {
    iRsl += (szCPF[ii] - '0') * jj;
  }
  
  iRsl = iRsl * 10 % 11;

  if(iRsl == 10)
  {
    iRsl = 0;
  }

  if(iRsl != (szCPF[10] - '0'))
  {
    return false;
  }

  return true;
}

bool bSSN_IsValid(const char *pszSSN)
{
  UNUSED(pszSSN);
  return true;
}

bool bCNPJ_IsValid(const char *pszCNPJ)
{
  UNUSED(pszCNPJ);
  return true;
}

bool bEIN_IsValid(const char *pszEIN)
{
  UNUSED(pszEIN);
  return true;
}

bool bGenderIsValid(const char chSex)
{
  if(toupper(chSex) == 'M' || toupper(chSex) == 'F')
  {
    return true; 
  }
  return false;
}

