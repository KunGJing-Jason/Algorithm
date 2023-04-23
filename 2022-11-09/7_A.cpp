#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin >> n){
        int a[n] = {0};
        int max = 0, temp = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            temp += a[i];
            if(temp < 0){
                temp = 0;
            }
            if(temp > max){
                max = temp;
            }
        }
        cout << max << endl;
    }

    return 0;
}