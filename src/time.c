/**
 * time.c
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * Description: 
 *
 * Date: 21/09/2023
 */

#include "cutils/time.h"

bool bTimeIsValid(Time *pstTime)
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

bool bTimeIsEqual(Time *pstTimeOne, Time *pstTimeTwo)
{
  if(pstTimeOne->iHour == pstTimeTwo->iHour && 
      pstTimeOne->iMinute == pstTimeTwo->iMinute &&
      pstTimeOne->iSecond == pstTimeTwo->iSecond)
  {
    return true;  
  }

  return false;
}

void vFormatTime(const Time *kpstTime,
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

