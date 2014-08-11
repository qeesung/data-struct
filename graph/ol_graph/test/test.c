/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  fscanf()
 *
 *        Version:  1.0
 *        Created:  2014年08月10日 16时21分19秒
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

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
    char buf[512];
    FILE * myfile ;
    if((myfile = fopen("./testfile", "r"))== NULL)
        return;
    fscanf(myfile , "%s", buf);
    printf("%s***\n", buf);
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
