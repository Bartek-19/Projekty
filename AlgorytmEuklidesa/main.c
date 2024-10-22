#include <stdio.h>
#include <stdlib.h>

void NWD(int a, int b, int *x)
{
    int r;

    printf("\n a\tb\ta mod b\n");

    while (b != 0)
    {
        r = a%b;
        printf(" %d\t%d\t%d\n", a, b, r);
        a = b;
        b = r;
        *x += 1;
    }

    printf(" %d\t%d\n", a, b);

    printf("\nNajwiekszy wspolny dzielnik: %d\n\n", a);
}

void RozAlgorytm(int x, int y, int n)
{
    int a[n];
    int q[n];
    int s[n];
    int t[n];

    a[0] = x; a[1] = y;
    s[0] = 1; s[1] = 0;
    t[0] = 0; t[1] = 1;
    q[0] = 0;

    int i = 0;

    printf("Wzory:\n");
    printf(" q[i] = a[i-1] div a[i]\n");
    printf(" a[i+1] = a[i-1] - (q[i] * a[i])\n");
    printf(" s[i+1] = s[i-1] - (q[i] * s[i])\n");
    printf(" t[i+1] = t[i-1] - (q[i] * t[i])\n");
    printf(" a[i] = x * s[i] + y * t[i]\n\n\n");

    printf(" i:\t a[i]:\t q[i]:\t s[i]:\t t[i]:\n");
    printf(" %d\t %d\t  \t %d\t %d\n", i, a[i], s[i], t[i]);
    i++;

    while (a[i] != 0)
    {
        q[i] = (int) a[i-1]/a[i];
        a[i+1] = a[i-1] - q[i] * a[i];
        s[i+1] = s[i-1] - q[i] * s[i];
        t[i+1] = t[i-1] - q[i] * t[i];
        printf(" %d\t %d\t %d\t %d\t %d\n", i, a[i], q[i], s[i], t[i]);
        i++;
    }

    printf(" %d\t %d\n\n", i, a[i]);
}

int main()
{
    int x, y, temp;
    int n = 1;

    printf("ALGORYTM EUKLIDESA\n\n");

    printf("Podaj x i y:\n");
    scanf("%d%d", &x, &y);
    if (x < y)
    {
        temp = x;
        x = y;
        y = temp;
    }

    NWD(x, y, &n);

    printf("ROZSZERZONY ALGORYTM EUKLIDESA\n\n");

    RozAlgorytm(x, y, n);

    system("PAUSE");
    return 0;
}
