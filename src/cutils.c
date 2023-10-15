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

/**
 * Andover      10, 12
 * Atlanta      60, 67
 * Austin       50, 53
 * Brookhaven   01, 02, 
 *              03, 04, 
 *              05, 06, 
 *              11, 13, 
 *              14, 16, 
 *              21, 22, 
 *              23, 24, 
 *              25, 34, 
 *              51, 52, 
 *              54, 55, 
 *              56, 57, 
 *              58, 59, 
 *              65
 * Cincinnati   30, 32, 35, 36, 37, 38, 61
 * Fresno       15, 24
 * Kansas City  40, 44
 * Memphis      94, 95
 * Ogden        80, 90
 * Philadelphia 33, 39,
 *              41, 42, 
 *              43, 46, 
 *              48, 62, 
 *              63, 64, 
 *              66, 68, 
 *              71, 72, 
 *              73, 74, 
 *              75, 76, 
 *              77, 85, 
 *              86, 87, 
 *              88, 91, 
 *              92, 93, 
 *              98, 99
 * Internet     20, 26, 
 *              27, 45, 
 *              46, 47, 
 *              81, 82, 
 *              83, 84, 
 *              85, 86, 
 *              87, 88, 
 *              92, 93
 * SBA          31
 *
 * Font: https://www.irs.gov/businesses/small-businesses-self-employed/how-eins-are-assigned-and-valid-ein-prefixes
 */
const int gkiEIN_Prefixes[84] = {
   1,  2,  3,  4,  5,  6, 
  10, 11, 12, 13, 14, 15,
  16, 20, 21, 22, 23, 24,
  25, 26, 27, 30, 31, 32,
  33, 34, 35, 36, 37, 38,
  39, 40, 41, 42, 43, 44,
  45, 46, 47, 48, 50, 51,
  52, 53, 54, 55, 56, 57,
  58, 59, 60, 61, 62, 63,
  64, 65, 66, 67, 68, 71,
  72, 73, 74, 75, 76, 77,
  80, 81, 82, 83, 84, 85,
  86, 87, 88, 90, 91, 92,
  93, 94, 95, 98, 99,  0 /* 0 is the end of array */
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
  if(strlen(szCPF) != 11)
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
  int ii;

  if(strlen(pszSSN) != 11)
  {
    return false;
  }

  if(pszSSN[3] != '-' || pszSSN[6] != '-')
  {
    return false;
  }

  for(ii = 0; pszSSN[ii] != '\0'; ii++)
  {
    if(ii == 3 || ii == 6) continue;

    if(!isdigit(pszSSN[ii]))
    {
      return false;
    }
  }
  
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
  
  if(strlen(szCNPJ) != 14)
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
  char szEIN[64];
  int ii;
  int jj = 0;
  char szEIN_Prefix[64];
  int iEIN_Prefix = 0;
  bool bValidPrefix = false;

  memset(szEIN       , 0, sizeof(szEIN       ));
  memset(szEIN_Prefix, 0, sizeof(szEIN_Prefix));
  
  if(pszEIN[2] != '-') return false;
  
  /**
   * Get only numbers
   */
  for(ii = 0; pszEIN[ii] != '\0'; ii++)
  {
    if(pszEIN[ii] == '-') continue;
    
    szEIN[jj++] = pszEIN[ii];
  }
  
  /* Verify the length */
  if(strlen(szEIN) != 9)
  {
    return false;
  }
  
  /**
   * Check if the content is only numbers
   */
  for(ii = 0; szEIN[ii] != '\0'; ii++)
  {
    if(!isdigit(szEIN[ii]))
    {
      return false;
    }
  }
  
  /**
   * Checking the EIN prefix
   */
  sprintf(szEIN_Prefix, "%d%d", szEIN[0] - '0', szEIN[1] - '0');
  
  iEIN_Prefix = atoi(szEIN_Prefix);
  
  for(ii = 0; gkiEIN_Prefixes[ii] != 0; ii++)
  {
    if(iEIN_Prefix == gkiEIN_Prefixes[ii])
    {
      bValidPrefix = true;
    }
  }
  
  if(!bValidPrefix) return false;

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

