/**
 * date_time.c
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * Description: Date and time manipulation functions
 *
 * Date: 21/09/2023
 */

#include <stdlib.h>
#include "cutils/date_time.h"
#include "cutils/str.h"

const char *gkpszDateFormat[8] = {
 "ddmmaa"  , "ddmmaaaa",
 "aaaammdd", "aammdd"  ,
 "mmddaaaa", "mmddaa"  ,
 "-99"
};

const char *gkpszWeekDays[] = {
  "Sunday"   , "Monday"  , "Tuesday",
  "Wednesday", "Thursday", "Friday" ,
  "Saturday" , NULL
};

const char *gkpszBR_WeekDays[] = {
  "Domingo", "Segunda", "Terca", 
  "Quarta" , "Quinta" , "Sexta", 
  "Sabado", NULL
};

const char *gkpszMonths[] = {
  "January", "February", "March"   ,
  "April"  , "May"     , "June"    ,
  "July"   , "August"  , "Setember",
  "October", "November", "December", 
  NULL
};

const char *gpkszBR_Months[] = {
  "Janeiro", "Fevereiro", "Marco"   ,
  "Abril"  , "Maio"     , "Junho"   ,
  "Julho"  , "Agosto"   , "Setembro",
  "Outubro", "Novembro" , "Dezembro",
  NULL
};

void vGetCurrentDate(PSTRUCT_DATE *ppstDate)
{
  time_t tSeconds = time(NULL);
  struct tm *pstCurrentDateTime = localtime(&tSeconds);

  (*ppstDate)->iDay = pstCurrentDateTime->tm_mday;
  (*ppstDate)->iMonth = pstCurrentDateTime->tm_mon + 1;
  (*ppstDate)->iYear = pstCurrentDateTime->tm_year + 1900;
}

void vGetCurrentTime(PSTRUCT_TIME *ppstTime)
{
  time_t tSeconds = time(NULL);
  struct tm *pstCurrentDateTime = localtime(&tSeconds);

  (*ppstTime)->iHour = pstCurrentDateTime->tm_hour;
  (*ppstTime)->iMinute = pstCurrentDateTime->tm_min;
  (*ppstTime)->iSecond = pstCurrentDateTime->tm_sec;
}

void vGetCurrentDateTime(PSTRUCT_DATE *ppstDate, PSTRUCT_TIME *ppstTime)
{
  /**
   * Saving date informations
   */
  vGetCurrentDate(ppstDate);

  /**
   * Saving time informations
   */
  vGetCurrentTime(ppstTime);
}

bool bYearIsLeapYear(int iYear)
{
  if(iYear % 4 == 0)
  {
    if(iYear % 400 == 0 && iYear % 100 != 0)
    {
      return true;
    }
  }

  return false;
}

bool bDateIsValid(STRUCT_DATE *pstDate)
{
  /**
   * Validate the day
   */
  if(pstDate->iDay < 1 || pstDate->iDay > 31)
  {
    return false;
  }
  
  /**
   * Validate the month
   */
  if(pstDate->iMonth < 1 || pstDate->iMonth > 12)
  {
    return false;
  }
  
  /**
   * Validate the year
   */
  if(pstDate->iYear < 1)
  {
    return false;
  }
  
  /**
   * Validate the month of February if the year is
   * a leap year.
   */
  if(bYearIsLeapYear(pstDate->iYear))
  {
    if(pstDate->iMonth == 2 && pstDate->iDay <= 29)
    {
      return true;
    }
  }
  
  /**
   * Validate the month of February in a normal year.
   */
  if(pstDate->iMonth == 2 && pstDate->iDay > 28)
  {
    return false;
  }
  
  /**
   * Validate the months with 31 days
   */
  if(pstDate->iMonth == 1 || pstDate->iMonth == 3 || 
      pstDate->iMonth == 5 || pstDate->iMonth == 7 ||
      pstDate->iMonth == 9 || pstDate->iMonth == 10 ||
      pstDate->iMonth == 12)
  {
    if(pstDate->iDay <= 31)
    {
      return true;
    }
  }
  
  /**
   * Validate the months with 30 days
   */
  if(pstDate->iMonth == 4 || pstDate->iMonth == 6 ||
      pstDate->iMonth == 9 || pstDate->iMonth == 11)
  {
    if(pstDate->iDay <= 30)
    {
      return true;
    }
  }
  
  return false;
}

bool bDatesIsEqual(STRUCT_DATE *pstDateOne, STRUCT_DATE *pstDateTwo)
{
  if(pstDateOne->iDay == pstDateTwo->iDay &&
      pstDateOne->iMonth == pstDateTwo->iMonth &&
      pstDateOne->iYear == pstDateTwo->iYear)
  {
    return true;
  }

  return false;
}

