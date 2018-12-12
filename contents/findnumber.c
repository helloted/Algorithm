
/*  输入n,m 打印出一个蛇形矩阵       */

#include <stdio.h>


int find(int row,int col,int arr[row][col],int num){
    int i = 0;
    int j = col -1;
    while (j+1){
        int t = arr[i][j];
        if (t == num)
        {
            return 1;
        }else if (t > num){  //选择下一列
            j--; 
        }else{ // 在这一行往下找
            i++;
        }
    }
    return 0;
}


int main() {
    int arr[4][4] = 
    {
        {1,2,8,9},
        {2,4,9,12},
        {4,7,10,13},
        {6,8,11,15},

    };
    printf("%d\n", find(4,4,arr,6));  
    return 0;
}