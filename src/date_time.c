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

ENUM_DATE_FMT eMatchDateOutputFormat(const char *kpszFmt) {
  if ( bStrIsEmpty(kpszFmt) )
    return atoi(gkpszDateFormat[DATE_FMTERROR]);
  if ( !strcasecmp(kpszFmt, gkpszDateFormat[DDMMYY]) )
    return DDMMYY;
  else if ( !strcasecmp(kpszFmt, gkpszDateFormat[DDMMYYYY]) )
    return DDMMYYYY;
  else if ( !strcasecmp(kpszFmt, gkpszDateFormat[YYYYMMDD]) )
    return YYYYMMDD;
  else if ( !strcasecmp(kpszFmt, gkpszDateFormat[YYMMDD]  ) )
    return YYMMDD;
  else if ( !strcasecmp(kpszFmt, gkpszDateFormat[MMDDYYYY]) )
    return MMDDYYYY;
  else if ( !strcasecmp(kpszFmt, gkpszDateFormat[MMDDYY]  ) )
    return MMDDYY;
  return atoi(gkpszDateFormat[DATE_FMTERROR]);
}

void vFormatDate(
  const STRUCT_DATE *kpstDate,
  ENUM_DATE_FMT eDateFmt,
  const char *kpszSeparator,
  char *pszOutput,
  size_t lOutputSize) {
  if ( pszOutput == NULL || bStrIsEmpty(kpszSeparator) )
    return;
  switch ( eDateFmt ) {
    case DDMMYYYY:
    case DDMMYY: {
      snprintf(
        pszOutput,
        lOutputSize,
        "%02d%c%02d%c%0*d",
        kpstDate->iDay,
        *kpszSeparator,
        kpstDate->iMonth,
        *kpszSeparator,
        eDateFmt == DDMMYY ? 2 : 4,
        eDateFmt == DDMMYY ? kpstDate->iYear%100 : kpstDate->iYear
      );
      break;
    }
    case YYYYMMDD:
    case YYMMDD: {
      snprintf(
        pszOutput,
        lOutputSize,
        "%0*d%c%02d%c%02d",
        eDateFmt == YYMMDD ? 2 : 4 ,
        eDateFmt == YYMMDD ? kpstDate->iYear%100 : kpstDate->iYear,
	*kpszSeparator,
        kpstDate->iMonth,
        *kpszSeparator,
        kpstDate->iDay
      );
      break;
    }
    case MMDDYYYY:
    case MMDDYY: {
      snprintf(
        pszOutput,
        lOutputSize,
        "%02d%c%02d%c%0*d",
        kpstDate->iMonth,
        *kpszSeparator,
        kpstDate->iDay,
        *kpszSeparator,
        eDateFmt == MMDDYY ? 2 : 4,
        eDateFmt == MMDDYY ? kpstDate->iYear%100 : kpstDate->iYear
      );
      break;
    }
    case DATE_FMTERROR:
    default: {
      pszOutput = NULL;
      return;
    }
  }
}

