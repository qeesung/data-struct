/*
 * =====================================================================================
 *
 *       Filename:  huffuman_tree.h
 *
 *    Description:  创建一颗huffuman树
 *
 *        Version:  1.0
 *        Created:  2014年07月31日 14时41分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */

#ifndef _HUFFUMAN_TREE_H
#define _HUFFUMAN_TREE_H
struct huff_tree
{
    unsigned int weight;
    unsigned int parent , leftchild , rightchild;
};

typedef struct huff_tree * Huff_tree;
int Get_Min(huff_tree my_tree , int index);//返回在index之前的最小的一个数的序号
void Select(Huff_tree my_tree , int last_index, int * index1 ,int * index2);

#endif
