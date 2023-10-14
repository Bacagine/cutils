/**
 * color.c
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * Description: 
 *
 * Date: 20/09/2023
 */

#include "cutils/color.h"
#include "cutils/str.h"

bool bTerminalSupportColors(void)
{
  char *szTerm = getenv("TERM");
  
  if(bStrIsEmpty(szTerm) || !strcmp(szTerm, "dumb"))
  {
    return false;
  }
  
  return true;
}

void vMakeColoredText(char *pszColoredStr,
                      const char *kpszStr,
                      const bool bBold,
                      const ENUM_TEXT_COLORS eENUM_TEXT_COLORS)
{
  if(bBold)
  {
    sprintf(pszColoredStr, "%s%s%s", kszBoldColors[eENUM_TEXT_COLORS], kpszStr, END_COLOR_STR);
  }
  else
  {
    sprintf(pszColoredStr, "%s%s%s", kszNormalColors[eENUM_TEXT_COLORS], kpszStr, END_COLOR_STR);
  }
}

bool bPrintColored(const ENUM_TEXT_COLORS eENUM_TEXT_COLORS,
                   const bool bBold,
                   const char *kpszFmt, ...)
{
  va_list args;
  char szColoredStr[2048];
  
  memset(szColoredStr, 0, sizeof(szColoredStr));
  
  va_start(args, kpszFmt);

  if(!bTerminalSupportColors())
  {
    vfprintf(stdout, kpszFmt, args);
    return false;
  }  
  
  vMakeColoredText(szColoredStr, kpszFmt, bBold, eENUM_TEXT_COLORS);
  
  vfprintf(stdout, szColoredStr, args);

  va_end(args);

  return true;
}

