/**
 * consts.h
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * consts and macros header file
 *
 * Date: 20/09/2023
 */

#ifndef _CUTILS_CONSTANTS_H_
#define _CUTILS_CONSTANTS_H_

#ifndef _MAX_PATH
  #define _MAX_PATH 256
#endif /* _MAX_PATH */

#ifndef UNUSED
  #define UNUSED(X) (void) X
#endif /* UNUSED */

#ifndef TRUE
  #define TRUE 1
#endif /* TRUE */

#ifndef FALSE
  #define FALSE 0
#endif /* FALSE */

#ifndef SUM
  #define SUM(A, B) A + B
#endif /* SUM */

#ifndef SUB
  #define SUB(A, B) A - B
#endif /* SUB */

#ifndef MULT
  #define MULT(A, B) A * B
#endif /* MULT */

#ifndef DIV
  #define DIV(A, B) A / B
#endif /* DIV */

#ifndef MAX
  #define MAX(A, B) ((A > B) ? (A) : (B))
#endif /* MAX */

#ifndef MIN
  #define MIN(A, B) ((A < B) ? (A) : (B))
#endif /* MIN */

#endif /* _CUTILS_CONSTANTS_H_ */

