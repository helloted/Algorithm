
/* 在长度为n的数组中，所有的元素都是0到n-1的范围内。 数组中的某些数字是重复的，
但不知道有几个重复的数字，也不知道重复了几次，请找出任意重复的数字。 例如，输入
长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出为[2,3]*/

#include <stdio.h>


int method_1(int data[],int length){
    printf("%d\n", length);
    return 0;
}


int main() {
    int numbers[3] = {1,2,3};
    int a[8];
    method_1(numbers,sizeof(a)/sizeof(a[0]));
    printf("开始\n");
    return 0;
}