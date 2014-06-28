/*
 * =====================================================================================
 *
 *       Filename:  string.h
 *
 *    Description:  This header file will define a string
 *
 *        Version:  1.0
 *        Created:  2014年06月29日 04时44分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */

#ifndef _STRING_H
#define _STRING_H
#define STR_MAX_SIZE 256
typedef char String[STR_MAX_SIZE];/*  String[0] is used to store the size */

void Init_String(char * msg);
int Index_Kmp(String string1 , String string2);
void Print_String(String string);



#endif