ENUM_DATE_FMT eMatchDateOutputFormat(const char *kpszFmt)
{
  if ( bStrIsEmpty(kpszFmt) )
    return atoi(gkpszDateFormat[FMTERROR]);

  if ( !strcasecmp(kpszFmt, gkpszDateFormat[DDMMAA]) )
    return DDMMAA;
  else if ( !strcasecmp(kpszFmt, gkpszDateFormat[DDMMAAAA]) )
    return DDMMAAAA;
  else if ( !strcasecmp(kpszFmt, gkpszDateFormat[AAAAMMDD]) )
    return AAAAMMDD;
  else if ( !strcasecmp(kpszFmt, gkpszDateFormat[AAMMDD]  ) )
    return AAMMDD;
  else if ( !strcasecmp(kpszFmt, gkpszDateFormat[MMDDAAAA]) )
    return MMDDAAAA;
  else if ( !strcasecmp(kpszFmt, gkpszDateFormat[MMDDAA]  ) )
    return MMDDAA;
  
  return atoi(gkpszDateFormat[FMTERROR]);
}

void vFormatDate(const STRUCT_DATE *kpstDate,
                 const char *kpszFmt,
                 char *szOutput,
                 char *pchDlm)
{
  ENUM_DATE_FMT eDateFmt;

  if( szOutput == NULL || bStrIsEmpty(pchDlm) ) 
  {
    return;
  }

  switch ((eDateFmt = eMatchDateOutputFormat(kpszFmt)))
  {
    case DDMMAAAA:
    case DDMMAA:
      sprintf(szOutput,
          "%02d%c%02d%c%0*d",
          kpstDate->iDay,
          *pchDlm,
          kpstDate->iMonth,
          *pchDlm,
          eDateFmt == DDMMAA ? 2 : 4,
          eDateFmt == DDMMAA ? kpstDate->iYear%100 : kpstDate->iYear
      );
      break;    
    case AAAAMMDD:
    case AAMMDD:
     sprintf(szOutput, 
        "%0*d%c%02d%c%02d",
        eDateFmt == AAMMDD ? 2 : 4 ,
        eDateFmt == AAMMDD ? kpstDate->iYear%100 : kpstDate->iYear,
        *pchDlm,
        kpstDate->iMonth,
        *pchDlm,
        kpstDate->iDay
      );
      break;
    case MMDDAAAA:
    case MMDDAA:
     sprintf(szOutput, 
        "%02d%c%02d%c%0*d",
        kpstDate->iMonth,
        *pchDlm,
        kpstDate->iDay,
        *pchDlm,
        eDateFmt == MMDDAA ? 2 : 4,
        eDateFmt == MMDDAA ? kpstDate->iYear%100 : kpstDate->iYear
      );
      break;
    case FMTERROR:
    default:
      szOutput = NULL;
      return;
  }
}

void vPrintDate(PSTRUCT_DATE pstDate, const char *kpszFmt)
{
  char szOutput[256];

  memset(szOutput, 0, sizeof(szOutput));

  vFormatDate(pstDate, kpszFmt, szOutput, "/");

  puts(szOutput);
}

bool bTimeIsValid(STRUCT_TIME *pstTime)
{
  if(pstTime->iHour < 0 || pstTime->iHour > 23)
  {
    return false;
  }

  if(pstTime->iMinute < 0 || pstTime->iMinute > 59)
  {
    return false;
  }

  if(pstTime->iSecond < 0 || pstTime->iSecond > 59)
  {
    return false;
  }

  return true;
}

bool bTimeIsEqual(STRUCT_TIME *pstTimeOne, STRUCT_TIME *pstTimeTwo)
{
  if(pstTimeOne->iHour == pstTimeTwo->iHour && 
      pstTimeOne->iMinute == pstTimeTwo->iMinute &&
      pstTimeOne->iSecond == pstTimeTwo->iSecond)
  {
    return true;  
  }

  return false;
}

void vFormatTime(const STRUCT_TIME *kpstTime,
                 const char *kpszFmt,
                 char *szOutput)
{
  if(!strcmp(kpszFmt, "hh:mm"))
  {
    sprintf(szOutput, "%02dh:%02dmin", kpstTime->iHour,
                                       kpstTime->iMinute);
    return;
  }

  if(!strcmp(kpszFmt, "hh:mm:ss"))
  {
    sprintf(szOutput, "%02dh:%02dmin:%02d", kpstTime->iHour,
                                            kpstTime->iMinute,
                                            kpstTime->iSecond);
    return;
  }

  szOutput = NULL;
}

void vPrintTime(PSTRUCT_TIME pstTime, const char *kpszFmt)
{
  char szOutput[256];

  memset(szOutput, 0, sizeof(szOutput));

  vFormatTime(pstTime, kpszFmt, szOutput);
  
  puts(szOutput);
}

void vPrintDateTime(PSTRUCT_DATE pstDate,
                    const char *kpszDateFmt,
                    PSTRUCT_TIME pstTime,
                    const char *kpszTimeFmt)
{
  char szDateOutput[256];
  char szTimeOutput[256];

  memset(szDateOutput, 0, sizeof(szDateOutput));
  memset(szTimeOutput, 0, sizeof(szTimeOutput));

  vFormatDate(pstDate, kpszDateFmt, szDateOutput, "/");
  vFormatTime(pstTime, kpszTimeFmt, szTimeOutput);

  printf("%s %s\n", szDateOutput, szTimeOutput);
}

