/*
 * =====================================================================================
 *
 *       Filename:  list.h
 *
 *    Description:  header file for my list
 *
 *        Version:  1.0
 *        Created:  2014年06月30日 03时55分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */

#ifndef _LIST_H
#define _LIST_H

/*-----------------------------------------------------------------------------
 *  for book index number link list
 *-----------------------------------------------------------------------------*/
struct book_index_node {
	int number ;// book number
	struct book_index_node * next;
};				/* ----------  end of struct book_index_node  ---------- */

typedef struct book_index_node * Book_index_node;

/*-----------------------------------------------------------------------------
 *  for string_node link list
 *-----------------------------------------------------------------------------*/

struct string_node {
	char * book_word;
	Book_index_node;
	struct string_node * next;
};				/* ----------  end of struct string_node  ---------- */

typedef struct string_node  * String_node;



#endif
