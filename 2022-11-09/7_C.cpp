#include<iostream>
using namespace std;
const int N = 101;
int A[N];
int m[N][N];
int s[N][N];
void MatrixChain(int n)
{
	int r, i, j, k;
	for (i = 0; i <= n; i++)
	{
		m[i][i] = 0;
	}
	for (r = 2; r <= n; r++)
	{
		for (i = 1; i <= n - r + 1; i++)
		{
			j = i + r - 1;
			m[i][j] = m[i][i]+m[i + 1][j] + A[i - 1] * A[i] * A[j];
			s[i][j] = i;
			for (k = i + 1; k < j; k++)
			{
				int t = m[i][k] + m[k + 1][j] + A[i - 1] * A[k] * A[j];
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
}

int main()
{
	int n = 0; int count = 0;
    while(cin >> n){
        int i, j;
	    for (i = 0; i <= n; i++)
	    {
		    cin >> A[i];
	    }
	    MatrixChain(n);
	    cout << "Case " << ++count << endl;
        cout << m[1][n] << endl;
    }
	
	return 0;
}