#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, k;
    while (cin >> n >> k){
        int *a = new int [n];

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a,a+n);
        for(int i = 0; i < k; i++){
            cout << a[i] <<" ";
        }
        cout << endl;
        delete(a);
    }
    
    return 0;
}