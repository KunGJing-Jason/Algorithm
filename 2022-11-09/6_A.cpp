#include <iostream>
using namespace std;

int n, a[1005], dp[1005], x = -9999;
int main(){
    while (cin >> n){
        dp[1] = 1;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
            dp[i] = 1;
        }
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j < i; ++j){
                if (a[i] > a[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        for (int i = 1; i <= n; ++i){
            if (x < dp[i])
                x = dp[i];
        }

        cout << x << endl;
    }
    return 0;
}