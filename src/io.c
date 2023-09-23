/**
 * io.c
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * Description: 
 *
 * Date: 20/09/2023
 */

#include <stdio.h>
#include "cutils/cutils.h"
#include "cutils/string.h"
#include "cutils/io.h"

void vFgets(char *szString, int iLength, FILE *fpStream)
{
  fgets(szString, iLength, fpStream);
  setbuf(fpStream, NULL);

  vRemoveNewLines(szString);
}





