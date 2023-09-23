/**
 * date.c
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * Description: 
 *
 * Date: 21/09/2023
 */

#include "cutils/date.h"

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

bool bDateIsValid(Date *pstDate)
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

bool bDatesIsEqual(Date *pstDateOne, Date *pstDateTwo)
{
  if(pstDateOne->iDay == pstDateTwo->iDay &&
      pstDateOne->iMonth == pstDateTwo->iMonth &&
      pstDateOne->iYear == pstDateTwo->iYear)
  {
    return true;
  }

  return false;
}

void vFormatDate(const Date *kpstDate,
                 const char *kpszFmt,
                 char **szOutput)
{
  if(!strcmp(kpszFmt, "dd/mm/aaaa"))
  {
    sprintf(*szOutput, "%02d/%02d/%04d", kpstDate->iDay,
                                         kpstDate->iMonth,
                                         kpstDate->iYear);
    return;
  }

  if(!strcmp(kpszFmt, "aaaa/mm/dd"))
  {
    sprintf(*szOutput, "%04d/%02d/%02d", kpstDate->iYear,
                                         kpstDate->iMonth,
                                         kpstDate->iDay);
    return;
  }
  
  *szOutput = NULL;
}

