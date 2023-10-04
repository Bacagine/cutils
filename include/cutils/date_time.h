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
 "ddmmaa"  , "ddmmaaaa",
 "aaaammdd", "aammdd",
 "mmddaaaa", "mmddaa",
 "-99"
};

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

typedef struct STRUCT_TIME
{
  int iHour;
  int iMinute;
  int iSecond;
} STRUCT_TIME, *PSTRUCT_TIME;

typedef enum ENUM_DATE_FMT
{
  DDMMAA,
  DDMMAAAA,
  AAAAMMDD,
  AAMMDD,
  MMDDAAAA,
  MMDDAA,
  FMTERROR, 
} ENUM_DATE_FMT;

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

/**
 * Return the format was used in kpszFmt
 */
ENUM_DATE_FMT eMatchDateOutputFormat(const char *kpszFmt);

/**
 *
 */
bool bTimeIsValid(STRUCT_TIME *pstTime);

/**
 *
 */
bool bTimeIsEqual(STRUCT_TIME *pstTimeOne, STRUCT_TIME *pstTimeTwo);

/**
 *
 */
void vFormatTime(const STRUCT_TIME *kpstTime,
                 const char *kpszFmt,
                 char **szOutput);
#endif /* _CUTILS_DATE_H_  */

