
/*  输入n,m 打印出一个蛇形矩阵       */

#include <stdio.h>

void temp(int n,int m){
    int a[n][m];
        for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            a[i][j] = 0;
        }

    }

    int x,y,temp;
    x = 0;
    y = m-1;

    // 从右上角开始
    temp = a[x][y] = 1;

    while(temp < n * m ){
        // 向下走，一直到m或者下一行已经赋值
        while (x+1<m && !a[x+1][y]){
            a[++x][y]=++temp;
        }

        // 向左走，一直到0列或者前列已经赋值
        while (y-1>= 0 && !a[x][y-1]){
            a[x][--y]=++temp;
        }

        // 向上走，一直走到0行或者上行已经赋值
        while (x-1>=0 && !a[x-1][y]){
            a[--x][y]=++temp;
        }

        // 向右方向，一直走到最右或者右列已经赋值
        while (y+1< m && !a[x][y+1]){
            a[x][++y]=++temp;
        }
    }

    // 打印
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            printf("%4d ",a[i][j]);
        printf("\n\n");
    }
}

int main() {
    temp(3,4);
    return 0;
}