/*
 * =====================================================================================
 *
 *       Filename:  string.h
 *
 *    Description:  dynamic string header file
 *
 *        Version:  1.0
 *        Created:  2014年06月26日 04时33分10秒
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

struct string {
	char * ch;
	int length;
};				/* ----------  end of struct string  ---------- */

typedef struct string  * String;

String Str_Assign(String string);// copy a string
int Str_Length(String string);
int Str_Compare(String string1 , String string2);
void Clear_String(String string);
String Concat(String string1 , String string2);
String Sub_String(String string , int pos , int len);
void Str_Insert(String string , int pos , String new_string);// insert new_string into string  at pos
String Init_String(char * );
void Print_String(String string);


#endif
