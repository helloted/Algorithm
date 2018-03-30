/*  把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，
 * 输出旋转数组的最小数组。例如数组{3,4,5,1,2}是数组{1,2,3,4,5}的旋转数组，该数组的最小值为1。 */

#include <stdio.h>
#include<string.h>

int find_min(int arr[],int len)
{
    if(arr == 0 || len <= 0){
        return 0;
    }
    int begin = 0;
    int end = len - 1;
    int middle;
    while(arr[begin] >= arr[end]){
        if((end - begin) == 1){
            middle = end;
            break;
        }
        middle = (begin + end)/2;
        if(arr[middle] >= arr[begin]){
            begin = middle;
        }else if(arr[middle] <= arr[end]){
            end = middle;
        }
    }
    return arr[middle];
}


int main() {
    int arr[9] = {7,8,9,1,2,3,4,5,6};
    int a =  find_min(arr,9);
    printf("%d",a);
    return 0;
}