/**
 * string.h
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * string header file
 *
 * Date: 19/09/2023
 */

#ifndef _CUTILS_STRING_H_
#define _CUTILS_STRING_H_

#include <ctype.h>
#include <string.h>
#include <stdbool.h>

/**
 * Check if a string is empty
 */
bool bStrIsEmpty(const char *kpszStr);

/**
 * Save a upper pszStrLower in szDest
 */
void szStrUpper(char *szDest, char *pszStrLower);

/**
 * Save a lower pszStrUpper in szDest
 */
void szStrLower(char *szDest, char *pszStrUpper);

/**
 * Remove the '\n' character of a string
 */
void vRemoveNewLines(char *pszStr);

#endif /* _CUTILS_STRING_H_ */

