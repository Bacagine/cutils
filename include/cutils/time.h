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

typedef struct STRUCT_TIME
{
  int iHour;
  int iMinute;
  int iSecond;
} STRUCT_TIME, *PSTRUCT_TIME;

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

#endif /* _CUTILS_TIME_H_ */

