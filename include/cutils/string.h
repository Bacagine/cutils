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
   * 
   */
  void szStrUpper(char *szDest, char *pszStrLower);

  /**
   * 
   */
  void szStrLower(char *szDest, char *pszStrUpper);

  /**
   * Check if your terminal have support a colored text
   */
  bool bTerminalSupportColors(void);

  /**
   * Remove the '\n' character of a string
   */
  void vRemoveEnter(char *pszStr);
  void vRemoveNewLines(char *pszStr);

#endif /* _CUTILS_STRING_H_ */

