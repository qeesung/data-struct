/*
 * =====================================================================================
 *
 *       Filename:  string_list.h
 *
 *    Description:  this is string link list haeder file
 *
 *        Version:  1.0
 *        Created:  2014年06月30日 21时36分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */

#ifndef _STRING_LIST_H
#define _STRING_LIST_H
#include"./index_list/index_list.h"


struct string_node {
	char * book_word;
	Index_list book_index;
	struct string_node * next;
};				/* ----------  end of struct string_node  ---------- */

typedef struct string_node  * String_node;
typedef String_node String_list;
typedef String_list String_position;

String_list Init_String_List();
void Insert_String_List(String_list list,char * word , int index_number );
void Delete_String_List(String_list list , char * word, int index_number );
void Print_String_List(String_list list);
String_position Find_Position(String_list list , char * word);
String_position Find_Insert_Position(String_list list , char * word);
void Write_String_List(char * filename, String_list list);



#endif
