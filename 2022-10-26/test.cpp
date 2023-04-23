#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int k;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    cin >> k;
    for (int j = 0; j < k; j++)
    {
        cout << a[j];
    }
    return 0;
}