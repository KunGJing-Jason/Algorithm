#include <iostream>
using namespace std;
int main(){
    int q = 0;
    int n;
    while (cin >> n){
        q++;
        int k;
        cin >> k;
        int a[n], b[n], c[k][n];

        for (int i = 0; i < n; i++){
            cin >> a[i];
            if (i == 0){
                b[i] = a[i];
            }
            else{
                b[i] = b[i - 1] + a[i];
            }
            c[0][i] = b[i];
        }

        for (int i = 1; i < k; i++){

            for (int j = 0; j < n; j++){

                c[i][j] = 1 << 31 - 1;
                
                for (int l = 0; l < j; l++){

                    if (c[i][j] > max(c[i - 1][l], b[j] - b[l])){
                        c[i][j] = max(c[i - 1][l], b[j] - b[l]);
                    }
                }
            }
        }
        cout << "Case " << q << ":" << c[k - 1][n - 1] << endl;
    }
}