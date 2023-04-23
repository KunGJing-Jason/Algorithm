#include <iostream>
using namespace std;

#define M 10
#define N 10

int main(){
    int m,n;
    int dp[M][N];
    char X[M],Y[N];
    int i,j;

    cin >> m >> n;
    cout << "请输入两个序列长度" << endl;
    cout<<"请输入第一个序列" << endl;
    for(i = 1; i <= m; i++){
        cin >> X[i];
    }
    cout<<"请输入第二个序列" << endl;
    for(i = 1; i <= n; i++){
        cin >> Y[i];
    }

    for(i = 0; i <= n; i++)             //每行首元素置零
        dp[i][0] = 0;
    for(j = 0; j <= n; j++)
        dp[0][j] = 0;                   //每列首元素置零

    /// @brief 进行比较判断情况，对序列情况进行确立。1、若；两字符相等，则dp为上一个状态值+1，
    /// @return 2、若不相等，则取上一行和上一列中最大值
    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j++){
            if(X[i -1 ] == Y[j - 1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = dp[i][j - 1] > dp[i-1][j] ? dp[i][j - 1] : dp[i-1][j];
        }
    }

    /// @brief 输出结果
    /// @return 
    for(i = 0; i <= m; i++){
        for(j = 0; j <= n; j++){
            cout.width(2);
            cout<<dp[i][j];
        }
        cout << endl;
    }
    return 0;
}