void vPrintDate(PSTRUCT_DATE pstDate, ENUM_DATE_FMT eDateFmt, const char *kpszSeparator) {
  char szOutput[256] = "";
  memset(szOutput, 0x00, sizeof(szOutput));
  vFormatDate(pstDate, eDateFmt, kpszSeparator, szOutput, sizeof(szOutput));
  puts(szOutput);
}
void vGetDateFromStr(PSTRUCT_DATE pstDate, const char *kpszDate, char *pszSeparator, ENUM_DATE_FMT eDateFmt) {
  char szTemp[5] = "";
  
  memset(szTemp, 0x00, sizeof(szTemp));
  
  if ( !pstDate || !kpszDate )
    return;

  if ( !bStrIsEmpty(pszSeparator) ) {
    switch ( eDateFmt ) {
      case DDMMYYYY:
      case DDMMYY:
      case YYYYMMDD:
      case YYMMDD:
      case MMDDYYYY:
      case MMDDYY: {
        int iDiaPos = 0;
        int iMesPos = 0;
        int iAnoPos = 0;
        if ( eDateFmt == DDMMYYYY || eDateFmt == DDMMYY ){
          iDiaPos = 0;
          iMesPos = 3;
          iAnoPos = 6;
        }
        else if ( eDateFmt == YYYYMMDD || eDateFmt == YYMMDD ) {
          iDiaPos = 6;
          iMesPos = 4;
          iAnoPos = 0;
        }
        else {
          iDiaPos = 3;
          iMesPos = 0;
          iAnoPos = 6;
        }
        szTemp[0] = kpszDate[iDiaPos];
        szTemp[1] = kpszDate[iDiaPos + 1];
        szTemp[2] = '\0';
	pstDate->iDay = atoi(szTemp);
        szTemp[0] = kpszDate[iMesPos];
        szTemp[1] = kpszDate[iMesPos + 1];
        szTemp[2] = '\0';
        pstDate->iMonth = atoi(szTemp);
        if ( eDateFmt == DDMMYYYY || eDateFmt == YYYYMMDD || eDateFmt == MMDDYYYY ) {
          int ii = 0;
          for ( ii = 0; ii < 4; ii++ )
            szTemp[ii] = kpszDate[iAnoPos + ii];
          szTemp[4] = '\0';
        }
        else {
          szTemp[0] = kpszDate[iAnoPos];
          szTemp[1] = kpszDate[iAnoPos + 1];
          szTemp[2] = '\0';
        }
        pstDate->iYear = atoi(szTemp);
        break;
      }
      case DATE_FMTERROR:
      default:
        return;
    }
  }
  else {
    switch ( eDateFmt ) {
      case DDMMYYYY: {
        int ii = 0;
        szTemp[0] = kpszDate[0];
        szTemp[1] = kpszDate[1];
        szTemp[2] = '\0';
        pstDate->iDay = atoi(szTemp);
        szTemp[0] = kpszDate[2];
        szTemp[1] = kpszDate[3];
	szTemp[2] = '\0';
        pstDate->iMonth = atoi(szTemp);
        for ( ii = 0; ii < 4; ii++ )
          szTemp[ii] = kpszDate[4 + ii];
        szTemp[4] = '\0';
        pstDate->iYear = atoi(szTemp);
        break;
      }
      case DDMMYY: {
        szTemp[0] = kpszDate[0];
        szTemp[1] = kpszDate[1];
        szTemp[2] = '\0';
        pstDate->iDay = atoi(szTemp);
        szTemp[0] = kpszDate[2];
        szTemp[1] = kpszDate[3];
        szTemp[2] = '\0';
        pstDate->iMonth = atoi(szTemp);
        szTemp[0] = kpszDate[4];
        szTemp[1] = kpszDate[5];
        szTemp[2] = '\0';
        pstDate->iYear = atoi(szTemp);
        break;
      }
      case YYYYMMDD: {
        int ii = 0;
        for ( ii = 0; ii < 4; ii++ )
          szTemp[ii] = kpszDate[ii];
        szTemp[4] = '\0';
        pstDate->iYear = atoi(szTemp);
        szTemp[0] = kpszDate[4];
        szTemp[1] = kpszDate[5];
        szTemp[2] = '\0';
        pstDate->iMonth = atoi(szTemp);
	szTemp[0] = kpszDate[6];
        szTemp[1] = kpszDate[7];
        szTemp[2] = '\0';
        pstDate->iDay = atoi(szTemp);
        break;
      }
      case YYMMDD: {
        szTemp[0] = kpszDate[0];
        szTemp[1] = kpszDate[1];
        szTemp[2] = '\0';
        pstDate->iYear = atoi(szTemp);
        szTemp[0] = kpszDate[2];
        szTemp[1] = kpszDate[3];
        szTemp[2] = '\0';
        pstDate->iMonth = atoi(szTemp);
        szTemp[0] = kpszDate[4];
        szTemp[1] = kpszDate[5];
        szTemp[2] = '\0';
        pstDate->iDay = atoi(szTemp);
        break;
      }
      case MMDDYYYY: {
        int ii = 0;
        szTemp[0] = kpszDate[0];
        szTemp[1] = kpszDate[1];
        szTemp[2] = '\0';
        pstDate->iMonth = atoi(szTemp);
        szTemp[0] = kpszDate[2];
        szTemp[1] = kpszDate[3];
        szTemp[2] = '\0';
        pstDate->iDay = atoi(szTemp);
        for ( ii = 0; ii < 4; ii++ )
          szTemp[ii] = kpszDate[4 + ii];
        szTemp[4] = '\0';pstDate->iYear = atoi(szTemp);
        break;
      }
      case MMDDYY: {
        szTemp[0] = kpszDate[0];
        szTemp[1] = kpszDate[1];
        szTemp[2] = '\0';
        pstDate->iMonth = atoi(szTemp);
        szTemp[0] = kpszDate[2];
        szTemp[1] = kpszDate[3];
        szTemp[2] = '\0';
        pstDate->iDay = atoi(szTemp);
        szTemp[0] = kpszDate[4];
        szTemp[1] = kpszDate[5];
        szTemp[2] = '\0';
        pstDate->iYear = atoi(szTemp);
        break;
      }
      case DATE_FMTERROR:
      default:
        return;
    }
  }
}

void vFormatTime(
  const PSTRUCT_TIME kpszTime,
  const ENUM_TIME_FMT eTimeFmt,
  char *pszOutput,
  size_t lOutputSize) {
  switch ( eTimeFmt ) {
    case HHMM: {
      snprintf(pszOutput, lOutputSize, "%02d:%02d", kpszTime->iHour, kpszTime->iMinute);
      break;
    }
    case HHMMSS: {
      snprintf(pszOutput, lOutputSize, "%02d:%02d:%02d", kpszTime->iHour, kpszTime->iMinute, kpszTime->iSecond);
      break;
    }
    case HHMMSSM: {
      snprintf(pszOutput, lOutputSize, "%02d:%02d:%02d:%3d", kpszTime->iHour, kpszTime->iMinute, kpszTime->iSecond, kpszTime->iMillisecond);
      break;
    }
    case TIME_FMTERROR:
    default:
      return;
  }
}

void vPrintTime(PSTRUCT_TIME pstTime, ENUM_TIME_FMT eTimeFmt) {
  char szOutput[256] = "";
  memset(szOutput, 0x00, sizeof(szOutput));
  vFormatTime(pstTime, eTimeFmt, szOutput, sizeof(szOutput));
  puts(szOutput);
}

void vPrintDateTime(PSTRUCT_DATE pstDate, ENUM_DATE_FMT eDateFmt, const char *kpszDateSeparator, PSTRUCT_TIME pstTime, ENUM_TIME_FMT eTimeFmt) {
  char szDateOutput[256] = "";
  char szTimeOutput[256] = "";
  memset(szDateOutput, 0x00, sizeof(szDateOutput));
  memset(szTimeOutput, 0x00, sizeof(szTimeOutput));
  vFormatDate(pstDate, eDateFmt, kpszDateSeparator, szDateOutput, sizeof(szDateOutput));
  vFormatTime(pstTime, eTimeFmt, szTimeOutput, sizeof(szTimeOutput));
  printf("%s %s\n", szDateOutput, szTimeOutput);
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

