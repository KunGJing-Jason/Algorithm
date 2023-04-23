#include <stdio.h>
#include <string.h>
#define N 1005
const int inf = 0x3f3f3f3f;
int a[N][N];
int main()
{
    int n, m, i, j, ans;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        ans = 0;
        memset(a, inf, sizeof(a));
        while (m--)
        {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            a[x][y] = a[y][x] = z;
        }
        int d[N] = {0}, vis[N] = {0};
        memset(d, inf, sizeof(d));
        for (i = 1; i <= n; i++)
        {
            d[i] = a[1][i];
        }
        vis[1] = 1;
        int t = n - 1;
        while (t--)
        {
            int fi = -1, fa = inf;
            for (i = 1; i <= n; i++)
            {
                if (vis[i] == 0 && d[i] < fa)
                {
                    fa = d[i];
                    fi = i;
                }
            }
            if (fi == -1)
            {
                printf("-1");
                return 0;
            }
            ans += fa;
            vis[fi] = 1;
            for (i = 1; i <= n; i++)
            {
                if (vis[i] == 0 && d[i] > a[fi][i])
                {
                    d[i] = a[fi][i];
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}