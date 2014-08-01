/*
 * =====================================================================================
 *
 *       Filename:  list_test.c
 *
 *    Description:  测验链表函数是否可执行
 *
 *        Version:  1.0
 *        Created:  2014年08月01日 16时23分28秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */



#include	<stdlib.h>
#include    <stdio.h>
#include    "list.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
    List my_list ;
    my_list = Init_List();
    Insert_List(my_list , 6);
    Insert_List(my_list , 3);
    Insert_List(my_list , 10);
    Insert_List(my_list , 2);
    Insert_List(my_list , 5);
    Insert_List(my_list , 9);
    Insert_List(my_list , 3);
    Insert_List(my_list , 3);
    Insert_List(my_list , 7);
    Print_List(my_list);
/*    Delete_List(my_list , 2);
    Delete_List(my_list , 10);
    Delete_List(my_list , 5);
    Delete_List(my_list , 100);
    Print_List(my_list); */
    printf("in the list the number of 3 is:%d\n",Check_Ele(my_list , 3));
    printf("in the list the number of 10 is:%d\n",Check_Ele(my_list , 10));
    printf("in the list the number of 100 is:%d\n",Check_Ele(my_list , 100));
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

