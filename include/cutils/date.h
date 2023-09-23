/**
 * date.h
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * Description: 
 *
 * Date: 21/09/2023
 */

#ifndef _CUTILS_DATE_H_
#define _CUTILS_DATE_H_

#include <stdio.h>
#include <string.h>
#ifndef _WIN32
  #include <time.h>
#else
  #include <sys\timeb.h> 
#endif
#include <stdbool.h>

const char *kpszDateFormat[8] = {
                                  "ddmmaa",
                                  "ddmmaaaa",
                                  "aaaammdd",
                                  "aammdd",
                                  "mmddaaaa",
                                  "mmddaa",
                                  "-99"
                                };
// const char *kpszDDMMAA  = "ddmmaa";
// const char *kpszDDMMAAAA= "ddmmaaaa";
// const char *kpszAAAAMMDD= "aaaammdd";
// const char *kpszAAMMDD  = "aammdd";
// const char *kpszMMDDAAAA= "mmddaaaa";
// const char *kpszMMDDAA  = "mmddaa";
// const char *kpszERROR   = "-99";

typedef enum ENUM_OTPFMT{
  DDMMAA=0,
  DDMMAAAA,
  AAAAMMDD,
  AAMMDD,
  MMDDAAAA,
  MMDDAA,
  FMTERROR, 
}ENUM_OTPFMT;

ENUM_OTPFMT eMatchOutputFormat(const char *kpszFmt);

/**
 * This structure 
 * that represents
 * a date.
 */
typedef struct STRUCT_DATE
{
  int iDay;
  int iMonth;
  int iYear;
} STRUCT_DATE, *PSTRUCT_DATE;

/**
 * Week days
 */
const char *kpszWeekDays[] = {
  "Sunday"   , "Monday"  , "Tuesday",
  "Wednesday", "Thursday", "Friday",
  "Saturday" , NULL
};

/**
 * Months of Year
 */
const char *kpszMonths[] = {
  "January", "February", "March",
  "April"  , "May"     , "June",
  "July"   , "August"  , "Setember",
  "October", "November", "December", 
  NULL
};

/**
 * Check if a year is a leap year.
 */
bool bYearIsLeapYear(int iYear);

/**
 * Validate a date
 */
bool bDateIsValid(STRUCT_DATE *pstDate);

/**
 * Check if the dates are the same
 */
bool bDatesIsEqual(STRUCT_DATE *pstDateOne, STRUCT_DATE *pstDateTwo);

/**
 * Save the formated date in szOutput, if szOutput is
 * NULL, the format is invalid.
 */
void vFormatDate(const STRUCT_DATE *kpstDate,
                 const char *kpszFmt,
                 char **szOutput,
                 char *pchDlm);

#endif /* _CUTILS_DATE_H_  */

