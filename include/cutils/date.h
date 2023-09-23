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
#include <time.h>
#include <stdbool.h>

/**
 * This structure 
 * that represents
 * a date.
 */
typedef struct Date
{
  int iDay;
  int iMonth;
  int iYear;
} Date, *PDate;

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
bool bDateIsValid(Date *pstDate);

/**
 * Check if the dates are the same
 */
bool bDatesIsEqual(Date *pstDateOne, Date *pstDateTwo);

/**
 * Save the formated date in szOutput, if szOutput is
 * NULL, the format is invalid.
 */
void vFormatDate(const Date *kpstDate,
                 const char *kpszFmt,
                 char **szOutput);

#endif /* _CUTILS_DATE_H_  */

