/**
 * date_time.h
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * Description: Date and time manipulation functions
 *
 * Date: 21/09/2023
 */

#ifndef _CUTILS_DATE_TIME_H_
#define _CUTILS_DATE_TIME_H_

#include <stdio.h>
#include <string.h>
#ifndef _WIN32
  #include <time.h>
#else
  #include <sys\timeb.h> 
#endif
#include <stdbool.h>
#include "consts.h"

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
  DDMMYY,
  DDMMYYYY,
  YYYYMMDD,
  YYMMDD,
  MMDDYYYY,
  MMDDYY,
  FMTERROR, 
} ENUM_DATE_FMT;

/**
 * @enum ENUM_TIME_FMT
 * @brief Time format enumeration for string formatting/parsing.
 */
typedef enum ENUM_TIME_FMT {
  HHMM,
  HHMMSS,
  HHMMSSM,
  TIME_FMTERROR
} ENUM_TIME_FMT;

/**
 * Date formates string array
 */
extern const char *gkpszDateFormat[8];

/**
 * Week days
 */
extern const char *gkpszWeekDays[];

/**
 * Brazilian week days
 */
extern const char *gkpszBR_WeekDays[];

/**
 * Months of year
 */
extern const char *gkpszMonths[];

/**
 * Brazilian months of year.
 */
extern const char *gkpszBR_Months[];

/**
 * Get the current date of the system
 * and save in ppstDate
 */
void vGetCurrentDate(PSTRUCT_DATE *ppstDate);

/**
 * Get the current time of the system
 * and save in ppstTime
 */
void vGetCurrentTime(PSTRUCT_TIME *ppstTime);

/**
 * Save the current date in ppstDate and current time in ppstTime.
 */
void vGetCurrentDateTime(PSTRUCT_DATE *ppstDate, PSTRUCT_TIME *ppstTime);

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
                 char *szOutput,
                 char *pchDlm);

/**
 * Print date in specific format
 */
void vPrintDate(PSTRUCT_DATE pstDate, const char *kpszFmt);

/**
 * @brief Parses a date string into a STRUCT_DATE based on the specified format and separator.
 *
 * Extracts day, month, and year from the input string and stores them in the date structure.
 *
 * @param pstDate Pointer to the date structure to populate.
 * @param kpszDate Input date string.
 * @param pszSeparator Separator used in the date string.
 * @param eDateFmt Date format enumeration that matches the input format.
 */
void vGetDateFromStr(PSTRUCT_DATE pstDate, const char *kpszDate, char *pszSeparator, ENUM_DATE_FMT eDateFmt);

/**
 * @brief Formats a time structure into a string according to the specified format.
 *
 * Converts the given STRUCT_TIME into a formatted string based on the time format enumeration.
 *
 * @param kpszTime Pointer to the time structure to format.
 * @param eTimeFmt Time format enumeration specifying output format.
 * @param pszOutput Buffer to receive the formatted time string.
 * @param lOutputSize Size of the output buffer.
 */
void vFormatTime(
  const PSTRUCT_TIME kpszTime,
  const ENUM_TIME_FMT eTimeFmt,
  char *pszOutput,
  size_t lOutputSize);

/**
 * @brief Prints a time structure to standard output using the specified format.
 *
 * Outputs the formatted time to stdout.
 *
 * @param pstTime Pointer to the time structure to print.
 * @param eTimeFmt Time format enumeration.
 */
void vPrintTime(PSTRUCT_TIME pstTime, ENUM_TIME_FMT eTimeFmt);

/**
 * @brief Prints a date and time combination to standard output.
 *
 * Formats and outputs the date and time according to the specified formats and separator.
 *
 * @param pstDate Pointer to the date structure.
 * @param eDateFmt Date format enumeration.
 * @param kpszDateSeparator Separator string between date components.
 * @param pstTime Pointer to the time structure.
 * @param eTimeFmt Time format enumeration.
 */
void vPrintDateTime(PSTRUCT_DATE pstDate, ENUM_DATE_FMT eDateFmt, const char *kpszDateSeparator, PSTRUCT_TIME pstTime, ENUM_TIME_FMT eTimeFmt);

/**
 * Return the format was used in kpszFmt
 */
ENUM_DATE_FMT eMatchDateOutputFormat(const char *kpszFmt);

/**
 * Check if the values of pstTime is
 * valid
 */
bool bTimeIsValid(STRUCT_TIME *pstTime);

/**
 * Check if two times are equals
 */
bool bTimeIsEqual(STRUCT_TIME *pstTimeOne, STRUCT_TIME *pstTimeTwo);

/**
 * Save a formatted time in szOutput
 */
void vFormatTime(const STRUCT_TIME *kpstTime,
                 const char *kpszFmt,
                 char *szOutput);

/**
 * Print time in specific format
 */
void vPrintTime(PSTRUCT_TIME pstTime, const char *kpszFmt);

/**
 * Print date and time in specific format
 */
void vPrintDateTime(PSTRUCT_DATE pstDate,
                    const char *kpszDateFmt,
                    PSTRUCT_TIME pstTime,
                    const char *kpszTimeFmt);

#endif /* _CUTILS_DATE_TIME_H_ */

