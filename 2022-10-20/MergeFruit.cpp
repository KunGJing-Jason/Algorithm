#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int num = 0;
    while(cin >> num){
        int sum = 0;
        int a[num] = {0};
        int temp_a = 0;
        int temp_b = 0;

        queue<int>q;
        for (int i = 0; i < num; i++){
            cin >> a[i];
        }

        sort(a,a+num);

        for (int i = 0; i < num; i++){
           q.push(a[i]);
        }

        while(q.size() != 1){
            temp_a = q.front();q.pop();
            temp_b = q.front();q.pop();
            sum += (temp_a + temp_b);
            q.push(temp_a + temp_b);
        }

        cout << sum << endl;
        sum = 0;
        while(!q.empty())
            q.pop();
    }

    return 0;
}
