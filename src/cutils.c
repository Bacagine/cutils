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

const char *gkpszShortUFs[28] = {
  "AC", "AL", "AP", "AM",
  "BA", "CE", "DF", "ES",
  "GO", "MA", "MT", "MS",
  "MG", "PA", "PB", "PR",
  "PE", "PI", "RJ", "RN",
  "RS", "RO", "RR", "SC",
  "SP", "SE", "TO", NULL
};

const char *gkpszLongUFs[28] = {
  "Acre"             , "Alagoas" , "Amapa"            , "Amazonas"           ,
  "Bahia"            , "Ceara"   , "Distrito Federal" , "Espirito Santo"     ,
  "Goiais"           , "Maranhao", "Mato Grosso"      , "Mato Grosso do Sul" ,
  "Minas Gerais"     , "Para"    , "Paraiba"          , "Parana"             ,
  "Pernanbuco"       , "Piaui"   , "Rio de Janeiro"   , "Rio Grande do Norte",
  "Rio Grande do Sul", "Rondonia", "Roraima"          , "Santa Catarina"     ,
  "Sao Paulo"        , "Sergipe" , "Tocantins"        , NULL
};

const char *gkpszShortUSA_States[51] = {
  "AL", "AK", "AZ", "AR", "CA",
  "CO", "CT", "DE", "FL", "GA",
  "HI", "ID", "IL", "IN", "IA",
  "KS", "KY", "LA", "ME", "MD",
  "MA", "MI", "MN", "MS", "MO",
  "MT", "NE", "NV", "NH", "NJ",
  "NM", "NY", "NC", "ND", "OH",
  "OK", "OR", "PA", "RI", "SC",
  "SD", "TN", "TX", "UT", "VT",
  "VA", "WA", "WV", "WI", "WY",
  NULL
};

const char *gkpszLongUSA_States[51] =  {
  "Alabama"      , "Alaska"     , "Arizona"       , "Arkansas"     , "California",
  "Colorado"     , "Connecticut", "Delaware"      , "Florida"      , "Georgia"   ,
  "Hawaii"       , "Idaho"      , "Illinois"      , "Indiana"      , "Iowa"      ,
  "Kansas"       , "Kentucky"   , "Louisiana"     , "Maine"        , "Maryland"  ,
  "Massachusetts", "Michigan"   , "Minnesota"     , "Mississippi"  , "Missouri"  ,
  "Montana"      , "Nebraska"   , "Nevada"        , "New Hampshire", "New Jersey",
  "New Mexico"   , "New York"   , "North Carolina", "North Dakota" , "Ohio",
  "Oklahoma"     , "Oregon"     , "Pennsylvania"  , "Rhode Island" , "South Carolina",
  "Shouth Dakota", "Tennessee"  , "Texas"         , "Utah"         , "Vermont",
  "Virginia"     , "Washington" , "West Verginia" , "Wisconsin"    , "Wyoming",
  NULL
};

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
   * Ignore '.' and '-' of the string
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
  char szCNPJ[64];
  int ii;
  int jj = 0;
  bool bEquals = true;
  int iRsl = 0;

  memset(szCNPJ, 0, sizeof(szCNPJ));

  /**
   * Ignore '.',  '/' and '-' of the string
   */
  for(ii = 0; pszCNPJ[ii] != '\0'; ii++)
  {
    if(pszCNPJ[ii] != '.' && pszCNPJ[ii] != '/' && pszCNPJ[ii] != '-')
    {
      szCNPJ[jj++] = pszCNPJ[ii];
    }
  }
  
  if(strlen(szCNPJ) > 14)
  {
    return false;
  }
  
  /**
   * Is numeric?
   */
  for(ii = 0; szCNPJ[ii] != '\0'; ii++)
  {
    if(!isdigit(szCNPJ[ii]))
    {
      return false;
    }
  }

  /**
   * Check if all numbers are equals
   */
  for(ii = 0; szCNPJ[ii] != '\0'; ii++)
  {
    if(szCNPJ[0] != szCNPJ[ii])
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
  for(ii = 0, jj = 5; ii < 12; ii++, jj--)
  {
    if(jj == 1)
    {
      jj = 9;
    }

    iRsl += (szCNPJ[ii] - '0') * jj;
  }

  iRsl = iRsl % 11;
  
  if(iRsl < 2)
  {
    iRsl = 0;
  }
  else
  {
    iRsl = 11 - iRsl;
  }

  if(iRsl != (szCNPJ[12] - '0'))
  {
    return false;
  }

  /****************************************************************************
   *                                                                          *
   *                   Validating the second digit after '-'                  *
   *                                                                          *
   ****************************************************************************/
  iRsl = 0;

  for(ii = 0, jj = 6; ii < 13; ii++, jj--)
  {
    if(jj == 1)
    {
      jj = 9;
    }

    iRsl += (szCNPJ[ii] - '0') * jj;
  }

  iRsl = iRsl % 11;

  if(iRsl < 2)
  {
    iRsl = 0;
  }
  else
  {
    iRsl = 11 - iRsl;
  }

  if(iRsl != (szCNPJ[13] - '0'))
  {
    return false;
  }

  return true;
}

bool bEIN_IsValid(const char *pszEIN)
{
  UNUSED(pszEIN);
  return true;
}

bool bSexIsValid(const char chSex)
{
  if(toupper(chSex) == 'M' || toupper(chSex) == 'F')
  {
    return true; 
  }
  return false;
}

