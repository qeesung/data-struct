/*
 * =====================================================================================
 *
 *       Filename:  recall_test.c
 *
 *    Description:  回溯的测试文件
 *
 *        Version:  1.0
 *        Created:  2014年08月01日 20时07分04秒
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
#include    "recall.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
    int i=0;
    int my_point[POINT_ARRAY_SIZE];
    for(i=0;i<7;i++)
    {
        my_point[i]=-1;
    }
    List my_list ;
    my_list = Init_List();
    Init_Distance_List(my_list);
    Turnpike(my_point , my_list , 6);
    for(i=0;i<7;i++)
    {
        printf("%d\t",my_point[i]);
    }
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
