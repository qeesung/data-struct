/*
 * =====================================================================================
 *
 *       Filename:  string.h
 *
 *    Description:  Hedaer file about the string array
 *
 *        Version:  1.0
 *        Created:  2014年06月25日 23时22分14秒
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

#define MAXSTRLEN 255/*  the array max array length */
typedef char String[MAXSTRLEN+1];

int Concat(String merge_string,String string1 , String string2);
int Str_Length(String string);
void Print_String(String string);
void Input_String(String string);
#endif
