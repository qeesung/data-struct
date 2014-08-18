/*
 * =====================================================================================
 *
 *       Filename:  binomial.c
 *
 *    Description:  动态规划里面的二项试系数
 *
 *        Version:  1.0
 *        Created:  2014年08月18日 10时32分16秒
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
void binomial(int number)
{
    int k1;
    int k2;
    int matrix[number][number];
    /* 初始化矩阵 */
    for(k1=0;k1<number;k1++)
    {
        for(k2=0;k2<number;k2++)
        {
            matrix[k1][k2]=0;
            if(k1 == k2)
                matrix[k1][k2]=1;
            if(k2 ==0)
                matrix[k1][k2]=1;
        }
    }
    for(k1=1;k1<number;k1++)
    {
        for(k2=1;k2<k1;k2++)
        {
           matrix[k1][k2] = matrix[k1-1][k2-1]+matrix[k1-1][k2]; 
        }
    }
    printf("\n");
    for(k1=0;k1<number;k1++)
    {
        for(k2=0;k2<number;k2++)
        {
            if(matrix[k1][k2]==0)
                break;
            printf("%d\t",matrix[k1][k2]);
        }
        printf("\n");
    }
}

int main()
{
    int number;
    printf("Enter the number:");
    scanf("%d",&number);
    binomial(number);
}
