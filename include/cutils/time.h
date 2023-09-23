/**
 * time.h
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * Description: 
 *
 * Date: 21/09/2023
 */

#ifndef _CUTILS_TIME_H_
#define _CUTILS_TIME_H_

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct Time
{
  int iHour;
  int iMinute;
  int iSecond;
} Time, *PTime;

/**
 *
 */
bool bTimeIsValid(Time *pstTime);

/**
 *
 */
bool bTimeIsEqual(Time *pstTimeOne, Time *pstTimeTwo);

/**
 *
 */
void vFormatTime(const Time *kpstTime,
                 const char *kpszFmt,
                 char **szOutput);

#endif /* _CUTILS_TIME_H_ */

