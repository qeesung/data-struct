/*
 * =====================================================================================
 *
 *       Filename:  test.c                                                                      
 *                                                      
 *    Description:  测试孙需查找的函数                            
 *                                                      
 *        Version:  1.0                                 
 *        Created:  2014年09月02日 13时21分01秒                       
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
#include "search.h"


int main(int argc, char *argv[])
{
    ST my_st;
    my_st = Init_ST();
    Create(my_st , "info_file");
    Traverse(my_st);
    printf("Find the 14 index is %d\n",Search(my_st , 56));
    Destory(my_st);
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

