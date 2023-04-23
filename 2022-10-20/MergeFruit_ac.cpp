#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        priority_queue<int, vector<int>, greater<int> > pq;
        
        while(n--){
            int x;
            scanf("%d", &x);
            pq.push(x);
        }

        int res = 0;

        while(pq.size() > 1){
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            res += x + y;
            pq.push(x + y);
        }

    printf("%d\n", res);
    }
    
    return 0;

}

