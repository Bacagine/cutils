/**
 * cutils.h
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * cutils header file
 *
 * Date: 19/09/2023
 */

#ifndef _CUTILS_H_
#define _CUTILS_H_

/******************************************************************************
 *                                                                            *
 *                                 Includes                                   *
 *                                                                            *
 ******************************************************************************/
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <errno.h>
#ifndef _WIN32
  #include <time.h>
  #include <sys/utsname.h>
  #include <pwd.h>
#else
  #include <sys/timeb.h>
#endif
#include <unistd.h>
#include "date_time.h"

/******************************************************************************
 *                                                                            *
 *                             Defines and macros                             *
 *                                                                            *
 ******************************************************************************/

/**
 * This macro is used to remove
 * unused warnings during the
 * compilation.
 */
#define UNUSED(X) (void) X

/******************************************************************************
 *                                                                            *
 *                  Typedefs, structures, unions and enums                    *
 *                                                                            *
 ******************************************************************************/

/**
 * Structure that represents a address
 */
typedef struct STRUCT_ADDRESS
{
  char szStreet[64];
  int iNUmber;
  char szApartment[64];
  char szNeighborhood[64];
  char szCity[64];
  char szState[64];
  char szCEP[64]; /* In Brazil */
  char szZIP[64]; /* In USA    */
  char szCountry[64];
} STRUCT_ADDRESS, *PSTRUCT_ADDRESS;

/**
 * Structure that represents a
 * generic person.
 */
typedef struct STRUCT_PERSON
{
  STRUCT_ADDRESS stAddress;
  char szName[192];
  char szPhone[64];
  char szEmail[64];
} STRUCT_PERSON, *PSTRUCT_PERSON;

/**
 * Structure that represents a natural person.
 */
typedef struct STRUCT_NATURAL_PERSON
{
  STRUCT_PERSON stPersonInfo;
  char szFirstName[64];
  char szMiddleName[64];
  char szLastName[64];
  char szCPF[64]; /* In Brazil */
  char szSSN[64]; /* In USA    */
  STRUCT_DATE stBornDate;
  int iAge;
  char szNationality[64];
  char szMaritalStatus[64];
  char chSex; /* M or F */
} STRUCT_NATURAL_PERSON, *PSTRUCT_NATURAL_PERSON;

typedef struct STRUCT_JURIDICAL_PERSON
{
  STRUCT_PERSON stPersonInfo;
  char szCNPJ[64]; /* In Brazil */
  char szEIN[64];  /* In USA    */
  STRUCT_DATE stIncorporationDate;
  int iTimeInOperation;
  char szLegalForm[64];
} STRUCT_JURIDICAL_PERSON, *PSTRUCT_JURIDICAL_PERSON;

typedef struct STRUCT_LOGIN
{
  char szUser[64];
  char szPasswd[64];
} STRUCT_LOGIN, *PSTRUCT_LOGIN;

/******************************************************************************
 *                                                                            *
 *                     Global variables and constants                         *
 *                                                                            *
 ******************************************************************************/

extern const char *gkpszShortUFs[28];
extern const char *gkpszLongUFs[28];
extern const char *gkpszShortUSA_States[51];
extern const char *gkpszLongUSA_States[51];
extern const int gkiEIN_Prefixes[84];

/******************************************************************************
 *                                                                            *
 *                            Prototype functions                             *
 *                                                                            *
 ******************************************************************************/

/**
 * Check if the current user is root.
 */
bool bUserIsRoot(void);

/**
 * Check if the CPF is valid.
 */
bool bCPF_IsValid(const char *pszCPF);

/**
 * Check if the SSN if valid.
 */
bool bSSN_IsValid(const char *pszSSN);

/**
 * Check if the CNPJ is valid.
 */
bool bCNPJ_IsValid(const char *pszCNPJ);

/**
 * Check if the EIN is valid.
 */
bool bEIN_IsValid(const char *pszEIN);

/**
 * Check if the gender is valid (M or F)
 */
bool bSexIsValid(const char chSex);

#endif /* _CUTILS_H_ */

