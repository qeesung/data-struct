/*
 * =====================================================================================
 *
 *       Filename:  recall.h
 *
 *    Description:  回溯算法的头文件
 *
 *        Version:  1.0
 *        Created:  2014年08月01日 15时47分06秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */

#ifndef _RECALL_H
#define _RECALL_H
#define POINT_ARRAY_SIZE
#include    "list.h"
void Init_Distance_List(List distance_list);
void Delete(List distance_list, int data);
void Insert(List distance_list, int data);

#endif
