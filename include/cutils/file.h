/**
 * file.h
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * Description: 
 *
 * Date: 20/09/2023
 */

#ifndef _CUTILS_FILE_H_
#define _CUTILS_FILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Check if a path is a directory
 */
bool bFileExist(const char *kpszFileName);

/**
 * Open a file
 * 
 * Return:
 *  true  - Can open the file
 *  false - Can't open the file
 */
bool bOpenFile(FILE **fppFile, const char *kpszFileName, const char *pkszMode);

/**
 * Close a file and set NULL 
 * in your pointer.
 */
bool bCloseFile(FILE **ppfFile);

/**
 * Remove a file
 */
bool bRemoveFile(const char *kpszFileName);

/**
 * Return the lenght of file in bytes.
 */
long lGetFileLen(FILE *fpFile, const char *kpszFileName);

#endif /* _CUTILS_FILE_H_ */

