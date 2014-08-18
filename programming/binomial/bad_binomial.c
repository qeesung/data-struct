/*
 * =====================================================================================
 *
 *       Filename:  bad_binomial.c
 *
 *    Description:  用递归来实现
 *
 *        Version:  1.0
 *        Created:  2014年08月18日 10时49分38秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  Stay hangry , Stay foolish
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>

int bad_binomial(int k , int n)
{
    if(n<k)
        exit(-1);
    if(n==k)
        return 1;
    if(k==0)
        return 1;
    if(n==0)
        return 1;
    return bad_binomial(k-1,n-1)+bad_binomial(k, n-1);
}


int main()
{
    int k ,n;
    printf("Enter k & n:");
    scanf("%d %d",&k , &n);
    printf("C(%d,%d)=%d\n",n,k,bad_binomial(k , n));
    exit(0);
}
