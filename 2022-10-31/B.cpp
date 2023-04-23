#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n = 0;
    while(cin >> n){
        int customer[n] = { 0 };
        int waittime[n] = { 0 };
        int sum = 0;
        for (int i = 0; i < n; i++){
            cin >> customer[i];
        }

        sort(customer, customer + n);
        for (int i = 0; i < n; i++){
            if( i == 0)
                waittime[0] = 0;
            waittime[i] = waittime[i-1]+customer[i];
        }

        for (int i = 0; i < n - 1; i++){
            sum += waittime[i];
        }
        
        
        cout << sum << endl;

    }
}
