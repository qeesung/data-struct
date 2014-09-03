/*
 * =====================================================================================
 *
 *       Filename:  test.c                                                                      
 *                                                      
 *    Description:  测试文件                            
 *                                                      
 *        Version:  1.0                                 
 *        Created:  2014年09月03日 15时24分42秒                       
 *       Revision:  none                                
 *       Compiler:  gcc                                 
 *                                                          
 *         Author:  qeesung (), 1245712564@qq.com     
 *   Organization:  Stay hangry , Stay foolish                      
 *                                                              
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "bitree.h"
#include "search.h"

int main(int argc, char *argv[])
{
    ST my_st;
    char key;
    int result;
    my_st = Init_ST();
    Create_ST(my_st , "info_file");
    Traverse_ST(my_st);
    printf("Enter the key:");
    scanf("%c", &key);
    result = Search_ST(my_st , key);
    if(result == -1)
        printf("can not find the key!\n");
    else
        printf("find the key index : %d\n", result);
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

