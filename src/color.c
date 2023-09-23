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

void vMakeColoredText(char *pszColoredStr,
                      const char *kpszStr,
                      const bool bBold,
                      const TextColors eTextColors)
{
  if(bBold)
  {
    sprintf(pszColoredStr, "%s%s%s", kszBoldColors[eTextColors], kpszStr, END_COLOR_STR);
  }
  else
  {
    sprintf(pszColoredStr, "%s%s%s", kszNormalColors[eTextColors], kpszStr, END_COLOR_STR);
  }
}

bool bPrintColored(const TextColors eTextColors,
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
  
  vMakeColoredText(szColoredStr, kpszFmt, bBold, eTextColors);
  
  vfprintf(stdout, szColoredStr, args);

  va_end(args);

  return true;
}

