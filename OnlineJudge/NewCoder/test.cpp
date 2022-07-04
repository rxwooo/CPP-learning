#include <stdio.h>
#include <math.h>
int main()
{
    int num, i, A1 = 0, A2 = 0, s = 0, A3 = 0, A5 = 0;
    double count = 0, sum = 0, A4;
    char ch1, ch2, ch3, ch4, ch5;

    scanf("%d", &num);
    int a[num];
    for (i = 0; i < num; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < num; i++)
    {
        if (a[i] % 5 == 0 && a[i] % 2 == 0)
        {
            A1 = A1 + a[i];
        }
    }
    if (A1 == 0)
    {
        ch1 = 'N';
        printf("%c ", ch1);
    }
    else
    {
        printf("%d ", A1);
    }
    for (i = 0; i < num; i++)
    {
        if (a[i] % 5 == 1)
        {
            A2 = A2 + pow(-1, s) * a[i];
            s = s + 1;
        }
    }
    if (A2 == 0)
    {
        ch2 = 'N';
        printf("%c ", ch2);
    }
    else
    {
        printf("%d ", A2);
    }
    for (i = 0; i < num; i++)
    {
        if (a[i] % 5 == 2)
        {
            A3 = A3 + 1;
        }
    }
    if (A3 == 0)
    {
        ch3 = 'N';
        printf("%c ", ch3);
    }
    else
    {
        printf("%d ", A3);
    }
    for (i = 0; i < num; i++)
    {
        if (a[i] % 5 == 3)
        {
            sum = sum + a[i];
            count = count + 1;
        }
    }
    A4 = sum / count;
    if (count == 0)
    {
        ch4 = 'N';
        printf("%c ", ch4);
    }
    else
    {
        printf("%.1f ", A4);
    }
    for (i = 0; i < num; i++)
    {
        if (a[i] % 5 == 4)
        {
            A5 = (A5 > a[i]) ? A5 : a[i];
        }
    }
    if (A5 == 0)
    {
        ch5 = 'N';
        printf("%c", ch5);
    }
    else
    {
        printf("%d", A5);
    }
    return 0;
}