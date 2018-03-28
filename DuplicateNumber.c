
/* 
	在长度为n的数组中，所有的元素都是0到n-1的范围内。 数组中的某些数字是重复的，
	但不知道有几个重复的数字，也不知道重复了几次，请找出任意重复的数字。 例如，输入
	长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出为2或者3
*/

#include <stdio.h>
#include <stdlib.h>
void quick_sort(int s[],int l,int r);


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
int method_2(int data[],int length){
	quick_sort(data,0,6);
	for (int i = 0; i < length; ++i)
	{
		if (data[i] != i)
		{
			return data[i];
		}
	}
    return 0;
}


void quick_sort(int s[],int l,int r)
{
    if(l < r)
    {
        int i=l,j=r,x=s[l];
        while(i<j)
        {
            while(i<j && s[j]>=x)//从右到左找到第一个小于x的数  
                j--;
            if(i<j)
                s[i++]=s[j];
            
            while(i<j && s[i]<=x)//从左往右找到第一个大于x的数  
                i++;
            if(i<j)
                s[j--]=s[i]; 
            
        } 
        s[i]=x;//i = j的时候，将x填入中间位置  
        quick_sort(s,l,i-1);//递归调用 
        quick_sort(s,i+1,r);        
    }
}


int main() {
    int numbers[7] = {2,3,1,0,2,5,3};
    int dul =  method_2(numbers,7);
    printf("%d\n", dul);
    return 0;
}