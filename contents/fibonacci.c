
//*  Fibonacci数列矩阵的算法 */

#include <stdio.h>
#include<string.h>

typedef struct MTX{
    int m00;
    int m01;
    int m10;
    int m11;
}mtx;
mtx mtx0;


mtx m_multiply(mtx a, mtx b)
{
    mtx c;
    c.m00=a.m00*b.m00+a.m01*b.m10;
    c.m01=a.m00*b.m01+a.m01*b.m11;
    c.m10=a.m10*b.m00+a.m11*b.m10;
    c.m11=a.m10*b.m01+a.m11*b.m11;
    return c;
}

mtx m_power(int k)
{
    mtx m;

    if(1==k)
    {
        m=mtx0;
        return m;
    }
    else if(0==k%2)
    {
        m=m_multiply(m_power(k/2),m_power(k/2));
        return m;
    }
    else
    {
        m=m_multiply(m_power((k-1)/2),m_power((k-1)/2));
        m=m_multiply(m,mtx0);
        return m;
    }
}
int fibonacci(int n)
{
    int m;
    mtx mtx1;

    int t[2]={0, 1};
    if(n<3)
        return t[n];
    else
        mtx1=m_power(n-2);
    return mtx1.m00;
}

int main(void) {
    mtx0.m00 = 1;
    mtx0.m01 = 1;
    mtx0.m10 = 1;
    mtx0.m11 = 0;
    int n = 8;
    int m = fibonacci(n);
    printf("Fibonacci(%d)=%d", n, m);
    return 0;
}
