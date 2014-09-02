/*
 * =====================================================================================
 *
 *       Filename:  test.c                                                                      
 *                                                      
 *    Description:  测试文件                            
 *                                                      
 *        Version:  1.0                                 
 *        Created:  2014年09月02日 17时14分04秒                       
 *       Revision:  none                                
 *       Compiler:  gcc                                 
 *                                                          
 *         Author:  qeesung (), 1245712564@qq.com     
 *   Organization:  Stay hangry , Stay foolish                      
 *                                                              
 * =====================================================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "search.h"

int main(int argc, char *argv[])
{
    int number;
    int result;
    ST my_st;
    my_st = Init_ST();
    Create_ST(my_st , "info_file");
    Traverse_ST(my_st);
    printf("\n");
    printf("Enter the number :");
    scanf("%d",&number);
    if((result = Search_ST(my_st , number))==-1)
        printf("can not find the  number\n");
    else
        printf("find the number index : %d\n" , result);
    Destory_ST(my_st);
    exit(0);

}




/*
 * =====================================================================================
                                       _ooOoo_
                                      o8888888o
                                      88" . "88
                                      (| -_- |)
                                      O\  =  /O
                                   ____/`---'\____
                                 .'  \\|     |//  `.
                                /  \\|||  :  |||//  \
                               /  _||||| -:- |||||-  \
                               |   | \\\  -  /// |   |
                               | \_|  ''\---/''  |   |
                               \  .-\__  `-`  ___/-. /
                             ___`. .'  /--.--\  `. . __
                          ."" '<  `.___\_<|>_/___.'  >'"".
                         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
                         \  \ `-.   \_ __\ /__ _/   .-` /  /
                    ======`-.____`-.___\_____/___.-`____.-'======
                                       `=---='
                    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                             佛祖保佑       永无BUG
 * =====================================================================================
 */

