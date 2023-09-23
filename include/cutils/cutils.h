/**
 * cutils.h
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * cutils header file
 *
 * Date: 19/09/2023
 */

#ifndef _CUTILS_H_
  #define _CUTILS_H_

  /******************************************************************************
   *                                                                            *
   *                                 Includes                                   *
   *                                                                            *
   ******************************************************************************/
  #include <stdlib.h>
  #include <ctype.h>
  #include <string.h>
  #include <stdbool.h>
  #include <stdarg.h>
  #include <errno.h>
  #ifndef _WIN32
    #include <time.h>
    #include <sys/utsname.h>
    #include <pwd.h>
  #else
    #include <sys/timeb.h>
  #endif
  #include <unistd.h>

  /******************************************************************************
   *                                                                            *
   *                             Defines and macros                             *
   *                                                                            *
   ******************************************************************************/

  /**
   * Program information defines
   */
  #define VERSION        "1.0"
  #define DESCRIPTION    "This software is a C Utils Library"
  #define COPYRIGHT      "Copyright (C) 2023"
  #define DEV_NAME       "Gustavo Bacagine"
  #define DEV_MAIL       "gustavo.bacagine@protonmail.com"
  #define GITHUB_URL     "https://www.github.com/Gustavo Bacagine/cutils"

  /**
   * This macro is used to remove
   * unused warnings during the
   * compilation.
   */
  #define UNUSED(X) (void) X

  /******************************************************************************
   *                                                                            *
   *                  Typedefs, structures, unions and enums                    *
   *                                                                            *
   ******************************************************************************/

  typedef unsigned char byte_t;

  /******************************************************************************
   *                                                                            *
   *                     Global variables and constants                         *
   *                                                                            *
   ******************************************************************************/

  /******************************************************************************
   *                                                                            *
   *                            Prototype functions                             *
   *                                                                            *
   ******************************************************************************/

  /**
   * Check if your terminal have support a colored text
   */
  bool bTerminalSupportColors(void);

  /**
   * Check if the current user is root.
   */
  bool bUserIsRoot(void);

#endif /* _CUTILS_H_ */

