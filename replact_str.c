
/*  请实现一个函数，把字符串中的每个空格替换成"%20"，例如“We are happy.”，则输出“We%20are%20happy” */

#include <stdio.h>
#include<string.h>

void replace(char *ori,char *des){
    int len = strlen(ori);
    int temp = 0;
    for (int i = 0; i < len; ++i)
    {
        if (ori[i] == ' ')
        {
            temp ++;
        }
    }
    printf("%d\n",len);
    char tar[len+temp*2+1];
    temp = 0;
    for (int i = 0; i < len; ++i)
    {
        if (ori[i] == ' '){
            tar[temp] = '%';
            tar[temp+1] = '2';
            tar[temp+2] = '0';
            temp += 3;
        }else{
            tar[temp] = ori[i];
            temp ++;
        }
    }
    tar[temp] = '\0';
    stpcpy(des,tar);
}


int main() {
    char *des;
    replace("We are happy.",des);
    printf("%s\n", des);
    return 0;
}