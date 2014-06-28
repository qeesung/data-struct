/*
 * =====================================================================================
 *
 *       Filename:  KMP.h
 *
 *    Description:  KMP header file
 *
 *        Version:  1.0
 *        Created:  2014年06月29日 05时02分36秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */
#ifndef _KMP_H
#define _KMP_H
#include"string.h"
typedef char Next_Array[STR_MAX_SIZE];
void Set_Next(String string , Next_Array next);
#endif
