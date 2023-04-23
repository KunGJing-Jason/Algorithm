#include <iostream>
#include <math.h>
using namespace std;

long long divide_conquer(long long X, long long Y, int digit)
{
    long long A, B, C, D, AC, BD, ABCD;
    if (X == 0 || Y == 0)
    {
        return 0;
    }
    else if (digit == 1)
    {
        return X * Y;
    }
    else
    {
        A = X / pow(10, digit / 2);
        B = X % (int)pow(10, digit / 2);
        C = Y / pow(10, digit / 2);
        D = Y % (int)pow(10, digit / 2);
        AC = divide_conquer(A, C, digit / 2);
        BD = divide_conquer(B, D, digit / 2);
        ABCD = divide_conquer((A - B), (D - C), digit / 2) + AC + BD;
        // 如果是位数是偶数，公式为：XY = AC*10的n次方 +（（A-B）（D-C）+AC+BD）*10的n/2次方 + BD
        // 如果是位数是奇数，公式为：XY = AC*10的（n-1）次方 +（（A-B）（D-C）+AC+BD）*10的n/2次方 + BD
        if (digit % 2 == 0)
        {
            return AC * pow(10, digit) + ABCD * pow(10, digit / 2) + BD;
        }
        else
        {
            return AC * pow(10, digit - 1) + ABCD * pow(10, digit / 2) + BD;
        }
    }
}

int main()
{
    long long x, y, product;
    int digit;
    cin >> digit;
    cin >> x >> y;
    product = divide_conquer(x, y, digit);
    cout << product << endl;
}
