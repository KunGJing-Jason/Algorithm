#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n-- > 0)
    {
        string s1;
        string s2;
        cin >> s1 >> s2;
        
        int i = 0, j = 0;
        while (i < s1.length() && j < s2.length())
        {
            cout << s1[i];
            cout << s2[j];
            i++;
            j++;
        }
        while (i < s1.length())
        {
            cout << s1[i];
            i++;
        }
        while (j < s2.length())
        {
            cout << s2[j];
            j++;
        }
        cout << endl;
    }

    return 0;
}