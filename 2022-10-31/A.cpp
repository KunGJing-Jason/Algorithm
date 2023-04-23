#include<iostream>
using namespace std;


int main() {
    int t = 0;
    cin >> t;
    for(int i = 0; i < t ; i++){
        string a;
        int k;
        cin>> a >>k;
        int len=a.size(); 
        
        while(k--){
            for(int i=0;i<len;i++){
                if(a[i]>a[i+1]||i==len-1)
                {
                    a.erase(i,1);
                    break; 
                }
            }
        }
        
        while(a[0] == '0' && a[1] > 0)
            a.erase(0,1);

        cout<<a<<endl; 
    }
    return 0;
}