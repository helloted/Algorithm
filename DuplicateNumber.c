
/* 
	在长度为n的数组中，所有的元素都是0到n-1的范围内。 数组中的某些数字是重复的，
	但不知道有几个重复的数字，也不知道重复了几次，请找出任意重复的数字。 例如，输入
	长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出为2或者3
*/

#include <stdio.h>
#include <stdlib.h>


/* 
	利用一个Hash表，已有的值在表中标记，重复的值就可以得到了
*/
int method_1(int data[],int length){
	int hashMap[length];
    for (int i = 0; i < length; ++i)
    {
    	hashMap[length] = 0;
    }

    for (int i = 0; i < length; ++i)
    {
    	int value = data[i];
    	if (hashMap[value] == 0){
    		hashMap[value] += 1;
    	}else{
    		return value;
    	}
    }
    return 0;
}



/* 
	快排之后，值与位置不对应的就是重复的
*/
int method_1(int data[],int length){

    return 0;
}


int main() {
    int numbers[7] = {2,3,1,0,2,5,3};
    int dul = method_1(numbers,7);
    printf("%d\n",dul);
    return 0;
}