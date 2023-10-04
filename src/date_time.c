/**
 * date.c
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * Description: 
 *
 * Date: 21/09/2023
 */

#include <stdlib.h>
#include "cutils/date_time.h"
#include "cutils/str.h"

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
    return atoi(kpszDateFormat[FMTERROR]);

  if ( !strcasecmp(kpszFmt, kpszDateFormat[DDMMAA]) )
    return DDMMAA;
  else if ( !strcasecmp(kpszFmt, kpszDateFormat[DDMMAAAA]) )
    return DDMMAAAA;
  else if ( !strcasecmp(kpszFmt, kpszDateFormat[AAAAMMDD]) )
    return AAAAMMDD;
  else if ( !strcasecmp(kpszFmt, kpszDateFormat[AAMMDD]  ) )
    return AAMMDD;
  else if ( !strcasecmp(kpszFmt, kpszDateFormat[MMDDAAAA]) )
    return MMDDAAAA;
  else if ( !strcasecmp(kpszFmt, kpszDateFormat[MMDDAA]  ) )
    return MMDDAA;
  
  return atoi(kpszDateFormat[FMTERROR]);
}

void vFormatDate(const STRUCT_DATE *kpstDate,
                 const char *kpszFmt,
                 char **szOutput,
                 char *pchDlm)
{
  ENUM_DATE_FMT eDateFmt;

  if( *szOutput == NULL || bStrIsEmpty(pchDlm) ) 
  {
    return;
  }

  switch ((eDateFmt = eMatchDateOutputFormat(kpszFmt)))
  {
    case DDMMAAAA:
    case DDMMAA:
      sprintf(*szOutput,
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
     sprintf(*szOutput, 
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
     sprintf(*szOutput, 
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
      *szOutput = NULL;
      return;
  }
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
                 char **szOutput)
{
  if(!strcmp(kpszFmt, "hh:mm"))
  {
    sprintf(*szOutput, "%02dh:%02dmin", kpstTime->iHour,
                                        kpstTime->iMinute);
  }

  if(!strcmp(kpszFmt, "hh:mm:ss"))
  {
    sprintf(*szOutput, "%02dh:%02dmin:%02d", kpstTime->iHour,
                                             kpstTime->iMinute,
                                             kpstTime->iSecond);
  }

  *szOutput = NULL;
}
