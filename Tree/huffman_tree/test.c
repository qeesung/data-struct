/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  test huffuman tree functions are right
 *
 *        Version:  1.0
 *        Created:  2014年07月31日 15时46分20秒
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
#include    <string.h>
#include    "huffuman_tree.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
    Huff_tree my_tree;
    Huff_code my_code;
    int * weight_array;
    int k=0;
    weight_array = Random_Weight();
    Create_Hufftree(&my_tree , &my_code , weight_array, 5);
    for(k=0;k<6;k++)
    {
        printf("#%d--->%s\n",k,my_code[k]);
    }
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
