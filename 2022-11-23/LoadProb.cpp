# include<iostream>
using namespace std;
  
const int N = 30;
int n, c;
int w[N], x[N];
int r;
int cw;
int bestw;
int bestx[N];
  
void dfs(int t)
{
    if(t > n)
    { 
        if(cw > bestw)
        {
            for(int i = 1; i <= n; i++) 
                bestx[i] = x[i];
            bestw = cw;
        }
        return;
    }
    r -= w[t];
    if(cw + w[t] <= c)
    {
        x[t] = 1;
        cw += w[t];
        dfs(t + 1);
        cw -= w[t];
    }
    if(cw + r > bestw)
    {
        x[t] = 0;
        dfs(t + 1);
    }
    r += w[t];
}
  
int main()
{  
    while(cin >> n >> c)
    {
        r = 0;
        for(int i=1;i<=n;i++)
        {
            cin >> w[i];
            r += w[i];
        }
        cw = 0;
        bestw = 0;
        dfs(1);
        cout << bestw << endl;
    }
}