/**
 * dir.h
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * Description: 
 *
 * Date: 20/09/2023
 */

#ifndef _CUTILS_DIR_H_
  #define _CUTILS_DIR_H_

  #include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h>
  #include <sys/types.h>
  #include <sys/stat.h>
  #include <dirent.h>
  #include <unistd.h>
  #include "cutils.h"

  /**
   * Check if a path is a directory
   */
  bool bPathIsDir(const char *kpszPath);

  /**
   * Open a directory
   * 
   * Return:
   *  true  - Can open directory
   *  false - Can't open the directory
   */
  bool bOpenDir(DIR **ppDir, const char *kpszDirName);

  /**
   * TODO:
   */
  //void vListDir(DIR *pDir);

  /**
   * TODO:
   */
  //void vTreeDir(DIR *pDir);

  /**
   * Close a directory and set NULL 
   * in your pointer.
   */
  bool bCloseDir(DIR **ppDir);

  /**
   * Make a directory
   * 
   * Return:
   *  -1 - Direcotory already exists
   *   0 - Directory created
   *   1 - Directory not created
   */
  int iMkDir(const char *kpszDirName,
            const int iUmask);

  /**
   * Remove a directory
   *
   * Return:
   *  true  - Directory was removed
   *  false - Directory wasn't removed
   */
  bool bRmDir(const char *kpszDirName);

#endif /* _CUTILS_DIR_H_ */

