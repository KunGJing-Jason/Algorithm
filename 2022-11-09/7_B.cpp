#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    while(cin >> n){
        int result = (int)ceil(log((double)n)/log(3.0));
        cout << n << endl;
        cout <<"Times:"<< result << endl;
    }
    return 0;
}