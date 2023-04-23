#include <iostream>
using namespace std;
#define MAX 100
int main(){
    int n = 5, m = 10, r = 10, maxWeight = 0;               //创建 物品数量，背包重量，当前剩余重量，最大重量
    int W[] = {0, 2, 2, 6, 5, 4};
    int V[] = {0, 6, 3, 5, 4, 6};
    int dp[MAX][MAX], tag[6] = {0};                         //创建动态规划数组和物品选中情况

    for (int  i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;                               //0行0列为空，即0不用
            }
            else if(j < W[i]){
                dp[i][j] = dp[i - 1][j];                    //若背包空间有，则放入物品
            }
            else{
                dp[i][j] = dp[i-1][j] >= (dp[i-1][j - W[i]]+V[i]) ? dp[i-1][j] : (dp[i-1][j - W[i]]+V[i]);  //物品重量比较，取大
            }
        }
    }
    
    for(int i = 1; i <= n; i++){                        /// @brief 输出背包所有情况
        for(int j = 1; j <= m; j++){
            cout.width(3);
            cout << dp[i][j];
        }
        cout << endl;
    }

    for(int i = n; i >= 0; i--){                         /// @brief 选择背包中的物品
        if(dp[i][r] != dp[i - 1][r]){
            tag[i] = 1;
            r -= W[i];
            maxWeight += W[i];
        }
    }
    
    for(int i = 1; i <= n; i++){                        /// @brief 输出背包物品选中情况 
        cout.width(3);
        cout << tag[i];
    }
    cout << endl;
    cout.width(3);
    cout << maxWeight<<endl;
    cout.width(3);
    cout << dp[5][10];      //输出最大价值
    
    return 0;
}


