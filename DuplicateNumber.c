
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


void quick(int data[],int l, int r){
    int i = l;
    int j = r;
    int temp = data[i]; //l位置也就是i位置挖空,数值作为分化的标记。i位置现在为空
    while(i< j){
        while(i<j && data[j] > temp){
            j--;
        }
        if (i<j)
        {
            data[i] = data[j]; //将j位置小于temp的值，填入上一个挖空的i位置，j位置现在为空。
            i++;
        }

        while(i<j && data[i] < temp){
            i ++;
        }
        if (i<j)
        {
            data[j] = data[i];
            j--;
        }
    }
    data[i] = temp;
    quick(data,l,i-1);
    quick(data,i+1,r);
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


/* 
以数组{2,3,1,0,2,5,3}为例来分析找到重复数字的步骤。
数组的第 0 个数字（从 0 开始计数，和数组的下标保持一致）是 2，
与它的下标不相等，于是把它和下标为 2 的数字 1 交换。
交换之后的数组是{1.3.2.0.2.5.3}。此时第 0 个数字是 1，
仍然与它的下标不相等，继续把它和下标为 1 的数字 3 交换，
得到数组{3,1,2,0,2,5,3}.接下来继续交换第 0 个数字 3 和第 3 个数字 0，
得到数组{0,1,2,3,2,5,3}。此时第 0 个数字的数值为 0，
接着扫描下一个数字。在接下来的几个数字中，
下标为 1，2，3 的三个数字分别为 1，2，3 它们的下标和数值都分别相等，
因此不需要做任何操作。接下来扫描到下标为 4 的数字 2。
由于它的数值与它的下标不相等，再比较它和下标为 2 的数字。
注意到此时数组中下标为 2 的数字也是 2，也就是数字在下标为 2 和下标为 4 的两个位置都出现了，
因此找到一个重复的数字。
*/
int method_3(int data[],int length){
    for (int i = 0; i < length; ++i)
    {
        while(data[i] != i){
            if (data[i] == data[data[i]])
            {
                return data[i];
            }else{
                int temp = data[i];
                data[i] = data[temp];
                data[temp] = temp;
            }
        }
    }
    return 0;
}


/* 
	快排的中心思想，是将数组切割为两个，左边小于，右边大于，然后再分别递归
*/
void quick_sort(int s[],int l,int r)
{
    if(l < r)
    {
        int i=l,j=r,x=s[l];
        while(i<j) //从i,j两边向中间靠拢，将小于的值放到左边，大于的值放到右边
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
        s[i]=x;	//i = j的时候，将x填入中间位置  
        quick_sort(s,l,i-1);	//递归调用 
        quick_sort(s,i+1,r);        
    }
}


int main() {
    int numbers[7] = {2,3,1,0,2,5,3};
    int dul =  method_3(numbers,7);
    printf("%d\n", dul);
    return 0;
}