/**
 * color.h
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * Description: 
 *
 * Date: 20/09/2023
 */

#ifndef _CUTILS_COLOR_H
#define _CUTILS_COLOR_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "cutils.h"

/* Used for colored strings */
#define BLACK_STR     "\033[0;30m"
#define RED_STR       "\033[0;31m"
#define GREEN_STR     "\033[0;32m"
#define YELLOW_STR    "\033[0;33m"
#define BLUE_STR      "\033[0;34m"
#define PURPLE_STR    "\033[0;35m"
#define BLUE_CYAN_STR "\033[0;36m"
#define WHITE_STR     "\033[0;37m"

#define BLACK_BOLD_STR     "\033[1;30m"
#define RED_BOLD_STR       "\033[1;31m"
#define GREEN_BOLD_STR     "\033[1;32m"
#define YELLOW_BOLD_STR    "\033[1;33m"
#define BLUE_BOLD_STR      "\033[1;34m"
#define PURPLE_BOLD_STR    "\033[1;35m"
#define BLUE_CYAN_BOLD_STR "\033[1;36m"
#define WHITE_BOLD_STR     "\033[1;37m"

#define END_COLOR_STR "\033[m"

static const char *kszNormalColors[] = {
  BLACK_STR, RED_STR, GREEN_STR,
  YELLOW_STR, BLUE_STR, PURPLE_STR,
  BLUE_CYAN_STR, WHITE_STR, NULL
};

static const char *kszBoldColors[] = {
  BLACK_BOLD_STR, RED_BOLD_STR, GREEN_BOLD_STR, 
  YELLOW_BOLD_STR, BLUE_BOLD_STR, PURPLE_BOLD_STR, 
  BLUE_CYAN_BOLD_STR, WHITE_BOLD_STR, NULL
};

typedef enum TextColors
{
  BLACK,
  RED,
  GREEN,
  YELLOW,
  BLUE,
  PURPLE,
  CYAN_BLUE,
  WHITE
} TextColors;

/**
 * Check if your terminal have support a colored text
 */
bool bTerminalSupportColors(void);

/**
 * Create a colored text
 */
void vMakeColoredText(char *pszColoredStr,
                      const char *kpszStr,
                      const bool bBold,
                      const TextColors eTextColors);

/**
 * Print a colored text in terminal
 *
 * If your terminal don't have support a colored text,
 * the message is print without colors
 *
 * Return:
 *  true  - Can print colored text.
 *  false - Can't print colored text.
 */
bool bPrintColored(const TextColors eTextColors,
                   const bool bBold,
                   const char *kpszFmt, ...);


#endif /* _CUTILS_COLOR_H_ */

